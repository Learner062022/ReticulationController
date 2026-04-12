#pragma once

class FlowMeter {
private:
    const unsigned int pulses_per_lmin = 450;
    const unsigned int pin_num;
    volatile unsigned int pulse_count = 0;
    const unsigned int water_limit_liters;

public:
    FlowMeter(const unsigned int num_pin, 
              const unsigned int limit
    );
    
    float flow_rate_lmin(unsigned long interval_ms);
    float liters() const;
    void pulse();
    bool limit_reached();
};