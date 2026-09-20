#include "Controller.h"

Controller::Controller(std::array<Zone, ZONE_COUNT>& zonesRef,
                       uint8_t flowPin,
                       uint8_t masterValvePin)
    : zones(zonesRef),
      activeZone(-1),
      flowMeter(flowPin),
      startLiters(0),
      masterValvePin(masterValvePin)
{
    pinMode(masterValvePin, OUTPUT);
    digitalWrite(masterValvePin, HIGH);
}

void Controller::startCycle() {
    digitalWrite(masterValvePin, LOW);
    activeZone = 0;
    startLiters = flowMeter.liters();
    zones[activeZone].start();
}

float Controller::getUsedLiters() {
    return flowMeter.liters() - startLiters;
}

void Controller::update() {
    if (activeZone == -1) {
        return;
    }

    if (getUsedLiters() >= zones[activeZone].getLimitLiters()) {

        zones[activeZone].stop();
        activeZone++;

        if (activeZone >= ZONE_COUNT) {
            digitalWrite(masterValvePin, HIGH);
            activeZone = -1;
            return;
        }

        zones[activeZone].start();
    }
}
