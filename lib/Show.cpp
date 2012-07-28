#include "Show.h"
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <iostream>

Show::Show() : mName("")
{
        next = cues.end();
}
    
CueUid Show::addCueWithNumber(const double number, const std::string name)
{
        CueRef c = CueRef(new Cue(number, name));
        return addCue(c, cues.end());
}

CueUid Show::addCueAtLocation(const int location, const std::string name)
{
        CueRef c = CueRef(new Cue(location, name));
        return addCue(c , cues.end());
}

CueUid Show::addCue(CueRef c, CueList::iterator position)
{
        if (c->Number() <= 0) c->Number(suggestCueNumber(position));

        if (position == cues.end()) {
                auto new_it = cues.insert(position, c);
                cue_uid_lookup[c->Uid()] = new_it;
                cue_num_lookup[c->Number()] = new_it;
        }
        else {
                //cues.insert(cues.begin() + position, c);
        }
        if (cues.size() == 1) reset();
        return c->Uid();
}

CueRef Show::cue(CueUid uid)
{
    return *(cue_uid_lookup[uid]);
}

CueRef Show::cue(float num)
{
    return *(cue_num_lookup[num]);
}

double Show::suggestCueNumber(CueList::iterator position)
{
        if (position == cues.end()) {
            if (cues.size() == 0) return 1.0;
        }
        
        double lower = -1, upper = -1, current;
        
        //Find previous cue that has numerical cue number
        CueList::iterator it = position;
        it--;
        if (position != cues.begin()) {
                do {
                    lower = (*it)->Number();
                    break;
                    it--;
                } while (it != cues.begin());
        }

        //Find next cue that has numerical cue number
        for (it = position; it != cues.end(); ++it) {
            upper = (*it)->Number();
            break;
        }

        if (upper == -1) return floor(lower + 1);
        if (upper < lower) return 0;

        current = (lower + upper) / 2;

        int exp = (int) log10(upper - lower);
        float bound = floor(current * pow(10,-exp)) * pow(10,exp);
        if (bound > lower) return bound;
        bound = ceil(current * pow(10,-exp)) * pow(10,exp);
        if (bound < upper) return bound;
        
        return current;
}

int Show::findPosition(double number)
{
        /*int pos = 0;
        for (int i =  position; i < cues.size(); ++i) {
            if (number > 
        }*/
        return 0;
}

void Show::reset()
{
    if (cues.size() > 0) next = cues.begin();
}

void Show::go()
{
    if (next != cues.end()) {
        (*next)->fire();
        next++;
    }
}

void Show::standby(float num)
{
        next = cue_num_lookup[num];
}

void Show::standby(CueUid uid)
{
        next = cue_uid_lookup[uid];
}
