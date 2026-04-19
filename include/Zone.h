#pragma once

#include "FlowMeter.h"

class Zone {
private:
    FlowMeter& meter;
    const float limit;
    bool valve_open=false;

public:
    Zone(FlowMeter& meter,
        const float limit);

    void set_valve(bool v);
    void update();
    bool is_open() const;
    float liters();
};