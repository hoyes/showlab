#ifndef MIDI_ENGINE_H
#define MIDI_ENGINE_H

#include <list>
#include "MidiDevice.h"

typedef std::list<MidiDevice> MidiDeviceList;

class MidiEngine
{
private:
    MidiDeviceList mDevices;
};

#endif
