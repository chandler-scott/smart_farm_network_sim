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

#include "../nodes/WirelessSensorHost.h"


using namespace smart_farm;

Define_Module(WirelessSensorHost);


WirelessSensorHost::WirelessSensorHost() : soilMoistureHandler(nullptr) {}

WirelessSensorHost::~WirelessSensorHost() {
    delete soilMoistureHandler;  // Ensure we clean up the SoilMoistureHandler
}

void WirelessSensorHost::initialize(int stage) {
    if (stage == INITSTAGE_LOCAL) {
        updateSoilMoistureTimer = par("updateSoilMoistureTimer");

        soilMoistureHandler = new SoilMoistureHandler();  // Initialize SoilMoistureHandler
        updateDisplayString();
        updateMessage = new cMessage("Update Soil Moisture");
        scheduleAt(1.0, updateMessage);
    }
}

void WirelessSensorHost::handleMessage(cMessage *msg){
    if (msg->isSelfMessage()){
        soilMoistureHandler->updateSoilMoisture();
        updateDisplayString();
        scheduleAt(simTime() + 120.0, updateMessage);
    }
}

void WirelessSensorHost::updateDisplayString(){
    std::stringstream ss;
    ss << "Moisture: " << soilMoistureHandler->getSoilMoisture();
    getDisplayString().setTagArg("t", 0, ss.str().c_str());
}

double WirelessSensorHost::getSoilMoisture(){
    return soilMoistureHandler->getSoilMoisture();
}

bool WirelessSensorHost::getIrrigationStatus(){
    return soilMoistureHandler->getIrrigationStatus();
}

void WirelessSensorHost::setIrrigationStatus(bool turnIrrigationOn){
    soilMoistureHandler->setIrrigationStatus(turnIrrigationOn);
    if (turnIrrigationOn) {
        getDisplayString().setTagArg("i", 0, "status/yellow");
    }
    else {
        getDisplayString().setTagArg("i", 0, "status/off");
   }
}
