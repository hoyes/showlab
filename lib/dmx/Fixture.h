#ifndef FIXTURE_H
#define FIXTURE_H

#include "DmxState.h"

class Fixture {
private:
    int mUniverse;
    int mStartChannel;
    int mNumber;
public:
    int GetStartChannel() { return mStartChannel; }
    void SetStartChannel(int val) { mStartChannel = val; }
    
    int GetUniverse() { return mUniverse; }
    void SetUniverse(int val) { mUniverse = val; }
    
    int GetNumber() { return mNumber; }
    void SetNumber(int val) { mNumber = val; }
    
    virtual void SetDmxData(DmxState& state) = 0;
};

#endif
