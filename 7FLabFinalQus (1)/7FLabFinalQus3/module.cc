/*
 * module.cc
 *
 *  Created on: Jun 28, 2021
 *      Author: Niha
 */

#include <omnetpp.h>

using namespace omnetpp;

class labqus3node24 : public cSimpleModule

{
private:
    int source, dest;
    int count;
    double e;
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
    void forwardMessage(cMessage *msg);
    void finish() override;

};

Define_Module(labqus3node24);

void labqus3node24:: initialize()
{
    count = 0;
     e = par("energy");
     source = par("start");
     dest = par("stop");

     if((getIndex()==source) && (e>0.5))
     {

         cMessage *msg= new cMessage("C173224");
         forwardMessage(msg);
     }
     else
     {
         EV<<"Insufficient Energy";
     }

}
void labqus3node24 :: handleMessage(cMessage *msg)
{
    if ((getIndex()==dest) || (e<0.5))
       {
           delete msg;
           EV<<"Reached or Insufficient Energy";
       }
       else
       {
           forwardMessage(msg);
       }
}

void labqus3node24 :: forwardMessage(cMessage *msg)
{
  int n,k;
  n=gateSize("gate");
  k=intuniform(0,n-1); //random selection of gate
  send(msg,"gate$o",k); // sending msg to kth gate
  count+=1;
  e-=0.5;
  EV<<"Count: "<<count;
  EV<<"Remaining Energy: "<<e;
}
void labqus3node24 :: finish()
{
    recordScalar("#Forward no:",count);
  recordScalar("#Remaining Energy:",e);
}






