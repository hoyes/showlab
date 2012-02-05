#include "ShowService_client.h"

ShowService_client::ShowService_client() 
{
        
}

void ShowService_client::start()
{
  boost::shared_ptr<TSocket> socket(new TSocket("localhost", 9155));
  boost::shared_ptr<TTransport> transport(new TBufferedTransport(socket));
  boost::shared_ptr<TProtocol> protocol(new TBinaryProtocol(transport));

  mTransport = transport;

  mClient = boost::shared_ptr<ShowServiceClient>(new ShowServiceClient(protocol));
  transport->open();
}

void ShowService_client::stop()
{
   mTransport->close();
}
