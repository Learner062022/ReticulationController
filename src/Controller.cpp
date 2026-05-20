#include "controller.h"
#include "i_zone.h"
#include "Arduino.h"

Controller::Controller(std::array<IZone*, ZONE_COUNT>& zones,
                       IZone* masterZone,
                       IFlowMeter& flowMeter)
    : zones(zones),
      masterZone(masterZone),
      activeZone(-1),
      flowMeter(flowMeter),
      startLiters(0)
{
}

void Controller::startCycle() {
    masterZone->openValve();
    activeZone = 0;
    startLiters = flowMeter.getTotalLiters();
    zones[activeZone]->openValve();
}

float Controller::getUsedLiters() {
    return flowMeter.getTotalLiters() - startLiters;
}

void Controller::update() {
    if (activeZone == -1) {
        return;
    }
    
    if (getUsedLiters() >= zones[activeZone] -> getLimitLiters()) {

        zones[activeZone]->closeValve();
        activeZone++;

        if (activeZone >= ZONE_COUNT) {
            startLiters = flowMeter.getTotalLiters();
            masterZone->closeValve();
            activeZone = -1;
            return;
        }

        zones[activeZone]->openValve();
    }
}
