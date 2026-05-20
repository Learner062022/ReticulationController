#pragma once

#include "i_zone.h"
#include <Arduino.h>

class HardwareZone : public IZone{
public:
    HardwareZone(uint8_t pin, float limitLiters);
    void openValve() override;
    void closeValve() override;
    float getLimitLiters() const override;

private:
    uint8_t valvePin;
    float limitLiters;
};