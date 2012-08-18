#ifndef CONFIG_NODE_H
#define CONFIG_NODE_H

#include <map>
#include <boost/lexical_cast.hpp>

namespace showlab {
namespace showstore {

class ConfigNode
{
private:
    std::map<std::string, ConfigNode> mChildren;
    std::string mValue;
public:
    ConfigNode& GetNode(std::string key, bool create = false);
    void AddNode(std::string key) {
        mChildren[key] = ConfigNode();
    }
    
    std::string GetValue() { return mValue; }
    int GetIntValue() { return boost::lexical_cast<int>(mValue); }
    float GetFloatValue() { return boost::lexical_cast<float>(mValue); }
    
    void SetValue(std::string val) { mValue = val; }
    void SetValue(int val) { mValue = boost::lexical_cast<std::string>(val); }
    void SetValue(float val) { mValue = boost::lexical_cast<std::string>(val); }
};

}}

#endif
