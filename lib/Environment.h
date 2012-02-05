#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Show.h"
#include "AudioManager.h"

class Environment
{
private:
    Show s;
    AudioManager am;
    
public:
    Show& getShow() { return s; }
    AudioManager& getAudioManager() { return am; }
};

#endif
