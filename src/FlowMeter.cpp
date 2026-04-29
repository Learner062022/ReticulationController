#include "FlowMeter.h"

void FlowMeter::pulse() {
    pulses++;
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