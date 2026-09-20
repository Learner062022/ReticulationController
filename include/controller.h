#pragma once

#include "i_zone.h"
#include "i_flow_meter.h"
#include <cstdint>
#include <array>

constexpr std::uint8_t ZONE_COUNT = 4;

class Controller {
private:
    std::array<IZone*, ZONE_COUNT>& zones;
    IZone* masterZone;
    std::int8_t activeZone;
    IFlowMeter& flowMeter;
    float startLiters;

public:
    Controller(std::array<IZone*, ZONE_COUNT>& zones,
               IZone* masterZone, 
               IFlowMeter& flowMeter);

    void startCycle();
    float getUsedLiters();
    void update();
};