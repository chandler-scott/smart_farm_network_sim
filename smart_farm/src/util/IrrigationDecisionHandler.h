/*
 * IrrigationDecisionHandler.h
 *
 *  Created on: Apr 13, 2024
 *      Author: chandler
 */

#ifndef UTIL_IRRIGATIONDECISIONHANDLER_H_
#define UTIL_IRRIGATIONDECISIONHANDLER_H_
namespace smart_farm {

class IrrigationDecisionHandler {
private:
    double irrigationThreshold;
public:
    IrrigationDecisionHandler();
    virtual ~IrrigationDecisionHandler();
    bool turnIrrigationOn(double moistureLevel);
    void setIrrigationThreshold(double threshold);
};
}
#endif /* UTIL_IRRIGATIONDECISIONHANDLER_H_ */
