#pragma once

#include "i_zone.h"

class FakeZone : public IZone {
private:
    bool valveOpen = false;
    float limitLiters;

public:
    FakeZone(float limit = 0.0f);
    void openValve() override;
    void closeValve() override;
    float getLimitLiters() const override;
};