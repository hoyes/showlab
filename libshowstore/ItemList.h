#ifndef ITEM_LIST_H
#define ITEM_LIST_H

#include "ItemId.h"
#include <map>

namespace showlab {
namespace showstore {

template<typename T>
class ItemList
{
public:
    typedef std::map<ItemId, T> list_type;
    typedef typename list_type::iterator iterator;
private:
    list_type mChildren;
public:
    iterator begin() { return mChildren.begin(); }
    iterator end() { return mChildren.end(); }
    unsigned int size() { return mChildren.size(); }
    T& get(ItemId id) { return mChildren[id]; }
    
    T& operator[](ItemId id) { return get(id); }
    
    void clear() { mChildren.clear(); }
};

}}

#endif
