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

#include "../util/SoilMoistureHandler.h"
using namespace smart_farm;

SoilMoistureHandler::SoilMoistureHandler() {
    std::srand(std::time(0));
    currentSoilMoisture = 100.0;
    irrigationOn = false;
}

SoilMoistureHandler::~SoilMoistureHandler() {
    // Destructor code here
}

void SoilMoistureHandler::updateSoilMoisture() {
    // Generate a random number between -1.0 and 1.0
    double randomChange = rand() % 5 + 1;

    // Update current soil moisture
    currentSoilMoisture += irrigationOn ? (randomChange * 2) : -randomChange;

    // Moisture can't be below 0
    currentSoilMoisture = std::max((double)0, currentSoilMoisture);
}

double SoilMoistureHandler::getSoilMoisture() {
    return currentSoilMoisture;
}

bool SoilMoistureHandler::getIrrigationStatus(){
    return irrigationOn;
}

void SoilMoistureHandler::setIrrigationStatus(bool value) {
    irrigationOn = value;
}
