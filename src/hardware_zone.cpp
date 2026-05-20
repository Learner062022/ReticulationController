#include "hardware_zone.h"

HardwareZone::HardwareZone(uint8_t pin, float limitL)
    : valvePin(pin),
      limitLiters(limitL) {

    pinMode(valvePin, OUTPUT);
    digitalWrite(valvePin, HIGH);
}

void HardwareZone::openValve() {
    digitalWrite(valvePin, LOW);
}

void HardwareZone::closeValve() {
    digitalWrite(valvePin, HIGH);
}

float HardwareZone::getLimitLiters() const {
    return limitLiters;
}