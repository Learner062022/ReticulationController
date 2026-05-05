#include "Controller.h"

Controller::Controller(std::array<Zone, ZONE_COUNT>& zonesRef, uint8_t flowPin)
    : zones(zonesRef),
      activeZone(-1),
      flowMeter(flowPin),
      startLiters(0) {}

void Controller::startCycle() {
    activeZone = 0;
    startLiters = flowMeter.liters();
    zones[activeZone].start();
}

void Controller::update() {
    if (activeZone == -1) {
        return;
    }

    float current = flowMeter.liters();
    float used = current - startLiters;

    if (used >= zones[activeZone].getLimitLiters()) {
        zones[activeZone].stop();

        activeZone++;

        if (activeZone >= ZONE_COUNT) {
            activeZone = -1;
            return;
        }

        startLiters = current;
        zones[activeZone].start();
    }
}

float Controller::getLiters() const {
    return flowMeter.liters();
}