#ifndef AUDIO_MIXER_H
#define AUDIO_MIXER_H

#include <portaudio.h>
#include <samplerate.h>
#include <boost/circular_buffer.hpp>
#include <string>
#include <memory>
#include "AudioFile.h"
#include <thread>

typedef boost::circular_buffer<float> FrameBuffer;

class AudioMixer {
	
private:
        int mId, mSampleRate, mChannels;
        PaStream *stream;
        std::vector<std::shared_ptr<AudioFile>> audioFiles;
        boost::circular_buffer<float> buffer;


        bool running;
        std::mutex mut_running;
        std::mutex mut_buffer;
        std::thread th;

public:
        AudioMixer(int id);
        ~AudioMixer();
        
        void start();
        void stop();
        int Id() { return mId; }
        void addFile(AudioFileRef file);
        
        static int audioCallback(const void *input, void *output, unsigned long frameCount, 
            const PaStreamCallbackTimeInfo *timeInfo, PaStreamCallbackFlags statusFlags, void *userData);
        
        static void diskThread(void* ptr);
	
};

typedef std::shared_ptr<AudioMixer> AudioMixerRef;

#endif
