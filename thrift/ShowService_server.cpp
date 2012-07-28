#include "ShowService_server.h"
#include "../lib/AudioAction.h"

ShowServiceHandler::ShowServiceHandler(std::shared_ptr<Environment> e) : env(e)
{

}

void ShowServiceHandler::addCueWithNumber(std::string& _return, const double number, const std::string& name) {
   printf("addCueWithNumber\n");
   CueUid uid = env->getShow().addCueWithNumber(number, name);
   _return = Cue::convertUidToString(uid);
}

void ShowServiceHandler::addCueAtLocation(std::string& _return, const std::string& location, const std::string& name) {
   printf("addCueAtLocation\n");
   //return env->getShow().addCueAtLocation(location, name);
}

  void ShowServiceHandler::getCues(std::vector<CueData> & _return) {
    // Your implementation goes here
    printf("getCues\n");
    
    std::vector<CueData> cues;
    for (auto i = env->getShow().cuesBegin(); i != env->getShow().cuesEnd(); ++i) {
        CueData d;
        d.number = (*i)->Number();
        d.name = (*i)->Name();
        cues.push_back(d);
    }
    _return = cues;
  }

  void ShowServiceHandler::getCue(CueData& _return, const std::string& id) {
    // Your implementation goes here
    printf("getCue\n");
    CueUid uid = Cue::convertStringToUid(id);
    
    CueRef c = env->getShow().cue(uid);
    CueData d;
    d.uid = id;
    d.name = c->Name();
    d.number = c->Number();
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

 void ShowServiceHandler::addAudioActionById(const std::string& cueid, const std::string& filename) {
    // Your implementation goes here
    ActionRef a(new AudioAction(env->getAudioManager(), "", filename));
    CueUid uid = Cue::convertStringToUid(cueid);
    env->getShow().cue(uid)->addAction(a);
  }

  void ShowServiceHandler::addAudioActionByNumber(const int32_t num, const std::string& filename) {
    // Your implementation goes here
    ActionRef a(new AudioAction(env->getAudioManager(), "", filename));
    env->getShow().cue(num)->addAction(a);
  }

void ShowServiceHandler::go()
{
    env->getShow().go();
}

void ShowServiceHandler::reset()
{
    env->getShow().reset();
}

void ShowServiceHandler::standbyUid(const std::string& id) {
        CueUid uid = Cue::convertStringToUid(id);
        env->getShow().standby(uid);
}

void ShowServiceHandler::standbyNum(const double number) {
        env->getShow().standby((float) number);
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

