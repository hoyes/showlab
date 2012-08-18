#ifndef STORE_PATH_H
#define STORE_PATH_H

#include <vector>
#include <string>
#include "ItemId.h"

namespace showlab {
namespace showstore {

class StorePathPart
{
public:
    enum PartType {
        TYPE_ID,
        TYPE_KEY,
    };
    virtual PartType Type() = 0;
};

class IdPathPart : public StorePathPart
{
private:
    ItemId mId;
public:
    IdPathPart(ItemId id) { mId = id; }
    virtual PartType Type() { return TYPE_ID; }
    ItemId Get() { return mId; }
};

class KeyPathPart : public StorePathPart
{
private:
    std::string mKey;
public:
    KeyPathPart(std::string key) { mKey = key; }
    virtual PartType Type() { return TYPE_KEY; }
    std::string Get() { return mKey; }
};

class StorePath
{
private:
    std::vector<StorePathPart*> mParts;
    
public:
    StorePath(std::string path);
    ~StorePath();
};

}}

#endif
