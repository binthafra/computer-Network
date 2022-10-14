/*
 * module.cc
 *
 *  Created on: Mar 15, 2021
 *      Author: HP
 */
#include <string.h>
#include <omnetpp.h>

using namespace omnetpp;

class labfinalnode_29 : public cSimpleModule
{
protected:
    void initialize() override;
    void handleMessage(cMessage *msg) override;
};

Define_Module(labfinalnode_29);

void labfinalnode_29:: initialize()
{
    if (strcmp("tic",getName())==0)
    {
        cMessage *msg = new cMessage("Hello");
        send(msg, "out");
    }
}
void labfinalnode_29:: handleMessage(cMessage *msg)
{
    send(msg, "out");
}




