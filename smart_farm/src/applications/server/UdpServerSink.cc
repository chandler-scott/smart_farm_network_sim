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

#include "UdpServerSink.h"
#include "UdpServerApp.h"
#include "inet/common/packet/Packet.h"

#include "../SensorPacket_m.h"
#include "inet/networklayer/common/L3AddressTag_m.h"



using namespace smart_farm;

Define_Module(UdpServerSink);


void UdpServerSink::processPacket(Packet *pk)
{
    SensorPacket* packet = dynamic_cast<SensorPacket*>(pk);
    if (packet == nullptr) {
        EV_WARN << "Packet is not a SensorPacket" << endl;
        return;
    }
    EV_DEBUG << "<<<<<<<< Soil Moisture: " << packet->getSoilMoistureLevel() << endl;

    // Get source IP address safely
    inet::L3Address srcAddress;
    if (auto l3Tag = pk->findTag<inet::L3AddressInd>()) {
        srcAddress = l3Tag->getSrcAddress();
    }

    UdpServerApp* serverApp = check_and_cast<UdpServerApp*>(getModuleByPath("^.app[1]"));
    serverApp->sendIrrigationResponse(packet->getSoilMoistureLevel(), srcAddress);

    UdpSink::processPacket(pk);
}


