#include <omnetpp.h>

struct IrrigationMessageData {
    double data;
    inet::L3Address destAddr;
    cMessage *timerMsg;
    

    IrrigationMessageData(double data, inet::L3Address addr)
        : data(data), destAddr(addr) {
        timerMsg = new cMessage("delayTimer");
        timerMsg->setContextPointer(this);
    }
        
    
    ~IrrigationMessageData() {
        delete(timerMsg);
    }
};
