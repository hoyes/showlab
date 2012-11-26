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
    Resource(ItemId id, ConfigNodeRef config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_RESOURCE; }
    
    std::string fileName() { return *config()->node("filename"); }
    std::string extension() { return *config()->node("extension"); }
    std::string mime() { return *config()->node("mime"); }
    int size() { return *config()->node("size"); }
    
};

typedef std::shared_ptr<Resource> ResourceRef;

}}

#endif
