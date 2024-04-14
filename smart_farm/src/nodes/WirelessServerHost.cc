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

#include "../nodes/WirelessServerHost.h"

using namespace smart_farm;

Define_Module(WirelessServerHost);


WirelessServerHost::WirelessServerHost() : irrigationDecisionHandler() {}

WirelessServerHost::~WirelessServerHost() {
}

void WirelessServerHost::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        irrigationDecisionHandler.setIrrigationThreshold(par("irrigationThreshold"));
    }
}

void WirelessServerHost::handleMessage(cMessage *msg){

}
