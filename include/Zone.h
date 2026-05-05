#pragma once

#include <Arduino.h>

class Zone {
public:
    Zone(uint8_t pin, float limitLiters);
    void start();
    void stop();
    bool isActive() const;
    float getLimitLiters() const;

private:
    uint8_t valvePin;
    bool active;
    float limitLiters;
};