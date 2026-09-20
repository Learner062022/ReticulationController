# Reticulation Controller Design

## Introduction

This document defines the prototype architecture, control flow, interfaces, validation approach, and deployment limitations.

## System Architecture

### Components and Interfaces

| Component or interface | Implementation                                                   | Purpose                         |
| ---------------------- | ---------------------------------------------------------------- | ------------------------------- |
| Controller             | ESP32 C++ firmware using Arduino core and PlatformIO             | Run irrigation logic            |
| Flow sensor            | YF-S201 pulse meter via GPIO interrupt                           | Measure water usage             |
| Zone output            | Solenoid valves through `IZone`                                  | Open and close irrigation zones |
| Network                | ESP32 Wi‑Fi                                                      | Connect to the local network    |
| Telemetry              | Adafruit IO client and `reticulationcontroller.total-usage` feed | Publish total usage             |

### Control Flow

- a `Controller` manages four `IZone` instances
- the master valve opens at the start of the cycle
- the active zone runs until its litres limit is reached
- `Controller::update()` compares usage against the active zone limit
- when the limit is reached, the current zone closes and the next zone opens
- after the final zone, the master valve closes and the controller returns to idle
- total usage is published to the configured Adafruit IO feed

## Testing and Validation

| Test case             | Expected result                               |
| --------------------- | --------------------------------------------- |
| Controller sequencing | Zones switch in order when limits are reached |
| Flow conversion       | Pulse totals convert consistently to litres   |
| Adafruit IO publish   | Usage is saved to the configured feed         |
| Limit enforcement     | Current zone closes and the next one opens    |

## Status

This prototype is complete for local irrigation control and telemetry demonstration. It is not a production deployment system and does not yet include remote configuration or hardened security.
