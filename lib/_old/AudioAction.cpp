#include "AudioAction.h"
#include "audio/AudioFileFactory.h"

AudioAction::AudioAction(AudioManager& man, std::string name, std::string filename)
    : Action(name), mFileName(filename), mAudioMan(man)
{
    load();
}

void AudioAction::load()
{
    mAudioFile = AudioFileFactory::create(FileName());
}

void AudioAction::doFire()
{
    mAudioMan.getMixer(0)->addFile(mAudioFile);
}
