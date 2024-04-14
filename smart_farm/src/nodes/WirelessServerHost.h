//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __SMARTFARM_WIRELESSSERVERHOST_H
#define __SMARTFARM_WIRELESSSERVERHOST_H

#include "../util/IrrigationDecisionHandler.h"
#include "inet/node/base/NodeBase.h"
#include <omnetpp.h>


namespace smart_farm {

using namespace inet;

/**
 * Wireless Server Host -- extension of INET WirelessHost
 */
class WirelessServerHost :  public cSimpleModule
{
protected:
    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;

public:
    smart_farm::IrrigationDecisionHandler irrigationDecisionHandler;
    WirelessServerHost();
    virtual ~WirelessServerHost();
};

} // namespace smart_farm
#endif

