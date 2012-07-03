#include "Show.h"
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <iostream>

Show::Show() : mName("")
{

}
    
int Show::addCueWithNumber(const double number, const std::string name)
{
        Cue c(number, name);
        return addCue(c, -1);
}

int Show::addCueAtLocation(const int location, const std::string name)
{
        Cue c(location, name);
        return addCue(c , -1);
}

int Show::addCue(Cue& c, int position)
{
        if (c.Number() <= 0) c.Number(suggestCueNumber(position));

        if (position == -1) {
                cues.push_back(c);
                return cues.size() - 1;
        }
        else {
                cues.insert(cues.begin() + position, c);
                return position;
        }
}

double Show::suggestCueNumber(int position)
{
        if (position == -1) {
            if (cues.size() == 0) return 1.0;
            position = cues.size();
        }
        
        double lower = -1, upper = -1, current;
        
        //Find previous cue that has numerical cue number
        unsigned int i;
        if (position > 0) {
                for (i = position - 1; i >= 0; --i) {
                        std::cout << i << std::endl;
                    lower = cues[i].Number();
                    break;
                }
        }

        //Find next cue that has numerical cue number
        for (i = position; i < cues.size(); ++i) {
            upper = cues[i].Number();
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
