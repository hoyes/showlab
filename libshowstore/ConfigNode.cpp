#include "ConfigNode.h"

namespace showlab {
namespace showstore {

ConfigNode& ConfigNode::GetNode(std::string key, bool create) 
{
    return mChildren[key]; 
}

}}
