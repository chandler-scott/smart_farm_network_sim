//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __SMARTFARM_UDPSERVERAPP_H
#define __SMARTFARM_UDPSERVERAPP_H

#include "inet/applications/udpapp/UdpBasicApp.h"

using namespace inet;


namespace smart_farm {

/**
 * UDP application. See NED for more info.
 */
class UdpServerApp : public UdpBasicApp
{
public:
    void sendIrrigationResponse(double data, inet::L3Address destAddr);
protected:
    virtual void initialize(int stage) override;
    virtual void handleMessageWhenUp(cMessage *msg) override;

}; // namespace smart_farm

}
#endif

