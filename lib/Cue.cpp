#include "Cue.h"
#include <sstream>

Cue::Cue() : mNumber(0), mName(""), uid(boost::uuids::random_generator()()) {}

Cue::Cue(double number, std::string name) 
 : mNumber(number), mName(name), uid(boost::uuids::random_generator()())
{
}

std::string Cue::convertUidToString(CueUid uid)
{
    std::stringstream ss;
    ss << uid;
    return ss.str();
}

CueUid Cue::convertStringToUid(std::string uid)
{
    CueUid id;
    std::stringstream ss(uid);
    ss >> id;
    return id;
}

void Cue::fire()
{
    for (auto it = mActions.begin(); it != mActions.end(); it++) {
        (*it)->fire();
    }
}
