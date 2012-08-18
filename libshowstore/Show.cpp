#include "Show.h"
#include <memory>

namespace showlab {
namespace showstore {

void Show::AddChild(StoreItemRef item)
{
    switch (item->Type()) {
        case TYPE_ACTION:
            mActions[item->Id()] = std::static_pointer_cast<Action>(item);
            break;
        case TYPE_CUE_STACK:
            mCueStacks[item->Id()] = std::static_pointer_cast<CueStack>(item);
            break;
        case TYPE_EXECUTOR_DEF:
            mExecutorDefs[item->Id()] = std::static_pointer_cast<ExecutorDef>(item);
            break;
        case TYPE_RESOURCE:
            mResources[item->Id()] = std::static_pointer_cast<Resource>(item);
            break;
        case TYPE_SHOW:
        case TYPE_UNKNOWN:
            break;
    }
    StoreItem::AddChild(item);
}

}}
