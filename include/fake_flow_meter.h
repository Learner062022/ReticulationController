// FakeFlowMeter
// -----------------------------
// Simulation-only implementation of IFlowMeter.
// Used to inject synthetic flow during testing so controller logic,
// zone sequencing and telemetry can be exercised without hardware.
// Real hardware uses YFS201FlowMeter, which increments pulses via ISR.

#pragma once
#include "i_flow_meter.h"

class FakeFlowMeter : public IFlowMeter {
private:
    float liters = 0.0f;

public:
    void addLiters(float amount);
    float getTotalLiters() const override;
    
};