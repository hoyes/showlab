#include "AudioAction.h"
#include "audio/AudioFileFactory.h"

AudioAction::AudioAction(EnvironmentRef e, std::string name, std::string filename)
    : Action(e, name), mFileName(filename)
{
    load();
}

void AudioAction::load()
{
    mAudioFile = AudioFileFactory::create(FileName());
}

void AudioAction::doFire()
{

}
