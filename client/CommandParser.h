#ifndef COMMAND_PARSER_H
#define COMMAND_PARSER_H

#include <string>
#include "../thrift/ShowService_client.h"
#include <memory>

class CommandParser
{
private:
        std::shared_ptr<ShowService_client> mClient;

public:
        CommandParser();
        std::string parse(const std::string& command);

        std::string cmdList();
        std::string cmdAdd(const std::string& command);
};

#endif
