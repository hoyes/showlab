#include "MidiCommand.h"

MidiCommand::Type MidiCommand::GetType()
{
    if (GetLength() < 2) {
        return TYPE_INVALID;
    }

    unsigned char cmd = (GetData(0) & 0xF0) >> 4;    
    if (GetLength() == 3) {
        switch (cmd) {
            case 0x9: return TYPE_NOTE_ON;
            case 0x8: return TYPE_NOTE_OFF;
            case 0xB: return TYPE_CONTROL_CHANGE;
        }
    }
    else if (GetLength() == 2) {
        switch (cmd) {
            case 0xA: return TYPE_PROGRAM_CHANGE;
        }
    }
    return TYPE_INVALID;
}
