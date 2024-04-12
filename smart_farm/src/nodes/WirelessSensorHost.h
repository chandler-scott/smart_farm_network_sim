//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __SMARTFARM_WIRELESSSENSORHOST_H
#define __SMARTFARM_WIRELESSSENSORHOST_H

#include "../util/SoilMoistureHandler.h"
#include "inet/node/base/NodeBase.h"
#include <omnetpp.h>


namespace smart_farm {

using namespace inet;

/**
 * Wireless Sensor Host -- extension of INET WirelessHost
 */
class WirelessSensorHost :  public cSimpleModule
{
private:
    cMessage *updateMessage;

    void updateDisplayString();
protected:
    smart_farm::SoilMoistureHandler* soilMoistureHandler;  // Pointer to the SoilMoistureHandler

    virtual int numInitStages() const override { return inet::NUM_INIT_STAGES; }
    virtual void initialize(int stage) override;
    virtual void handleMessage(cMessage *msg) override;

public:
    WirelessSensorHost();
    virtual ~WirelessSensorHost();

    smart_farm::SoilMoistureHandler* getSoilMoistureHandler() const { return soilMoistureHandler; }
};

} // namespace smart_farm
#endif

