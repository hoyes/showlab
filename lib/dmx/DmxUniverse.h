#ifndef DMX_UNIVERSE_H
#define DMX_UNIVERSE_H

#include <vector>

typedef unsigned char DmxValue;
typedef std::vector<DmxValue> DmxValues;

class DmxUniverse
{
private:
    DmxValues mValues;
    
public:
    DmxValue GetDmxAt(int i) { return mValues[i]; }
    void SetDmxAt(int i, int val) { mValues[i] = val; }

};

#endif
