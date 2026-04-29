#pragma once

#include <Arduino.h>

class FlowMeter {
private:
    static constexpr float pulses_per_liter = 450.0f;
    volatile unsigned long pulses = 0;

public:
    void pulse();
    float liters() const;
    void reset();
};