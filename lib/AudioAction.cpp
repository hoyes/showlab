#include "AudioAction.h"

AudioAction::AudioAction(std::string name, std::string filename)
    : Action(name), mFileName(filename)
{
    load();
}

void AudioAction::load()
{
    mAudioFile = AudioFileRef(new AudioFile);
    mAudioFile->open(FileName());
}
