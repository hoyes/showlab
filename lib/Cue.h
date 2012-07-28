#ifndef CUE_H
#define CUE_H

#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <memory>
#include <list>
#include "Action.h"

typedef boost::uuids::uuid CueUid;
typedef std::list<ActionRef> ActionList;

class Cue
{
private:
    double mNumber;
    std::string mName;
    int mOrder;
    
    CueUid uid;
    ActionList mActions;

public:
    Cue();
    Cue(double number, std::string name);

    double Number() { return mNumber; }
    void Number(double v) { mNumber = v; }
    
    std::string Name() { return mName; }
    void Name(std::string v) { mName = v; }
    
    int Order() { return mOrder; }
    void Order(int v) { mOrder = v; }
    
    static std::string convertUidToString(CueUid uid);
    static CueUid convertStringToUid(std::string uid);
    CueUid Uid() { return uid; }
    
    void addAction(ActionRef a) { mActions.push_back(a); }
    
    void fire();
};

typedef std::shared_ptr<Cue> CueRef;

#endif
