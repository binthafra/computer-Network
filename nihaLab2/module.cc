/*
 * module.cc
 *
 *  Created on: Jun 28, 2021
 *      Author: Niha
 */

#include <omnetpp.h>

using namespace omnetpp;

class labqus2node24 : public cSimpleModule

{
   private:
      int source,dest;

   protected:
       void initialize() override;
       void handleMessage(cMessage *msg) override;
       void forwardMessage(cMessage *msg);

};

Define_Module(labqus2node24);

void labqus2node24:: initialize()
{
    source = par("start");
    dest = par("stop");

    if(getIndex()== source)
    {
        cMessage *msg= new cMessage("lab3");
        forwardMessage(msg);
    }

}
void labqus2node24 :: handleMessage(cMessage *msg)
{
    if(getIndex() == dest)
    {

    delete msg;
    }

    else{
        forwardMessage(msg);
    }

}

void labqus2node24 :: forwardMessage(cMessage *msg)
{
  int n,k;
  n=gateSize("gate");
  k=intuniform(0,n-1); //random selection of gate
  send(msg,"gate$o",k); // sending msg to kth gate
}



