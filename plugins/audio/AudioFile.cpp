#include "AudioFile.h"

AudioFile::AudioFile() : mFileName(""), mFrames(0), mPosition(0), mChannels(0), mSampleRate(0), loaded(false)
{
}

void AudioFile::open(std::string fileName)
{
        mFileName = fileName;
        load();
}

void AudioFile::load() {
        if (!loaded) {
                doLoad();
                loaded = true;
        }
}

void AudioFile::unload() {
        if (loaded) {
                doUnload();
                loaded = false;
        }
}

AudioFile::~AudioFile()
{
        try {
              unload();
        }
        catch (...) {}
}

SampleList AudioFile::getSamples(int number)
{
    auto samples = SampleList(new std::vector<float>); 
    addToBuffer(samples, number);
    return samples;
}

void AudioFile::clearSamples(int number)
{
}
