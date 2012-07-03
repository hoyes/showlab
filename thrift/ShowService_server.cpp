#include "ShowService_server.h"

ShowServiceHandler::ShowServiceHandler(std::shared_ptr<Environment> e) : env(e)
{

}

int32_t ShowServiceHandler::addCueWithNumber(const double number, const std::string& name) {
   printf("addCueWithNumber\n");
   return env->getShow().addCueWithNumber(number, name);
}

int32_t ShowServiceHandler::addCueAtLocation(const int32_t location, const std::string& name) {
   printf("addCueAtLocation\n");
   return env->getShow().addCueAtLocation(location, name);
}

  void ShowServiceHandler::getCues(std::vector<CueData> & _return) {
    // Your implementation goes here
    printf("getCues\n");
    
    std::vector<CueData> cues;
    for (auto i = env->getShow().cuesBegin(); i != env->getShow().cuesEnd(); ++i) {
        CueData d;
        d.number = i->Number();
        d.name = i->Name();
        cues.push_back(d);
    }
    _return = cues;
  }

  void ShowServiceHandler::getCue(CueData& _return, const int32_t id) {
    // Your implementation goes here
    printf("getCue\n");
    Cue c = env->getShow().cue(id);
    CueData d;
    d.name = c.Name();
    d.number = c.Number();
    _return = d;
  }

  void ShowServiceHandler::deleteCue(const int32_t id) {
    // Your implementation goes here
    printf("deleteCue\n");
  }

  void ShowServiceHandler::changeNumber(const int32_t id, const double number) {
    // Your implementation goes here
    printf("changeNumber\n");
  }

  void ShowServiceHandler::changeName(const int32_t id, const std::string& name) {
    // Your implementation goes here
    printf("changeName\n");
  }
  
  void ShowServiceHandler::newShow() {
    // Your implementation goes here
    printf("newShow\n");
  }


ShowLabServer::ShowLabServer(std::shared_ptr<Environment> e) : env(e) 
{

}

void ShowLabServer::start() {
  int port = 9155;
  shared_ptr<ShowServiceHandler> handler(new ShowServiceHandler(env));
  shared_ptr<TProcessor> processor(new ShowServiceProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  mServer = shared_ptr<TSimpleServer>(new TSimpleServer(processor, serverTransport, transportFactory, protocolFactory));
  mServer->serve();
}

