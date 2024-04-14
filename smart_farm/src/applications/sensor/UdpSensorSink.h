//
// Copyright (C) 2000 Institut fuer Telematik, Universitaet Karlsruhe
// Copyright (C) 2004,2011 OpenSim Ltd.
//
// SPDX-License-Identifier: LGPL-3.0-or-later
//


#ifndef __SMARTFARM_UDPSENSORSINK_H
#define __SMARTFARM_UDPSENSORSINK_H

#include "inet/applications/udpapp/UdpSink.h"

using namespace inet;


namespace smart_farm {

/**
 * UDP application. See NED for more info.
 */
class UdpSensorSink : public UdpSink
{
protected:
    virtual void processPacket(Packet *msg) override;
}; // namespace smart_farm

}
#endif

