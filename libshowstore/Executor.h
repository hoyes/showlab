#ifndef EXECUTOR_H
#define EXECUTOR_H

#include <string>
#include "Action.h"
#include "ConfigNode.h"

namespace showlab {

using namespace showlab::showstore;

class Executor {
private:
    std::string mClass;
public:
    Executor(std::string class_name) : mClass(class_name) {};
    virtual void setup(ConfigNodeRef config) = 0;
    void fire(ActionRef action);
    virtual void doFire() = 0;
};

}

#endif
