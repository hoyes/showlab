#ifndef SHOW_H
#define SHOW_H

#include <string>
#include <deque>
#include <map>
#include "Cue.h"

typedef std::list<CueRef> CueList;
typedef std::map<CueUid, CueList::iterator> CueUidMap;
typedef std::map<float, CueList::iterator> CueNumMap;

class Show 
{
private:
    std::string mName;
    CueList cues;
    CueUidMap cue_uid_lookup;
    CueNumMap cue_num_lookup;
    
    CueList::iterator next;

public:
    Show();
    std::string Name() { return mName; }
    void Name(std::string v) { mName = v; }
    
    CueRef cue(CueUid uid);
    CueRef cue(float num);
    CueUid addCueWithNumber(const double number, const std::string name);
    CueUid addCueAtLocation(const int location, const std::string name);
    CueUid addCue(CueRef c, CueList::iterator position);
    const CueList::iterator cuesBegin() { return cues.begin(); };
    const CueList::iterator cuesEnd() { return cues.end(); };
    
    double suggestCueNumber(CueList::iterator position);
    int findPosition(double number);
    
    void reset();
    void go();
    void standby(float num);
    void standby(CueUid uid);
};

#endif
