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
            if (obj) itemlist[obj->Id()] = obj;
        }
    }
}

StoreItemRef ShowStorage::CreateStoreItem(path itempath)
{
    std::string id = itempath.filename().native();
    if (!ItemId::isValidId(id)) return NULL;

    path props_path = itempath;    
    if (is_directory(itempath)) props_path /= "props";
    ConfigNodeRef n = CreateNodeFromFile(props_path.native());
    std::string type = *n->node("type");
    
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

ConfigNodeRef ShowStorage::CreateNodeFromFile(std::string filename)
{
    YAML::Node doc = YAML::LoadFile(filename);
    
    std::cout << filename << std::endl;
    ConfigNodeRef config = ParseNode(doc);
    return config;
}

ConfigNodeRef ShowStorage::ParseNode(YAML::Node y_node)
{
    switch (y_node.Type()) {
        case YAML::NodeType::Scalar: {
            bool bool_val;
            int int_val;
            std::string str_val;
            float fl_val;
            if (YAML::convert<bool>::decode(y_node, bool_val)) {
                return ConfigNodeRef(new ValueConfigNode(bool_val));
            }
            else if (YAML::convert<float>::decode(y_node, fl_val)) {
                return ConfigNodeRef(new ValueConfigNode(fl_val));
            }
            else if (YAML::convert<int>::decode(y_node, int_val)) {
                return ConfigNodeRef(new ValueConfigNode(int_val));
            }
            else if (YAML::convert<std::string>::decode(y_node, str_val)) {
                if (ItemId::isValidId(str_val)) {
                    return ConfigNodeRef(new RefConfigNode(ItemId(str_val)));
                }
                else return ConfigNodeRef(new ValueConfigNode(str_val));
            }
            break;
        }
        case YAML::NodeType::Sequence: {
            std::shared_ptr<ListConfigNode> c_node(new ListConfigNode);
            for(YAML::const_iterator it=y_node.begin(); it!=y_node.end(); ++it) {
                c_node->add(ParseNode((YAML::Node)*it));
            }
            return c_node;
            break;
        }
        case YAML::NodeType::Map: {
            std::shared_ptr<MapConfigNode> c_node(new MapConfigNode);
            for(YAML::const_iterator it=y_node.begin(); it!=y_node.end(); ++it) {
                c_node->add(it->first.as<std::string>(), ParseNode(it->second));
            }
            return c_node;
            break;
        }
        case YAML::NodeType::Null:
        case YAML::NodeType::Undefined:
            return ConfigNodeRef(new BaseConfigNode);
            break;
    }
    return ConfigNodeRef(new BaseConfigNode);    
}

}}
