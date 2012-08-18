#ifndef SHOW_STORAGE_H
#define SHOW_STORAGE_H

#include <string>
#include "StoreItem.h"
#include <boost/filesystem.hpp>

namespace showlab {
namespace showstore {

class ShowStorage
{
public:
    std::string GetStoragePath();
    void LoadStoreItems(StoreItemList& itemlist);
    ConfigNode CreateNodeFromFile(std::string filename);
    StoreItemRef CreateStoreItem(boost::filesystem::path itempath);
};

}}

#endif
