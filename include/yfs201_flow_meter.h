#pragma once

#include "i_flow_meter.h"
#include <Arduino.h>

class YFS201FlowMeter : public IFlowMeter {
private:
    const uint8_t pin;
    static constexpr float PULSES_PER_LITER = 450.0f;
    volatile uint32_t pulses;

public:
    YFS201FlowMeter (uint8_t pin);
    float getTotalLiters() const override;
    static void isr(void* arg);
};