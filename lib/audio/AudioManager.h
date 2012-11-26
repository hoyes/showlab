#ifndef AUDIO_MANAGER_H
#define AUDIO_MANAGER_H

#include <vector>
#include "AudioMixer.h"
#include <memory>

struct Device {
        std::string name;
        int channels;
        int id;
        int sampleRate;
        int latency;
        bool isDefault;
};

class AudioManager 
{

private:

        typedef std::vector<std::shared_ptr<AudioMixer>> MixerList;
        MixerList mixers;
        
public:
        typedef std::vector<Device> DeviceList;
        
        AudioManager();
        ~AudioManager();
        
        DeviceList getDeviceList();
        int getDeviceCount();
        Device getDeviceByName(std::string name);
        
        AudioMixerRef addMixer(std::string name);
        AudioMixerRef getMixer(int index);
        unsigned int getMixerCount();

};

typedef std::shared_ptr<AudioManager> AudioManagerRef;

#endif
