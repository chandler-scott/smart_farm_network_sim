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

#include "UdpServerApp.h"

#include "inet/applications/base/ApplicationPacket_m.h"
#include "inet/common/TimeTag_m.h"
#include "inet/networklayer/common/FragmentationTag_m.h"
#include "inet/networklayer/common/L3AddressResolver.h"
#include "../ServerPacket_m.h"
#include "../../nodes/WirelessServerHost.h"
#include "../../util/IrrigationMessageData.h"


using namespace smart_farm;

Define_Module(UdpServerApp);

void UdpServerApp::initialize(int stage){
    UdpBasicApp::initialize(stage);
}

void UdpServerApp::sendIrrigationResponse(double data, inet::L3Address destAddr) {
    Enter_Method("sendIrrigationResponse");
    IrrigationMessageData *irrMsgData = new IrrigationMessageData(data, destAddr);
    scheduleAt(simTime() + 2, irrMsgData->timerMsg);
}

void UdpServerApp::handleMessageWhenUp(cMessage *msg){
    if (strcmp(msg->getName(), "delayTimer") == 0) {
        IrrigationMessageData *irrMsgData = static_cast<IrrigationMessageData*>(msg->getContextPointer());
        if(irrMsgData) {
            auto data = irrMsgData->data;
            auto destAddr = irrMsgData->destAddr;

            EV_DEBUG << "Directly received data: " << data  << " originally from " << destAddr << endl;
            // Process data as needed
            std::ostringstream str;
            str << packetName << "-" << numSent;
            ServerPacket *packet = new ServerPacket(str.str().c_str());
            if (dontFragment)
                packet->addTag<FragmentationReq>()->setDontFragment(true);
            const auto& payload = makeShared<ApplicationPacket>();
            payload->setChunkLength(B(par("messageLength")));
            payload->setSequenceNumber(numSent);
            payload->addTag<CreationTimeTag>()->setCreationTime(simTime());
            packet->insertAtBack(payload);
            /*********************************************************
                logic to decide to turn irrigation on here
            *********************************************************/
            WirelessServerHost *server = check_and_cast<WirelessServerHost*>(getParentModule());
            bool turnOn = server->irrigationDecisionHandler.turnIrrigationOn(data);
            packet->setTurnIrrigationOn(turnOn);

            emit(packetSentSignal, packet);
            socket.sendTo(packet, destAddr, destPort);
            numSent++;
        }
    }
    else {
        UdpBasicApp::handleMessageWhenUp(msg);
    }
}
