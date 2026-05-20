#pragma once

class IFlowMeter {
public:
    virtual ~IFlowMeter() = default;
    virtual float getTotalLiters() const = 0;
};