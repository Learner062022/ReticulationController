#include "FlowMeter.h"
#include <Arduino.h>

FlowMeter::FlowMeter(const unsigned int num_pin)
    : pin_num(num_pin)
{
}

float FlowMeter::liters() const {
    noInterrupts();
    unsigned long copy = pulses;
    interrupts();

    return static_cast<float>(copy) / pulses_per_liter;
}

void FlowMeter::reset() {
    noInterrupts();
    pulses = 0;
    interrupts();
}