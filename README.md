# Reticulation Controller

## Overview
An ESP32-based irrigation controller that monitors water usage per zone and automatically shuts off solenoid valves when preset limits are reached.

---

## Features
- Per-zone water usage limits  
- Automatic solenoid shutoff  
- Remote monitoring via online dashboard  

---

## Hardware Options

### Option 1: Integrated Board
- ESP32 AC/DC Wi-Fi 4-Channel Relay Module  
- Combines controller, relays, and power supply  

### Option 2: Individual Components

| Component            | Quantity |
| -------------------- | -------- |
| Flow meter           | 4        |
| 4 Channel relay      | 1        |
| ESP32                | 1        |
| AC → DC power supply | 1        |

**Notes:** Buck converter only needed if voltage conversion required; 3.3V logic components do not require level shifting.

---

## Enclosure
- IP65 or higher, waterproof, dustproof, UV-resistant  
- Use cable glands for all cable entries  

---

## Installation
1. Connect components  
2. Configure power supply  
3. Upload firmware  
4. Calibrate flow meters  
5. Configure usage limits  
6. Test valve operation  
7. Set up dashboard  

---

## Usage
1. Power on the ESP32  
2. Configure limits via dashboard (or local controls if implemented)  
3. System operates automatically  

---

## Documentation
For system architecture, data flow, protocols, and testing details, refer to the **Design & Prototype document**.

---

## License
This project is licensed under the [MIT License](LICENSE.md).