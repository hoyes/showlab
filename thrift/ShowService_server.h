#ifndef SHOW_SERVICE_SERVER_H
#define SHOW_SERVICE_SERVER_H

#include "ShowService.h"
#include <protocol/TBinaryProtocol.h>
#include <server/TSimpleServer.h>
#include <transport/TServerSocket.h>
#include <transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

class ShowServiceHandler : virtual public ShowServiceIf {
 public:
  ShowServiceHandler();

  void addCue(const CueData& data, const int32_t location);
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
public:
    void start();
    ShowLabServer();
};

#endif
