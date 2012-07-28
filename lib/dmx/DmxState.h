#ifndef DMX_STATE_H
#define DMX_STATE_H

#include "DmxUniverse.h"

class DmxState
{
private:
    std::vector<DmxUniverse> mUniverses;
    
public:
    DmxUniverse& GetUniverse(int i) { return mUniverses[i]; }
    int GetUniverseCount() { return mUniverses.size(); }
    void SetDmxValue(int universe, int channel, DmxValue value);
};

#endif
