#ifndef MODIFICATION_H
#define MODIFICATION_H

#include "StorePath.h"

namespace showlab {
namespace showstore {

class Modification
{
public:
    enum ModificationType {
        TYPE_ADDITION
        TYPE_REMOVAL
        TYPE_MODIFICATION
        TYPE_INIT
    };
    
private:
    ConfigNode mConfig;
    ModificationType mType;
    StorePath mPath;
    
public:
    Modification();
    
    ModificationType Type() { return mType; }
};

}}

#endif
