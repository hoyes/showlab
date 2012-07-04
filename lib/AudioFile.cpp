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
                buffer.set_capacity(SampleRate() * Channels() / 10);
                loaded = true;
        }
}

void AudioFile::unload() {
        if (loaded) {
                doUnload();
                buffer.resize(0);
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
    int count = 0;
    auto samples = SampleList(new std::vector<float>); 
    for (auto i = buffer.begin(); i != buffer.end() && count < number; ++i) {
        samples->push_back(*i);
        ++count;
    }
    return samples;
}

void AudioFile::clearSamples(int number)
{
    buffer.erase(buffer.begin(), buffer.begin() + number);
}
