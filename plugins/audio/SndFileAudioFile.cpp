#include "SndFileAudioFile.h"

void SndFileAudioFile::doLoad()
{
        SF_INFO info;
        handler = sf_open(FileName().c_str(), SFM_READ, &info);
        Frames(info.frames);
        SampleRate(info.samplerate);
        Channels(info.channels);
}

void SndFileAudioFile::doUnload()
{
        sf_close(handler);
}

SndFileAudioFile::~SndFileAudioFile()
{
        try {
               unload();
        }
        catch(...) {}
}

void SndFileAudioFile::addToBuffer(SampleList samples, unsigned int num)
{
        load();
        float new_data[num];
        int num_fetched = sf_read_float(handler, new_data, num);
        for (int i=0; i<num_fetched; ++i) {
                samples->push_back(new_data[i]);
        }
}
