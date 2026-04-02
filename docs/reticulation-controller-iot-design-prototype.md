# Reticulation Controller - IoT Design & Prototype

## Scope

### Key Requirements
- Settable limit per station.
- Water usage monitorable.

---

### System Parameters

| Questions                   | Response                 |
| --------------------------- | ------------------------ |
| Amount of stations          | 4                        |
| Controls for setting limits | Dashboard                |
| Existing reticulation setup | Existing pipeline system |

---

## Framework Selection

| Framework Component    | Selection | Justification                                          |
| ---------------------- | --------- | ------------------------------------------------------ |
| Power Source           | AC mains  | Integrated AC/DC module provides safe, stable power.    |
| Programming Language   | C++       | Direct support for ESP32 and available libraries.       |
| Communication Protocol | MQTT      | Lightweight, secure cloud communication for AdafruitIO. |

---

## System Overview / Data Flow

- Each irrigation zone consists of a **flow meter and a solenoid valve**, connected to the all-in-one ESP32 module.  
- The **ESP32 AC/DC 4-Channel Relay Module** manages all four zones directly, controlling relays and reading flow meters.  
- Zone limits are enforced locally on the ESP32.  
- Flow data is uploaded to **AdafruitIO** (or another cloud dashboard) for monitoring and visualization.  
- Onboard buttons can optionally be used for manual limit adjustments.

---

## Device & Prototype Integration

| Component       | Function & Integration      | Signal / Preprocessing / Protection | Power Source / Notes      |
| --------------- | --------------------------- | ----------------------------------- | ------------------------- |
| ESP32 AC/DC     | Controls solenoids.         | Integrated level shifting.          | Powered by onboard DC.    |
| 4-Channel Relay | Counts pulses, uploads data.| Logic protection.                   | Integrated with ESP32.    |
| Solenoid valves | Opens/closes per zone.      | Controlled by ESP32 relay outputs.  | AC mains via module relay.|

> **Note:** The all-in-one board removes the need for separate D1 Minis, buck converters, and logic level shifters. Signal conditioning and relay control are integrated.

---

## Communication Protocols

| Device       | Protocol                  | Justification        | Function                |
| ------------ | ------------------------- | -------------------- | ----------------------- |
| ESP32 Module | Wi-Fi (IEEE 802.11 b/g/n) | Standard wireless.   | Local/cloud network.    |
|              | MQTTS                     | Secure communication.| Upload water usage data.|

---

## Data Processing & Dashboard

- All flow readings are handled on the ESP32.  
- Dashboard visualizes trends (graphs) and real-time state (gauges).  
- Users set limits through AdafruitIO or onboard buttons.

---

## Security & Regulatory Compliance

| Component    | Security Measure / Regulation           | Compliance                                           |
| ------------ | --------------------------------------- | ---------------------------------------------------- |
| ESP32 Module | MQTTS, Wi-Fi security.                  | Secure cloud communication.                          |
| System       | AC mains isolation & onboard protection.| Integrated AC/DC relay module meets safety standards.|

---

## Benefits & Advantages

**Benefits**  
- Single-board integration reduces wiring and complexity.  
- Built-in relays and power supply improve reliability.  

**Advantages**  
- Decentralized D1 Mini network no longer required.  
- Faster deployment and fewer components.  
- Easier maintenance and fewer failure points.

---

## Testing

| Test Case               | Method                         | Expected Outcome                                          |
| ----------------------- | ------------------------------ | --------------------------------------------------------- |
| Water limit enforcement | Simulate flow to preset limit. | Relay closes solenoid when limit is reached; data logged. |
| Remote monitoring       | Observe AdafruitIO dashboard.  | Correct flow readings and zone status displayed.          |

---

## IoT Dashboard

### Data Visualization

| Type   | Why                                        |
| ------ | ------------------------------------------ |
| Graphs | Observe water usage trends per zone.       |
| Gauges | Real-time state of solenoids per zone.     |

---

### User Controls

- Settable limit per zone via AdafruitIO.  
- Optional onboard buttons for manual adjustments.

---

### Platform

- AdafruitIO for remote monitoring, control, and logging.