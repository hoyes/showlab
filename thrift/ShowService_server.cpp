#include "ShowService_server.h"

ShowServiceHandler::ShowServiceHandler() 
{

}

void ShowServiceHandler::addCue(const CueData& data, const int32_t location) {
    // Your implementation goes here
    printf("addCue\n");
}

  void ShowServiceHandler::getCues(std::vector<CueData> & _return) {
    // Your implementation goes here
    printf("getCues\n");
  }

  void ShowServiceHandler::getCue(CueData& _return, const int32_t id) {
    // Your implementation goes here
    printf("getCue\n");
  }

  void ShowServiceHandler::deleteCue(const int32_t id) {
    // Your implementation goes here
    printf("deleteCue\n");
  }

  void ShowServiceHandler::changeNumber(const int32_t id, const std::string& number) {
    // Your implementation goes here
    printf("changeNumber\n");
  }

  void ShowServiceHandler::changeName(const int32_t id, const std::string& name) {
    // Your implementation goes here
    printf("changeName\n");
  }


ShowLabServer::ShowLabServer()
{

}

void ShowLabServer::start() {
  int port = 9155;
  shared_ptr<ShowServiceHandler> handler(new ShowServiceHandler());
  shared_ptr<TProcessor> processor(new ShowServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  mServer = shared_ptr<TSimpleServer>(new TSimpleServer(processor, serverTransport, transportFactory, protocolFactory));
  mServer->serve();
}

