#include "Zone.h"

Zone::Zone(uint8_t pin, float limitL)
    : valvePin(pin),
      limitLiters(limitL) {

    pinMode(valvePin, OUTPUT);
    digitalWrite(valvePin, HIGH);
}

void Zone::start() {
    digitalWrite(valvePin, LOW);
}

void Zone::stop() {
    digitalWrite(valvePin, HIGH);
}

float Zone::getLimitLiters() const {
    return limitLiters;
}