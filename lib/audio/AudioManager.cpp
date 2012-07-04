#include "AudioManager.h"

AudioManager::AudioManager()
{
        Pa_Initialize();
}

AudioManager::~AudioManager()
{
        for (auto i = mixers.begin(); i != mixers.end(); ++i) {
                (*i)->stop();
        }
        Pa_Terminate();
}

AudioManager::DeviceList AudioManager::getDeviceList()
{
        AudioManager::DeviceList list;
        int i, num = getDeviceCount();
        int def = Pa_GetDefaultOutputDevice();
        const PaDeviceInfo *deviceInfo;
        
        for(i=0; i<num; i++) {
                deviceInfo = Pa_GetDeviceInfo(i);
                if (deviceInfo->maxOutputChannels > 0) {
                        Device d;
                        d.name = deviceInfo->name;
                        d.latency = deviceInfo->defaultLowOutputLatency;
                        d.sampleRate = deviceInfo->defaultSampleRate;
                        d.channels = deviceInfo->maxOutputChannels;
                        d.id = i;
                        d.isDefault = (i == def);
                        list.push_back(d);
                }
        }
        return list;
}

int AudioManager::getDeviceCount()
{
        return Pa_GetDeviceCount();
}

Device AudioManager::getDeviceByName(std::string name)
{
        int i, num = getDeviceCount();
        const PaDeviceInfo *deviceInfo;
        Device d;
        d.id = -1;
        
        for(i=0; i<num; i++) {
                deviceInfo = Pa_GetDeviceInfo(i);
                if (deviceInfo->name == name) {
         
                        d.name = deviceInfo->name;
                        d.latency = deviceInfo->defaultLowOutputLatency;
                        d.sampleRate = deviceInfo->defaultSampleRate;
                        d.channels = deviceInfo->maxOutputChannels;
                        d.id = i;
                        d.isDefault = (i == Pa_GetDefaultOutputDevice());
               }
        }
        return d;
}

AudioMixerRef AudioManager::addMixer(std::string name)
{
        Device d = getDeviceByName(name);
        AudioMixerRef m(new AudioMixer(d.id));
        mixers.push_back(m);
        return m;
}
