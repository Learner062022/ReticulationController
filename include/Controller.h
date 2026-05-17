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
    uint8_t masterValvePin;

public:
    Controller(std::array<Zone, ZONE_COUNT>& zones,
               uint8_t flowPin,
               uint8_t masterValvePin);

    void startCycle();
    void update();
};