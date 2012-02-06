#include "Show.h"
#include <boost/lexical_cast.hpp>
#include <cmath>
#include <iostream>

Show::Show() : mName("")
{

}

int Show::addCue(const std::string number, const std::string name, const int position = -1)
{
        Cue c(number, name);
        return addCue(c, position);
}

int Show::addCue(Cue& c, int position = -1)
{
        if (c.Number() == "") c.Number(suggestCueNumber(position));

        if (position == -1) {
                cues.push_back(c);
                return cues.size() - 1;
        }
        else {
                cues.insert(cues.begin() + position, c);
                return position;
        }
}

std::string Show::suggestCueNumber(int position)
{
        if (position == -1) position = cues.size();
        
        float lower = -1, upper = -1, current;
        
        //Find previous cue that has numerical cue number
        int i = position - 1;
                
        while (i > 0) {
                try {
                        lower = boost::lexical_cast<float>(cues[i].Number());
                        break;
                }
                catch (boost::bad_lexical_cast&) {
                }
        }
        
        //Find next cue that has numerical cue number
        i = position;
        while (i < cues.size()) {
                try {
                        upper = boost::lexical_cast<float>(cues[i].Number());
                        break;
                }
                catch (boost::bad_lexical_cast&) {
                }
        }
        
        if (lower == -1 && upper == -1) return "1";

                       std::cout << upper << " " << lower << std::endl; 
        if (upper == -1) return boost::lexical_cast<std::string>(floor(lower + 1));
        if (upper < lower) return "";

        current = (lower + upper) / 2;

        int exp = (int) log10(upper - lower);
        float bound = floor(current * pow(10,-exp)) * pow(10,exp);
        if (bound > lower) return boost::lexical_cast<std::string>(bound);
        bound = ceil(current * pow(10,-exp)) * pow(10,exp);
        if (bound < upper) return boost::lexical_cast<std::string>(bound);
        
        return boost::lexical_cast<std::string>(current);
}
