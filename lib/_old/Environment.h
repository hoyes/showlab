#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Show.h"
#include "audio/AudioManager.h"
#include <memory>

class Environment
{
private:
    Show s;
    AudioManager am;
    
public:
    Show& getShow() { return s; }
    AudioManager& getAudioManager() { return am; }
};

typedef std::shared_ptr<Environment> EnvironmentRef;

#endif
