#ifndef CUE_STACK_H
#define CUE_STACK_H

#include "StoreItem.h"
#include <memory>

namespace showlab {
namespace showstore {

class CueStack : public StoreItem
{
private:


public:
    CueStack(ItemId id, ConfigNodeRef config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_CUE_STACK; }
    
};

typedef std::shared_ptr<CueStack> CueStackRef;

}}

#endif
