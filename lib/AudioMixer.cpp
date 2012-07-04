#include "AudioMixer.h"
#include <iostream>
#include <exception>
#include <chrono>

AudioMixer::AudioMixer(int id) : mId (id), running(false)
{
        start();
}

AudioMixer::~AudioMixer()
{
        stop();
}


void AudioMixer::start()
{
        if (running) return;
        
        running = true;
        
        const PaDeviceInfo *deviceInfo = Pa_GetDeviceInfo(mId);
        mChannels = deviceInfo->maxOutputChannels;

        mSampleRate = deviceInfo->defaultSampleRate;
        
        {
                std::lock_guard<std::mutex> lk(mut_buffer);
                buffer.set_capacity(mSampleRate * mChannels / 4);        
        }
        th = std::thread(&AudioMixer::diskThread, (void*) this);

        PaStreamParameters params; 
        
        params.channelCount = mChannels;
        params.hostApiSpecificStreamInfo = NULL;
        params.device = mId;
        params.sampleFormat = paFloat32;
        params.suggestedLatency = deviceInfo->defaultLowOutputLatency;

        int err = Pa_OpenStream(
                    &stream,
                    NULL,
                    &params,
                    mSampleRate,
                    paFramesPerBufferUnspecified,
                    paNoFlag, 
                    &AudioMixer::audioCallback,
                    (void *)this );
        if (err != paNoError) {
                std::cout << Pa_GetErrorText(err) << std::endl;
        }
        Pa_StartStream(stream);
}

void AudioMixer::stop()
{
        mut_running.lock();
        if (running == false) return;
        running = false;
        mut_running.unlock();
        th.join();
        Pa_StopStream(stream);
        Pa_CloseStream(stream);
}

int AudioMixer::audioCallback(const void *input, void *output, unsigned long frameCount, 
                const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData)
{
        AudioMixer* m = (AudioMixer*) userData;
                        
        float *out = (float*)output;
        unsigned int i;
        (void) input; /* Prevent unused variable warning. */
        
        std::lock_guard<std::mutex> lk(m->mut_buffer);
        unsigned int count = frameCount*m->mChannels;
        
        unsigned int max_data = count;
        if (count > m->buffer.size()) max_data = m->buffer.size();
        for(i=0; i<max_data; i++) {
                *out++ = m->buffer.front();
                m->buffer.pop_front();
        }
        for (i=max_data; i < count; i++) {
                *out++ = 0.0;
        }
        return 0;
}

void AudioMixer::diskThread(void* ptr)
{
        AudioMixer* m = (AudioMixer*) ptr;
        std::unique_lock<std::mutex> lk(m->mut_running, std::defer_lock);
        while(m->running) {
                std::this_thread::sleep_for(std::chrono::milliseconds(20));
                lk.lock();
                int num;
                {
                    std::lock_guard<std::mutex> lk(m->mut_buffer);
                    num = m->buffer.reserve();
                }
                if (num > 0) {
                    std::vector<float> totals;
                    totals.assign(num, 0);
                    int numframes = 0;
                    for (auto i = m->audioFiles.begin(); i != m->audioFiles.end(); ++i) {
                       int error;
                       SRC_STATE* src_state = src_new(SRC_SINC_BEST_QUALITY, (*i)->Channels(), &error);
                       SRC_DATA data;
                       double ratio = m->mSampleRate / (*i)->SampleRate();
                       (*i)->fillBuffer();
                       unsigned int fnum = num / m->mChannels * (*i)->Channels();
                       auto samples = (*i)->getSamples(fnum * ratio);

                       std::vector<float> vals;
                       vals.assign(fnum, 0);
                       
                       data.data_in = samples->data();
                       data.data_out = vals.data();
                       data.input_frames = samples->size() /  (*i)->Channels();
                       data.output_frames = vals.size() /  (*i)->Channels();
                       data.end_of_input = 0;
                       data.src_ratio = ratio;
                       
                       if (ratio == 1.0) {
                          data.data_out = samples->data();
                          data.output_frames_gen = data.input_frames;
                          data.input_frames_used = data.input_frames;
                       }
                       else int res = src_process(src_state, &data);
                       //Add resampled values to totals
                       
                       numframes = data.output_frames_gen * m->mChannels;

                       for (int j = 0; j < data.output_frames_gen * (*i)->Channels(); ++j) {
                           int index = ((int)j / (*i)->Channels()) * m->mChannels + (j % (*i)->Channels());
                           totals[index] += samples->at(j);
                       }
                       (*i)->clearSamples(data.input_frames_used * (*i)->Channels());
                       src_delete(src_state);
                       
                       if (samples->size() < fnum) {
                                //We've reached the end of the file so delete it from mixer
                                i = m->audioFiles.erase(i) - 1;
                       }
                    }
                    {
                        std::lock_guard<std::mutex> lk(m->mut_buffer);
                        for (int i = 0; i < numframes; ++i) {
                            m->buffer.push_back(totals[i]);
                        }
                    }
                }
                lk.unlock();
        }
}

void AudioMixer::addFile(AudioFileRef file)
{
        if (file->SampleRate() < 1000 || file->SampleRate() > 200000) return;

        audioFiles.push_back(file);
}
