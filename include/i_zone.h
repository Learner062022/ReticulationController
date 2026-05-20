#pragma once

class IZone {
public:
    virtual ~IZone() = default;

    virtual void openValve() = 0;
    virtual void closeValve() = 0;
    virtual float getLimitLiters() const = 0;
};