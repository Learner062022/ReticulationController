#include "FlowMeter.h"

FlowMeter::FlowMeter(unsigned int num_pin, unsigned int limit)
    : pin_num(num_pin),
      water_limit_liters(limit)
{
}

float FlowMeter::flow_rate_lmin(unsigned long interval_ms)
{
    if (interval_ms == 0) return 0.0f;

    return (static_cast<float>(pulse_count) / pulses_per_lmin) *
           (60000.0f / interval_ms);
}

float FlowMeter::liters() const
{
  return static_cast<float>(pulse_count) / pulses_per_lmin;
}

void FlowMeter::pulse()
{
  pulse_count++;
}

bool FlowMeter::limit_reached()
{
  return liters() >= water_limit_liters;
}