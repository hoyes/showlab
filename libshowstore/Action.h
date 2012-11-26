#ifndef ACTION_H
#define ACTION_H

#include <string>
#include <memory>
#include <list>
#include "StoreItem.h"

namespace showlab {
namespace showstore {

class Action : public StoreItem
{
private:
    
public:
    Action(ItemId id, ConfigNodeRef config) : StoreItem(id, config) {};
    
    virtual ItemType Type() { return TYPE_ACTION; }
    
    std::string Class() { return *config()->node("class"); }
    
    std::string subClass() { return *config()->node("subclass"); }
};

typedef std::shared_ptr<Action> ActionRef;
typedef std::list<ActionRef> ActionRefList;


}}
#endif
