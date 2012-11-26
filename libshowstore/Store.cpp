#include "Store.h"
#include "ShowStorage.h"

namespace showlab {
namespace showstore {

Store::Store()
{
    mStorage.LoadStoreItems(mItems);
    for (auto it = mItems.begin(); it != mItems.end(); ++it) {
        it->second->resolveRefs();
    }
}

}}
