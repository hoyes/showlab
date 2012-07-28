#ifndef AUDIO_ACTION_H
#define AUDIO_ACTION_H

#include "Action.h"
#include "audio/AudioFile.h"
#include "audio/AudioLevels.h"
#include "audio/AudioManager.h"

class AudioAction : public Action
{
private:
    std::string mFileName;
    AudioFileRef mAudioFile;
    AudioLevels levels;
    
    AudioManager mAudioMan;
    
public:
    AudioAction(AudioManager& man, std::string name = "", std::string filename = "");
    
    std::string FileName() { return mFileName; }
    void FileName(std::string v) { mFileName = v; }
    
    virtual void doFire();
    void load();
};

#endif
