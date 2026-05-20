#include "fake_zone.h"

FakeZone::FakeZone(float limit) : limitLiters(limit) {}

void FakeZone::openValve() {
    valveOpen = true;
}

void FakeZone::closeValve() {
    valveOpen = false;
}

float FakeZone::getLimitLiters() const {
    return limitLiters;
}