#pragma once

#include <Arduino.h>

class FlowMeter {
private:
    const uint8_t pin;
    static constexpr float pulses_per_liter = 450.0f;
    volatile unsigned long pulses = 0;

public:
    FlowMeter(uint8_t pin);
    void pulse();
    float liters() const;
    void reset();
    uint8_t get_pin() const;
};