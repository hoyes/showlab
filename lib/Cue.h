#ifndef CUE_H
#define CUE_H

#include <string>

class Cue
{
private:
    std::string mNumber;
    std::string mName;

public:
    std::string Number() { return mNumber; }
    void Number(std::string v) { mNumber = v; }
    
    std::string Name() { return mName; }
    void Name(std::string v) { mName = v; }
};

#endif
