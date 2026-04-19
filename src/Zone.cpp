#include "Zone.h"

Zone::Zone(FlowMeter &meterRef, const float limit)
    : meter(meterRef),
      limit(limit)
{
}

void Zone::set_valve(bool v) {
    valve_open = v;
}

void Zone::update() {
    if (meter.liters() >= limit) {
        set_valve(false);
    }
}

bool Zone::is_open() const {
    return valve_open;
}

float Zone::liters() {
    return meter.liters();
}