#ifndef STORE_ITEM_H
#define STORE_ITEM_H

#include "ItemId.h"

#include <string>
#include <list>
#include <memory>
#include "ConfigNode.h"
#include "ItemList.h"

namespace showlab {
namespace showstore {

class StoreItem;
typedef std::shared_ptr<StoreItem> StoreItemRef;
typedef ItemList<StoreItemRef> StoreItemList;

enum ItemType  {
    TYPE_SHOW,
    TYPE_CUE_STACK,
    TYPE_ACTION,
    TYPE_EXECUTOR_DEF,
    TYPE_RESOURCE,
    TYPE_UNKNOWN,
};

class StoreItem
{
private:
    ItemId mId;
    ConfigNode mConfig;
    StoreItemList mChildren;
    
protected:
    ConfigNode& GetConfig() { return mConfig; }
    
public:
    StoreItem(ItemId id, ConfigNode config) : mId(id), mConfig(config) {};

    std::string Name() { return GetConfig().GetNode("name").GetValue(); }
    void Name(std::string v) { GetConfig().GetNode("name").SetValue(v); }
    
    ItemId Id() { return mId; }
    void Id(ItemId id) { mId = id; }
    
    virtual ItemType Type() { return TYPE_UNKNOWN; }
    
    virtual void AddChild(StoreItemRef item) { mChildren[item->Id()] = item; }
    StoreItemList& items() { return mChildren; }
    
    ConfigNode& operator[] (std::string key) { return mConfig.GetNode(key); }
    
};

}}

#endif
