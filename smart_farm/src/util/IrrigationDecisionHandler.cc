/*
 * IrrigationDecisionHandler.cc
 *
 *  Created on: Apr 13, 2024
 *      Author: chandler
 */

#include "IrrigationDecisionHandler.h"

using namespace smart_farm;

IrrigationDecisionHandler::IrrigationDecisionHandler() {
    irrigationThreshold = 50;
}

IrrigationDecisionHandler::~IrrigationDecisionHandler() {
}

bool IrrigationDecisionHandler::turnIrrigationOn(double moistureLevel) {
    return moistureLevel <= irrigationThreshold;
}

void IrrigationDecisionHandler::setIrrigationThreshold(double threshold){
    irrigationThreshold = threshold;
}
