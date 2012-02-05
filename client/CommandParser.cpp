#include "CommandParser.h"
#include <boost/algorithm/string.hpp>
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
                        words.erase(words.begin(), words.begin() + 1);
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
        d.name
        mClient->getInterface().addCue(
        return "added!";
}
