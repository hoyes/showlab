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
    int addCue(const std::string number, const std::string name, const int position);
    int addCue(Cue& c, int);
    const CueList::iterator& cuesBegin() { return cues.begin(); };
    const CueList::iterator& cuesEnd() { return cues.end(); };
    
    std::string suggestCueNumber(int position);
};

#endif
