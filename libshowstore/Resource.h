#ifndef RESOURCE_H
#define RESOURCE_H

#include "StoreItem.h"
#include <memory>

namespace showlab {
namespace showstore {

class Resource : public StoreItem
{
private:


public:
    Resource(ItemId id, ConfigNode config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_RESOURCE; }
    
    
};

typedef std::shared_ptr<Resource> ResourceRef;

}}

#endif
