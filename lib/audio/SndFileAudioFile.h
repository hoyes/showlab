#ifndef SNDFILE_AUDIO_FILE_H
#define SNDFILE_AUDIO_FILE_H

#include "AudioFile.h"
#include <sndfile.h>

class SndFileAudioFile : public AudioFile
{

public:
        virtual ~SndFileAudioFile();
        virtual void doLoad();
        virtual void doUnload();
        virtual void addToBuffer(SampleList samples, unsigned int number);

private:
        SNDFILE* handler;

};


#endif
