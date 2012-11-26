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
    int addCueWithNumber(const double number, const std::string name);
    int addCueAtLocation(const int location, const std::string name);
    int addCue(Cue& c, int position);
    const CueList::iterator cuesBegin() { return cues.begin(); };
    const CueList::iterator cuesEnd() { return cues.end(); };
    
    double suggestCueNumber(int position);
    int findPosition(double number);
};

#endif
