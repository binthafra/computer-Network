/*
 * module.cc
 *
 *  Created on: Mar 22, 2021
 *      Author: HP
 */

#include <omnetpp.h>

using namespace omnetpp;

class lab3node27 : public cSimpleModule
{
private:
    int source, dest;
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
    void forwardMessage(cMessage *msg);

};

Define_Module(lab3node27);

void lab3node27 :: initialize()
{
  source = par("start");
  dest = par("stop");

  if(getIndex()==source)
  {

      cMessage *msg= new cMessage("C173227");
      forwardMessage(msg);
  }
}

void lab3node27 :: handleMessage(cMessage *msg)
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

void lab3node27 :: forwardMessage(cMessage *msg)
{
  int n,k;
  n=gateSize("gate");
  k=intuniform(0,n-1); //random selection of gate
  send(msg,"gate$o",k); // sending msg to kth gate
}


