#include "AudioAction.h"
#include "AudioFileFactory.h"

AudioAction::AudioAction(std::string name, std::string filename)
    : Action(name), mFileName(filename)
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
