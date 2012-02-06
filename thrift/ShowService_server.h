#ifndef SHOW_SERVICE_SERVER_H
#define SHOW_SERVICE_SERVER_H

#include "ShowService.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>
#include "../lib/Environment.h"

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class ShowServiceHandler : virtual public ShowServiceIf {
private:
  std::shared_ptr<Environment> env;
  
 public:
  ShowServiceHandler(std::shared_ptr<Environment> e);

  int32_t addCue(const CueData& data, const int32_t location);
  void getCues(std::vector<CueData> & _return);
  void getCue(CueData& _return, const int32_t id);
  void deleteCue(const int32_t id);
  void changeNumber(const int32_t id, const std::string& number);
  void changeName(const int32_t id, const std::string& name);

};

class ShowLabServer
{
private:
        shared_ptr<TSimpleServer> mServer;
        std::shared_ptr<Environment> env;
public:
    void start();
    ShowLabServer(std::shared_ptr<Environment> e);
};

#endif
