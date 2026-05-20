#include "yfs201_flow_meter.h"

YFS201FlowMeter::YFS201FlowMeter(uint8_t p) : pin(p), pulses(0) {
    pinMode(pin, INPUT_PULLUP);
    attachInterruptArg(digitalPinToInterrupt(pin), isr, this, RISING);
}

float YFS201FlowMeter::getTotalLiters() const {
    noInterrupts();
    uint32_t copy = pulses;
    interrupts();

    return static_cast<float>(copy) / PULSES_PER_LITER;
}

void IRAM_ATTR YFS201FlowMeter::isr(void* arg) {
    YFS201FlowMeter* self = static_cast<YFS201FlowMeter*>(arg);
    self->pulses++;
}