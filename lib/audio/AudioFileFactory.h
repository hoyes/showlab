#ifndef AUDIO_FILE_FACTORY_H
#define AUDIO_FILE_FACTORY_H

#include "AudioFile.h"
#include <string>

class AudioFileFactory
{

public:
    static AudioFileRef create(std::string filename);

};

#endif
