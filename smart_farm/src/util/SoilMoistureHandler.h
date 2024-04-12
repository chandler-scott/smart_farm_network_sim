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

#ifndef SMARTFARM_SOILMOISTUREHANDLER_H_
#define SMARTFARM_SOILMOISTUREHANDLER_H_

#include <cstdlib>  // Include for std::rand() and std::srand()
#include <ctime>    // Include for std::time()
#include <algorithm> // Include for std::max()


namespace smart_farm {

class SoilMoistureHandler {
public:
    SoilMoistureHandler();  // Static method to access the instance
    virtual ~SoilMoistureHandler();             // Destructor

    void TurnIrrigationOn();
    void TurnIrrigationOff();
    void UpdateSoilMoisture();
    double GetSoilMoisture();

private:
double currentSoilMoisture;                 // Variable to hold the soil moisture level
    bool irrigationOn;                          // Variable to indicate if irrigation is turned on
};

} // namespace smart_farm

#endif /* SMARTFARM_SOILMOISTUREHANDLER_H_ */
