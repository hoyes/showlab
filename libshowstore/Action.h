#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <memory>
#include <list>
#include "StoreItem.h"

namespace showlab {
namespace showstore {

class Action;

class Action : public StoreItem
{
private:
    
public:
    Action(ItemId id, ConfigNode config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_ACTION; }
};

typedef std::shared_ptr<Action> ActionRef;
typedef std::list<ActionRef> ActionRefList;


}}
#endif
