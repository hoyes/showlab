#ifndef MIDI_COMMAND_H
#define MIDI_COMMAND_H

#include <vector>

typedef std::vector<unsigned char> MidiHexString;

class MidiCommand
{
public:
    enum Type {
        TYPE_NOTE_ON,
        TYPE_NOTE_OFF,
        TYPE_CONTROL_CHANGE,
        TYPE_PROGRAM_CHANGE,
        TYPE_PITCH_WHEEL,
        TYPE_CHANNEL_PRESSURE,
        TYPE_POLYPHONIC_KEY_PRESSURE,
        TYPE_MIDI_SHOW_CONTROL,
        TYPE_SYSTEM_EXCLUSIVE,
        TYPE_INVALID
    };

private:
    MidiHexString mData;

public:
    int GetLength() { return mData.size(); }
    unsigned char GetData(int i) { return mData[i]; }

    Type GetType();
};

#endif
