#include "fake_flow_meter.h"

void FakeFlowMeter::addLiters(float amount) {
    liters += amount;
}

float FakeFlowMeter::getTotalLiters() const {
    return liters;
}