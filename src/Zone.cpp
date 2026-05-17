#include "Zone.h"

Zone::Zone(uint8_t pin, float limitL)
    : valvePin(pin),
      active(false),
      limitLiters(limitL) {

    pinMode(valvePin, OUTPUT);
    digitalWrite(valvePin, HIGH);
}

void Zone::start() {
    digitalWrite(valvePin, LOW);
    active = true;
}

void Zone::stop() {
    digitalWrite(valvePin, HIGH);
    active = false;
}

float Zone::getLimitLiters() const {
    return limitLiters;
}