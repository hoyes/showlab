#include "DmxState.h"

void DmxState::SetDmxValue(int universe, int channel, DmxValue value)
{
    if (universe >= GetUniverseCount()) {
        mUniverses[universe] = DmxUniverse();
    }
    GetUniverse(universe).SetDmxAt(channel, value);
}
