#include "ShowStorage.h"
#include "StoreItem.h"
#include "Show.h"
#include "Action.h"
#include "ExecutorDef.h"
#include "CueStack.h"
#include "Resource.h"

#include <boost/filesystem.hpp>
#include <fstream>
#include <iostream>
#include <yaml-cpp/yaml.h>

#ifdef WIN32

#else
    #include <pwd.h>
#endif

using namespace boost::filesystem;

namespace showlab {
namespace showstore {

std::string ShowStorage::GetStoragePath()
{
    std::string dir;
    #ifdef WIN32
    
    #else
    struct passwd *pw = getpwuid(getuid());
    dir = std::string(pw->pw_dir) + "/.config/showlab";
    #endif
    
    create_directories(dir);
    return dir;
}

void ShowStorage::LoadStoreItems(StoreItemList& itemlist)
{
    itemlist.clear();

    path p(GetStoragePath());
    if (!is_directory(p)) return;
    
    for (auto it = directory_iterator(p); it != directory_iterator(); ++it) {
        path item = *it;
        if (is_directory(item)) {
            StoreItemRef obj = CreateStoreItem(item);
            itemlist[obj->Id()] = obj;
        }
    }
}

StoreItemRef ShowStorage::CreateStoreItem(path itempath)
{
    std::string id = itempath.filename().native();
    if (id.size() != 36) return NULL;

    path props_path = itempath;    
    if (is_directory(itempath)) props_path /= "props";
    ConfigNode n = CreateNodeFromFile(props_path.native());
    std::string type = n.GetNode("type").GetValue();
    
    ItemId item_id = ItemId(id);
    
    StoreItemRef item;
    
    if (type == "show") {
        item = StoreItemRef(new Show(item_id, n));
    }
    else if (type == "action") {
        item = StoreItemRef(new Action(item_id, n));        
    }
    else if (type == "cuestack") {
        item = StoreItemRef(new CueStack(item_id, n));
    }
    else if (type == "executor") {
        item = StoreItemRef(new ExecutorDef(item_id, n));
    }
    else if (type == "resource") {
        item = StoreItemRef(new Resource(item_id, n));
    }    
    else {
        item = StoreItemRef(new StoreItem(item_id, n));
    }

    path obj_path = itempath / "objs";
    if (is_directory(obj_path)) {
        for (auto it = directory_iterator(obj_path); it != directory_iterator(); ++it) {
            StoreItemRef subitem = CreateStoreItem(*it);
            if (subitem) item->AddChild(subitem);
        }
    }
    return item;
}

ConfigNode ShowStorage::CreateNodeFromFile(std::string filename)
{
    YAML::Node doc = YAML::LoadFile(filename);
    ConfigNode config;
    
    for(YAML::const_iterator it=doc.begin(); it!=doc.end(); ++it) {
        config.GetNode(it->first.as<std::string>()).SetValue(it->second.as<std::string>());
    }
    return config;
}

}}
