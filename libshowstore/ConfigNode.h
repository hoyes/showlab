#ifndef CONFIG_NODE_H
#define CONFIG_NODE_H

#include <map>
#include <vector>
#include <memory>
#include <boost/lexical_cast.hpp>
#include <boost/any.hpp>

namespace showlab {
namespace showstore {

enum ConfigNodeType {
    TYPE_NULL,
    TYPE_MAP,
    TYPE_LIST,
    TYPE_SCALAR,
    TYPE_REF,
};

class BaseConfigNode;
typedef std::shared_ptr<BaseConfigNode> ConfigNodeRef;

class BaseConfigNode
{
private:
    boost::any mValue;
public:
    virtual ConfigNodeRef node(std::string key) { return ConfigNodeRef(new BaseConfigNode); };
    virtual ConfigNodeRef node(int id) { return ConfigNodeRef(new BaseConfigNode); }
    virtual boost::any value() { return 0; }
    virtual void value(boost::any val) { }
    virtual ConfigNodeType type() { return TYPE_NULL; };
    virtual unsigned int size() { return 0; }
    
    ConfigNodeRef operator[] (std::string key) { return node(key); }
    ConfigNodeRef operator[] (int id) { return node(id); }
    
    virtual operator std::string () { return ""; }
    virtual operator int () { return 0; }
    virtual operator float () { return 0.0; }
     
};

class ListConfigNode : public BaseConfigNode
{
private:
    std::vector<ConfigNodeRef> mChildren;
public:
    virtual ConfigNodeRef node(int id) { return mChildren[id]; }
    virtual ConfigNodeType type() { return TYPE_LIST; }
    virtual unsigned int size() { return mChildren.size(); }
    void add(ConfigNodeRef child) {
        mChildren.push_back(child);
    }
    std::vector<ConfigNodeRef>::iterator begin() { return mChildren.begin(); }
    std::vector<ConfigNodeRef>::iterator end() { return mChildren.end(); }
};

typedef std::shared_ptr<ListConfigNode> ListConfigNodeRef;

class MapConfigNode : public BaseConfigNode
{
private:
    std::map<std::string, ConfigNodeRef> mChildren;
public:
    virtual ConfigNodeType type() { return TYPE_MAP; }
    virtual ConfigNodeRef node(std::string key) { return mChildren[key]; };
    virtual unsigned int size() { return mChildren.size(); }
    void add(std::string key, ConfigNodeRef child) {
        mChildren[key] = child;
    }
    std::map<std::string, ConfigNodeRef>::iterator begin() { return mChildren.begin(); }
    std::map<std::string, ConfigNodeRef>::iterator end() { return mChildren.end(); }
};

typedef std::shared_ptr<MapConfigNode> MapConfigNodeRef;

class ValueConfigNode : public BaseConfigNode {
private:
    boost::any mValue;
public:
    ValueConfigNode(boost::any value) : mValue(value) {};
    virtual ConfigNodeType type() { return TYPE_SCALAR; }
    
    virtual operator std::string () { return boost::any_cast<std::string>(mValue); }
    virtual operator int () { return 0; }
    virtual operator float () { return 0.0; }
    
    virtual boost::any value() { return mValue; }
    virtual void value(boost::any val) { mValue = val; }
    virtual unsigned int size() { return 1; }
    bool is_int() { return mValue.type() == typeid(int); }
    bool is_string() { return mValue.type() == typeid(std::string); }
    bool is_float() { return mValue.type() == typeid(float); }
};

}}

#endif
