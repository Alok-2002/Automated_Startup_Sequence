# ⏱️ Time-Delay Based Sequential Startup System (Arduino Uno)

![Arduino](https://img.shields.io/badge/Platform-Arduino-blue?logo=arduino)
![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)
![Made With C++](https://img.shields.io/badge/Made%20with-C++-1f425f.svg)
![Status](https://img.shields.io/badge/Status-Prototype-green)
![Project Type](https://img.shields.io/badge/Application-Defense-lightgrey)

---

This project implements a **real-time sequential startup and shutdown system** using an **Arduino Uno** and a **relay module**, designed during an internship at the **Indian Air Force**. The system mimics part of a real-world aircraft startup sequence for educational and simulation purposes. This prototype model uses relays to represent components such as motors, fuel pumps, and sensors.

> ⚠️ *This system is inspired by aircraft startup logic but does not directly mention or replicate classified or proprietary systems.*

---

## 📌 Key Features

* Time-based sequential control of simulated components
* Toggle switch to initiate a single startup cycle
* Serial output logs for debugging and monitoring
* LED blink indicating sequence completion
* Realistic relay-based simulation of key startup actions

---

## 🧩 Components Used

| Component                   | Quantity | Description / Function                    |
| --------------------------- | -------- | ----------------------------------------- |
| Arduino Uno                 | 1        | Microcontroller board                     |
| 5-Channel Relay Module      | 1        | Used to control simulated devices         |
| LED Strip (for visual cues) | 1        | Connected to relays to show device status |
| 1kΩ Resistor                | 1        | Current limiting resistor for onboard LED |
| DC Power Supply             | 1        | For Arduino and relay module              |
| Pushbutton / Toggle Switch  | 1        | Starts the system sequence (active LOW)   |

### 🔌 Relay Mappings (Load Simulations)

| Arduino Pin | Relay Label             | Simulated Component (Shown via LED Strip) |
| ----------- | ----------------------- | ----------------------------------------- |
| D3          | relay\_9                | Generator Speed Sensor (9)                |
| D4          | relay\_power\_indicator | Power Indicator (39)                      |
| D5          | relay\_10               | Starter Speed Sensor (10)                 |
| D6          | relay\_fuel\_pump       | Fuel Pump                                 |
| D8          | relay\_13               | Electric Motor (13)                       |
| D13         | led1                    | Status LED                                |

---

## 🧪 Serial Monitor Output (Sample)

```
System Initialized: Toggle switch to start...
Switch Toggled ON: Waiting 4 seconds before starting...
Sequence Started: Motor (13) and Fuel Pump turned ON.
2s: Generator Speed Sensor (9) turned ON.
14.5s: Motor (13) turned OFF.
14.5s: Power Indicator (39) turned ON.
20.5s: Starter Speed Sensor (10) turned ON.
38s: Fuel Pump turned OFF.
38s: Status LED blinked once.
Sequence complete. Toggle switch OFF then ON to restart.
```

---

## 🖼️ Circuit Diagram

![flowchart](https://github.com/user-attachments/assets/90de85cf-58fb-4020-9f5c-8be6da980612)


> This Fritzing-based diagram shows relay wiring and LED strip placement used for simulating signals.

---

## 👨‍💻 Team Members

This project was developed as a team of three during a technical internship:

* **Atul Sharma** — System Integration, Firmware Development
* **Sanskriti Yadav** — Circuit Prototyping and Component Wiring
* **Akash yadav** — Testing, Debugging, and Documentation

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).

---

## 🤝 Acknowledgements

* Indian Air Force for providing the internship opportunity and domain exposure
* Arduino community for open-source libraries and development tools

---

## 📦 Repository Structure

```
📁 startup-sequence-arduino
├── README.md
├── Code.ino
└── LICENSE
```

---

For further enhancements, consider:

* Adding real motor control instead of LED indicators
* Expanding with LCD display or buzzer for real-time feedback
* Integrating a reset button or start indicator light

---

> 👨‍🏭 Built with care, safety, and precision during defense sector prototyping.
