#include "WavAudioFile.h"

void WavAudioFile::doLoad()
{
        SF_INFO info;
        handler = sf_open(FileName().c_str(), SFM_READ, &info);
        Frames(info.frames);
        SampleRate(info.samplerate);
        Channels(info.channels);
}

void WavAudioFile::doUnload()
{
        sf_close(handler);
}

WavAudioFile::~WavAudioFile()
{
        try {
               unload();
        }
        catch(...) {}
}

void WavAudioFile::fillBuffer()
{
        load();
        int num = buffer.reserve();
        float new_data[num];
        int num_fetched = sf_read_float(handler, new_data, num);
        for (int i=0; i<num_fetched; ++i) {
                buffer.push_back(new_data[i]);
        }
}
