# Reticulation Controller

## Overview
An ESP32-based automated irrigation system that controls multi-zone watering using flow-based usage limit and provides cloud-based monitoring of water consumption.

---

## Features
- Multi-zone irrigation control  
- Flow meter-based water usage trackiing per zone
- Automatic solenoid valve switching via relay control
- Configurable water usage limits per zone
- Cloud telemetry for usage monitoring (read-only dashboard integration)  

---

## Hardware Options

### Option 1: Integrated Board
- ESP32 AC/DC Wi-Fi 4-Channel Relay Module (controller + relays + power supply)  

### Option 2: Individual Components

| Component            | Quantity |
| -------------------- | -------- |
| Flow meter           | 1        |
| 4-channel relay      | 1        |
| ESP32                | 1        |
| AC → DC power supply | 1        |

---

## Enclosure
- IP65 or higher recommended (waterproof, dustproof, UV-resistant)  
- Use cable glands for all cable entries  

---

## Operation
1. Power on the system
2. ESP32 initializes and loads configuration 
3. Irrigation cycles begin automatically  
4. Zones activated based on flow limits  
5. Water consumption data is logged to the cloud dashboard 

---

## Documentation
For system architecture, data flow, firmware design and testing details, refer to the [Design & Prototype document](./docs/design-prototype.md).

---

## License
This project is licensed under the [MIT License](./LICENSE.md).