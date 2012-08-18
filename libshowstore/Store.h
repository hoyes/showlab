#ifndef STORE_H
#define STORE_H

#include "StoreItem.h"
#include "ShowStorage.h"

namespace showlab {
namespace showstore {

class Store
{
private:
    StoreItemList mItems;
    ShowStorage mStorage;

public:
    Store();
    
    StoreItemList& items() { return mItems; }
};

}}

#endif
