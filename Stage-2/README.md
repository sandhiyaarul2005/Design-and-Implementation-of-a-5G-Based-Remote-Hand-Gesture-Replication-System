# Stage–2: Ultrasonic Sensor Data Transmission over 5G Infrastructure

## Overview

Stage–2 focuses on the implementation of real-time ultrasonic sensor data acquisition and its end-to-end transmission through a 5G communication framework. This phase demonstrates the integration of embedded sensing with 5G networking and edge computing infrastructure to validate low-latency data transfer capabilities.

The objective of this stage was to establish a complete data path from the sensing node to the receiver system through the 5G core and Multi-access Edge Computing (MEC) environment.

---

## System Workflow

The implemented workflow follows a structured communication pipeline:

1. **Sensor Interfacing and Data Acquisition**
   - An ultrasonic distance sensor was interfaced with the ESP32 microcontroller.
   - Real-time distance measurements were acquired using Embedded C programming.
   - Time-of-flight principles were used to compute object distance.

2. **Wi-Fi Connectivity to 5G CPE**
   - The ESP32 was configured to connect via Wi-Fi to a 5G Customer Premises Equipment (CPE).
   - Sensor data was transmitted wirelessly from the ESP32 to the 5G CPE.

3. **Integration with 5G Core Network**
   - The 5G CPE functioned as a gateway to the 5G Standalone (SA) core network.
   - Sensor data packets were forwarded into the 5G communication infrastructure.

4. **MEC Server Data Handling**
   - The transmitted data was routed to a Multi-access Edge Computing (MEC) server.
   - Low-latency processing and data handling were performed at the edge layer.
   - This minimized end-to-end transmission delay.

5. **Receiver-Side Evaluation**
   - The processed or relayed data from the MEC server was transmitted to a receiver-side evaluation board.
   - End-to-end data transmission was validated through real-time monitoring.

---

## Technical Components

- Ultrasonic Distance Sensor
- ESP32 Microcontroller
- Embedded C Firmware
- 5G Customer Premises Equipment (CPE)
- 5G Standalone Core Network
- Multi-access Edge Computing (MEC) Server
- Receiver Evaluation Board

---

## Performance Focus

The system was evaluated based on:

- End-to-End Latency
- Uplink Transmission Stability
- Packet Delivery Consistency
- Edge Processing Responsiveness
- Real-Time Data Continuity

---

## Inference

The successful transmission of ultrasonic sensor data across the 5G core network and MEC infrastructure validates the feasibility of using 5G for distributed sensing applications. The architecture demonstrates reliable end-to-end communication with reduced latency, making it suitable for real-time monitoring, teleoperation, and edge-assisted control systems.

This stage establishes the communication backbone required for implementing advanced real-time gesture transmission and actuation systems in subsequent phases of the project.
