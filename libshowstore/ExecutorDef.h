#ifndef EXECUTOR_DEF_H
#define EXECUTOR_DEF_H

#include "StoreItem.h"

namespace showlab {
namespace showstore {

class ExecutorDef : public StoreItem
{
private:

public:
    ExecutorDef(ItemId id, ConfigNodeRef config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_EXECUTOR_DEF; }
};

typedef std::shared_ptr<ExecutorDef> ExecutorDefRef;

}}

#endif
