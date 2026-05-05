#pragma once

#include <Arduino.h>

class FlowMeter {
private:
    const uint8_t pin;
    static constexpr float PULSES_PER_LITER = 450.0f;
    volatile uint32_t pulses;

public:
    FlowMeter(uint8_t pin);
    float liters() const;
    static void isr(void* arg);
};