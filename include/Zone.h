#pragma once

#include "FlowMeter.h"
#include <AdafruitIO_WiFi.h>

class Zone {
private:
    FlowMeter meter;
    const uint8_t solenoidPin;
    const float limit;

// Needs to own ISR handling; complete irrigation control must be encapsulated

public:
    Zone(uint8_t flowMeterPin,
        uint8_t solenoidPin,
        const float limit);

    void pulse();
    void handle_solenoid();
    float liters() const;
    FlowMeter& get_meter();
};