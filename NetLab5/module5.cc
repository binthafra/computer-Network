/*
 * module.cc
 *
 *  Created on: Mar 22, 2021
 *      Author: HP
 */
#include <omnetpp.h>

using namespace omnetpp;

class lab5node29 : public cSimpleModule
{
private:
    int source, dest;
    int count;
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
    void forwardMessage(cMessage *msg);
    void finish() override;
};

Define_Module(lab5node29);

void lab5node29 :: initialize()
{
  count = 0;
 // e = par("energy");
  source = par("start");
  dest = par("stop");

  if(getIndex()==source)
  {

      cMessage *msg= new cMessage("Afra C173229");
      forwardMessage(msg);
  }
  else
  {
      EV<<"Insufficient Energy";
  }
}

void lab5node29 :: handleMessage(cMessage *msg)
{
   if (getIndex()==dest)
   {
       delete msg;
       EV<<"Reached or Insufficient Energy";
   }
   else
   {
       forwardMessage(msg);
   }

}

void lab5node29 :: forwardMessage(cMessage *msg)
{
  int n,k;
  int ag_index;
  cGate *ag = msg->getArrivalGate();
  n=gateSize("gate");
  k=intuniform(0, n-1); //random selection of gate

  if(ag!=NULL && n>1)
  {
      ag_index = ag->getIndex(); //recieve index k arival index ag_index
      while(ag_index == k)
      {
          k = intuniform(0, n-1);
      }
  }
  send(msg,"gate$o",k); //sending msg to kth gate
  count+=1;
  //e-=0.2;
  EV<<"Count: "<<count;
  //EV<< "Remaining Energy :"<<e;

}
void lab5node29 :: finish()
{
    recordScalar("#Forward no:",count);
}



