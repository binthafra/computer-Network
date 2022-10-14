/*
 * module.cc
 *
 *  Created on: Jun 28, 2021
 *      Author: HP
 */
#include <omnetpp.h>

using namespace omnetpp;

class final2node29 : public cSimpleModule
{
private:
    int source, dest;
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
    void forwardMessage(cMessage *msg);

};

Define_Module(final2node29);

void final2node29 :: initialize()
{
  source = par("start");
  dest = par("stop");

  if(getIndex()==source)
  {

      cMessage *msg= new cMessage("Hello from afra");
      forwardMessage(msg);
  }
}

void final2node29 :: handleMessage(cMessage *msg)
{
   if (getIndex()==dest)
   {
       delete msg;
   }
   else
   {
       forwardMessage(msg);
   }

}

void final2node29 :: forwardMessage(cMessage *msg)
{
  int n,k;
  n=gateSize("gate");
  k=intuniform(0,n-1); //random selection of gate
  send(msg,"gate$o",k); //sending msg to kth gate
}



