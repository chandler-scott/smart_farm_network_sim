//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "UdpSensorSink.h"
#include "../ServerPacket_m.h"
#include "../../nodes/WirelessSensorHost.h"

using namespace smart_farm;

Define_Module(UdpSensorSink);

void UdpSensorSink::processPacket(Packet *pk)
{
    ServerPacket* packet = dynamic_cast<ServerPacket*>(pk);
    if (packet == nullptr) {
        EV_WARN << "Packet is not a SensorPacket" << endl;
        return;
    }
    EV_DEBUG << "<<<<<<<< Turn Irrigation On: " << packet->getTurnIrrigationOn() << endl;
    WirelessSensorHost *sensor = check_and_cast<WirelessSensorHost*>(getParentModule());

    bool turnIrrigationOn = packet->getTurnIrrigationOn();

    if (turnIrrigationOn != sensor->getIrrigationStatus()) {
        sensor->setIrrigationStatus(turnIrrigationOn);
    }

    inet::UdpSink::processPacket(pk);
}
