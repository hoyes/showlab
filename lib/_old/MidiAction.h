#ifndef AUDIO_ACTION_H
#define AUDIO_ACTION_H

#include "Action.h"

class MidiAction : public Action
{
private:
    int mMidiDevice;
    MidiCommand mCommand;
    
public:
    AudioAction(EnvironmentRef e, std::string name = "", std::string filename = "");
    
    
    
    virtual void doFire();
    void load();
};

#endif
