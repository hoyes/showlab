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
    ConfigNodeRef mConfig;
    StoreItemList mChildren;
    
protected:
    ConfigNodeRef config() { return mConfig; }
    
public:
    StoreItem(ItemId id, ConfigNodeRef config) : mId(id), mConfig(config) {};

    std::string Name() { return *config()->node("name"); }
    void Name(std::string v) { config()->node("name")->value(v); }
    
    ItemId Id() { return mId; }
    void Id(ItemId id) { mId = id; }
    
    virtual ItemType Type() { return TYPE_UNKNOWN; }
    
    virtual void AddChild(StoreItemRef item) { mChildren[item->Id()] = item; }
    StoreItemList& items() { return mChildren; }
    
    ConfigNodeRef operator[] (std::string key) { return mConfig->node(key); }
    
    void resolveRefs();
    void resolveRefsFromItem(StoreItem* item, ConfigNodeRef config);
    
};


class RefConfigNode : public BaseConfigNode {
private:
    ItemId mId;
    StoreItemRef mRef;
    bool mResolved;
public:
    RefConfigNode(ItemId id) : mId(id), mResolved(false) {};
    RefConfigNode(StoreItemRef ref) : mId(ref->Id()), mRef(ref), mResolved(true) {};
    virtual ConfigNodeType type() { return TYPE_REF; }
    virtual operator std::string () { return mId.str(); }
    operator StoreItemRef () { return mRef; }
    operator ItemId () { return mId; }
    
    bool resolved() { return mResolved; }
    ItemId id() { return mId; }
    StoreItemRef ref() { return mRef; }
    
    void resolve(StoreItemRef ref) { if (!mResolved) mRef =  ref; }
};

typedef std::shared_ptr<RefConfigNode> RefConfigNodeRef;

}}

#endif
