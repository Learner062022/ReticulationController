#pragma once

class FlowMeter {
private:
    const unsigned int pulses_per_liter = 450;
    const unsigned int pin_num;
    volatile unsigned int pulse_count = 0;

public:
    FlowMeter(const unsigned int num_pin);
    float liters() const;
    void pulse();
    void reset();
};