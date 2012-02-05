#ifndef WAV_AUDIO_FILE_H
#define WAV_AUDIO_FILE_H

#include "AudioFile.h"
#include <sndfile.h>

class WavAudioFile : public AudioFile
{

public:
        virtual ~WavAudioFile();
        virtual void doLoad();
        virtual void doUnload();
        virtual void fillBuffer();

private:
        SNDFILE* handler;

};


#endif
