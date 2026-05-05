#include "FlowMeter.h"

FlowMeter::FlowMeter(uint8_t p) : pin(p), pulses(0) {
    pinMode(pin, INPUT_PULLUP);
    attachInterruptArg(digitalPinToInterrupt(pin), isr, this, RISING);
}

float FlowMeter::liters() const {
    noInterrupts();
    uint32_t copy = pulses;
    interrupts();

    return static_cast<float>(copy) / PULSES_PER_LITER;
}

void IRAM_ATTR FlowMeter::isr(void* arg) {
    FlowMeter* self = static_cast<FlowMeter*>(arg);
    self->pulses++;
}