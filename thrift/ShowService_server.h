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

  void addCueWithNumber(std::string& _return, const double number, const std::string& name);
  void addCueAtLocation(std::string& _return, const std::string& location, const std::string& name);
  void getCues(std::vector<CueData> & _return);
  void getCue(CueData& _return, const std::string& id);
  void deleteCue(const int32_t id);
  void changeNumber(const int32_t id, const double number);
  void changeName(const int32_t id, const std::string& name);
  void newShow();
  
  void addAudioActionById(const std::string& cueid, const std::string& filename);
  void addAudioActionByNumber(const int32_t num, const std::string& filename);
  
  void go();
  void reset();
  void standbyUid(const std::string& id);

  void standbyNum(const double number);

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
