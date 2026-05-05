#include "Zone.h"

Zone::Zone(uint8_t pin, float limitL)
    : valvePin(pin),
      active(false),
      limitLiters(limitL) {

    pinMode(valvePin, OUTPUT);
    digitalWrite(valvePin, LOW);
}

void Zone::start() {
    digitalWrite(valvePin, HIGH);
    active = true;
}

void Zone::stop() {
    digitalWrite(valvePin, LOW);
    active = false;
}

bool Zone::isActive() const {
    return active;
}

float Zone::getLimitLiters() const {
    return limitLiters;
}