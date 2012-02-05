#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <deque>
#include "Cue.h"

typedef std::deque<Cue> CueList;

class Show 
{
private:
    std::string mName;
    CueList cues;

public:
    Show();
    std::string Name() { return mName; }
    void Name(std::string v) { mName = v; }
    
    Cue& cue(int i) { return cues[i]; }
};

#endif
