#ifndef SHOW_SERVICE_CLIENT_H
#define SHOW_SERVICE_CLIENT_H

#include <memory>
#include "ShowService.h"
#include <transport/TSocket.h>
#include <transport/TBufferTransports.h>
#include <protocol/TBinaryProtocol.h>


using namespace apache::thrift;
using namespace apache::thrift::protocol;
using namespace apache::thrift::transport;


class ShowService_client
{
private:
        boost::shared_ptr<TTransport> mTransport;
        boost::shared_ptr<TProtocol> mProtocol;
        boost::shared_ptr<ShowServiceClient> mClient;

public:
        void start();
        void stop();
        ShowService_client();
        ShowServiceClient& getInterface() { return *mClient; }
};

#endif
