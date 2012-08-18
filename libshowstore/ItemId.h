#ifndef ITEM_ID_H
#define ITEM_ID_H

#include <boost/uuid/uuid_generators.hpp>
#include <string>

namespace showlab {
namespace showstore {

class ItemId
{
private:
    boost::uuids::uuid mId;
public:
    ItemId();
    ItemId(const ItemId& id) { mId = id.uuid(); }
    ItemId(std::string str_id);
    
    ItemId operator=(const ItemId id) { return ItemId(id); }
    bool operator==(const ItemId id) const { return id.uuid() == mId; }
    bool operator<(const ItemId id) const { return id.uuid() < mId; }
    bool operator>(const ItemId id) const { return id.uuid() > mId; }
    
    const boost::uuids::uuid uuid() const { return mId; }
    
    std::string str();
    
    static bool isValidId(std::string id);
};

}}

#endif
