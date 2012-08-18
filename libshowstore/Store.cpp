#include "Store.h"
#include "ShowStorage.h"

namespace showlab {
namespace showstore {

Store::Store()
{
    mStorage.LoadStoreItems(mItems);
}

}}
