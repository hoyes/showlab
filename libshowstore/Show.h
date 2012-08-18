#ifndef SHOW_H
#define SHOW_H

#include <map>
#include "StoreItem.h"
#include "Action.h"
#include "CueStack.h"
#include "ExecutorDef.h"
#include "ItemList.h"
#include "Resource.h"

namespace showlab {
namespace showstore {

typedef ItemList<ActionRef> ActionList;
typedef ItemList<CueStackRef> CueStackList;
typedef ItemList<ExecutorDefRef> ExecutorDefList;
typedef ItemList<ResourceRef> ResourceList;

class Show : public StoreItem
{
private:
    ActionList mActions;
    CueStackList mCueStacks;
    ExecutorDefList mExecutorDefs;
    ResourceList mResources;

public:
    Show(ItemId id, ConfigNode config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_SHOW; }
    
    virtual void AddChild(StoreItemRef item);
    
    ActionList& actions() { return mActions; }
    CueStackList& cueStacks() { return mCueStacks; }
    ExecutorDefList& executorDefs() { return mExecutorDefs; }
    ResourceList& resources() { return mResources; }
    
};

typedef std::shared_ptr<Show> ShowRef;

}}

#endif
