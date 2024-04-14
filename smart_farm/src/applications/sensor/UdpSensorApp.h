//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __SMARTFARM_UDPSENSORAPP_H
#define __SMARTFARM_UDPSENSORAPP_H

#include "inet/applications/udpapp/UdpBasicApp.h"

using namespace inet;


namespace smart_farm {

/**
 * UDP application. See NED for more info.
 */
class UdpSensorApp : public UdpBasicApp
{
protected:
    virtual void sendPacket() override;

}; // namespace smart_farm

}
#endif

