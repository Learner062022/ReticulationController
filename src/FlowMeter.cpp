#include "FlowMeter.h"

FlowMeter::FlowMeter(uint8_t pin)
    : pin(pin)
{
}

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

uint8_t FlowMeter::get_pin() const {
    return pin;
}