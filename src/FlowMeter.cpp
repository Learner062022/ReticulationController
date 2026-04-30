#include "FlowMeter.h"

FlowMeter::FlowMeter(const unsigned int num_pin)
    : pin_num(num_pin)
{
}

float FlowMeter::liters() const {
  return static_cast<float>(pulse_count) / pulses_per_liter;
}

void FlowMeter::pulse() {
  pulse_count++;
}

void FlowMeter::reset() {
  pulse_count = 0;
}