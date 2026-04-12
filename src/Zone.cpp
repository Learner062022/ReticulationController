#include "Zone.h"

Zone::Zone(uint8_t flowMeterPin,
    uint8_t solenoidPin, 
    const float limit)
    : meter(flowMeterPin),
      solenoidPin(solenoidPin),
      limit(limit)
{
}

// attachInterrupt(digitalPinToInterrupt(pin), ISR, mode);
// void IRAM_ATTR onPulse() {
    
// }

void Zone::pulse() {
    meter.pulse();
}

void Zone::handle_solenoid() {
    if (meter.liters() >= limit) {
        // digitalWrite(soleniodPin, ...)
    }
    else
    {
        // digitalWrite(soleniodPin, ...)
    }
}

float Zone::liters() const {
    return meter.liters();
}

FlowMeter& Zone::get_meter() {
    return meter;
}