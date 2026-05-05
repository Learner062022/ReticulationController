#pragma once

#include "Zone.h"
#include "FlowMeter.h"
#include <array>

constexpr uint8_t ZONE_COUNT = 4;

class Controller {
private:
    std::array<Zone, ZONE_COUNT>& zones;
    int activeZone;
    FlowMeter flowMeter;
    float startLiters;

public:
    Controller(std::array<Zone, ZONE_COUNT>& zones, uint8_t flowPin);
    void startCycle();
    void update();
    float getLiters() const;
};