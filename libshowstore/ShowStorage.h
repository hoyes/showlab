#ifndef SHOW_STORAGE_H
#define SHOW_STORAGE_H

#include <string>
#include "StoreItem.h"
#include <boost/filesystem.hpp>
#include <yaml-cpp/yaml.h>

namespace showlab {
namespace showstore {

class ShowStorage
{
public:
    std::string GetStoragePath();
    void LoadStoreItems(StoreItemList& itemlist);
    ConfigNodeRef CreateNodeFromFile(std::string filename);
    StoreItemRef CreateStoreItem(boost::filesystem::path itempath);
    ConfigNodeRef ParseNode(YAML::Node y_node);
};

}}

#endif
