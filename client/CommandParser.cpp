#include "CommandParser.h"
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>

CommandParser::CommandParser()
{
        mClient = std::shared_ptr<ShowService_client>(new ShowService_client);
        mClient->start();
}

std::string CommandParser::parse(const std::string& input)
{
        std::vector<std::string> words;
        boost::split(words, input, boost::is_any_of(" "));
        
        if (words.size() >= 2 && (words[1] == "cues" || words[1] == "cue")) {
                if (words[0] == "list") return cmdList();
                else if (words[0] == "add") {
                        words.erase(words.begin(), words.begin() + 2);
                        std::string rest = boost::join(words, " ");
                        return cmdAdd(rest);
                }
        }
        return "unrecognised command";
}

std::string CommandParser::cmdList()
{
        std::vector<CueData> cues;
        mClient->getInterface().getCues(cues);
        return "ls!!!";
}

std::string CommandParser::cmdAdd(const std::string& input)
{

        CueData d;
        uint start = input.find_first_of("\"");
        uint end = input.find_last_of("\"");
        uint pos = -1;
        
        if (start < end) {
                d.name = input.substr(start + 1, end - start - 2);
        }
        else {
                d.name = "";        
        }
        
        if (start > 0) {
                d.number = input.substr(0, start - 1);
        }
        else {
                d.number = "";
        }
        
        if (end < input.size() - 1) {
                try {
                        pos = boost::lexical_cast<int>(input.substr(end+1, input.size()-1));
                }
                catch (boost::bad_lexical_cast&) {}
        }
        
        int id = mClient->getInterface().addCue(d, pos);
        mClient->getInterface().getCue(d, id);
        return "Added cue " + d.number + " : " + d.name;
}
