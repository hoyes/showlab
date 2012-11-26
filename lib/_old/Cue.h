#ifndef CUE_H
#define CUE_H

#include <string>

class Cue
{
private:
    double mNumber;
    std::string mName;

public:
    Cue();
    Cue(double number, std::string name);

    double Number() { return mNumber; }
    void Number(double v) { mNumber = v; }
    
    std::string Name() { return mName; }
    void Name(std::string v) { mName = v; }
};

#endif
