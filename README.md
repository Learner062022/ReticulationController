# Reticulation Controller

## Overview
An ESP32-based irrigation controller that monitors total water usage via a flow meter and automatically shuts off solenoid valves when preset per-zone limits are reached.

---

## Features
- Per-zone water usage limits (software-managed)  
- Automatic solenoid shutoff  
- Centralized flow tracking via single flow meter  
- Remote monitoring via online dashboard  

---

## Hardware Options

### Option 1: Integrated Board
- ESP32 AC/DC Wi-Fi 4-Channel Relay Module  
- Combines controller, relays, and power supply  

### Option 2: Individual Components

| Component            | Quantity |
| -------------------- | -------- |
| Flow meter           | 1        |
| 4-channel relay      | 1        |
| ESP32                | 1        |
| AC → DC power supply | 1        |

**Notes:** Buck converter only required if voltage conversion is needed. ESP32 GPIO operates at 3.3V logic.

---

## Enclosure
- IP65 or higher recommended (waterproof, dustproof, UV-resistant)  
- Use cable glands for all cable entries  

---

## Installation
1. Connect components  
2. Configure power supply  
3. Upload firmware  
4. Calibrate flow meter  
5. Configure per-zone usage limits  
6. Test valve operation  
7. Set up dashboard  

---

## Usage
1. Power on the ESP32  
2. Configure zone limits via dashboard (or local controls if implemented)  
3. System operates automatically based on flow usage tracking  

---

## Documentation
For system architecture, data flow, protocols, and testing details, refer to the **Design & Prototype document**.

---

## License
This project is licensed under the MIT License.