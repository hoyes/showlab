#ifndef DIMMER_FIXTURE_H
#define DIMMER_FIXTURE_H

#include "Fixture.h"

class DimmerFixture : public Fixture {
private:
    DmxValue mIntensity;
public:
    DmxValue GetIntensity() { return mIntensity; }
    void SetIntensity(DmxValue val) { mIntensity = val; }
    
    virtual void SetDmxData(DmxState& state);
};

#endif
