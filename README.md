# Smart Bus Occupancy Monitoring System

## Overview

Smart Bus Occupancy Monitoring System is an IoT-based solution designed to monitor seat occupancy inside a bus in real time using ESP32 and Blynk. The system detects occupied and available seats, calculates occupancy percentage, displays remaining seat capacity, and sends alerts when the bus reaches a critical occupancy level.

This project aims to improve passenger comfort and support smarter public transportation management through real-time monitoring.

---

## Features

### Real-Time Seat Monitoring

* Monitor 4 bus seats simultaneously.
* Detect occupied and empty seats using analog sensors.

### Occupancy Calculation

* Calculate total occupied seats.
* Calculate available seats.
* Display occupancy percentage automatically.

### Visual Indicators

* Physical LED indicator for each seat.
* Dashboard LED indicators in Blynk application.

### Smart Warning System

* Automatic warning when bus occupancy reaches 80% or higher.
* Buzzer notification activated once per warning event.
* Warning message displayed on dashboard.

### Remote Monitoring

* Monitor seat status from smartphone using Blynk.
* Access occupancy information remotely via internet connection.

---

## Technologies Used

### Hardware

* ESP32 DevKit V1
* 4 Analog Seat Sensors (simulated using potentiometers)
* 4 LEDs
* Buzzer
* Breadboard
* Jumper Wires

### Software

* Arduino IDE
* ESP32 Framework
* Blynk IoT Platform
* Wokwi Simulator

### Libraries

* Blynk
* WiFi
* BlynkTimer

---

## System Architecture

Seat Sensors
↓
ESP32
↓
Occupancy Processing
↓
Blynk Cloud
↓
Mobile Dashboard

Additional Outputs:

* Physical LEDs
* Dashboard LEDs
* Buzzer Alert

---

## Pin Configuration

| Component     | ESP32 Pin |
| ------------- | --------- |
| Seat Sensor 1 | GPIO 33   |
| Seat Sensor 2 | GPIO 32   |
| Seat Sensor 3 | GPIO 35   |
| Seat Sensor 4 | GPIO 34   |
| LED Seat 1    | GPIO 13   |
| LED Seat 2    | GPIO 12   |
| LED Seat 3    | GPIO 14   |
| LED Seat 4    | GPIO 27   |
| Buzzer        | GPIO 26   |

---

## Blynk Dashboard Mapping

| Virtual Pin | Function                |
| ----------- | ----------------------- |
| V0          | Seat 1 Status           |
| V1          | Seat 2 Status           |
| V2          | Seat 3 Status           |
| V3          | Seat 4 Status           |
| V4          | Occupancy Percentage    |
| V5          | Warning Status          |
| V6          | Remaining Seats         |
| V7          | Buzzer Indicator        |
| V8          | Seat 1 Availability LED |
| V9          | Seat 2 Availability LED |
| V10         | Seat 3 Availability LED |
| V11         | Seat 4 Availability LED |

---

## System Workflow

1. ESP32 reads analog values from seat sensors.
2. Sensor values above threshold indicate occupied seats.
3. LEDs turn on for occupied seats.
4. Seat status is sent to Blynk dashboard.
5. Occupancy percentage is calculated.
6. Remaining seats are calculated.
7. If occupancy reaches 80% or more:

   * Warning message appears.
   * Buzzer activates once.
   * Warning indicator is enabled.
8. Data is continuously updated every 500 ms.

---

## Results

The system successfully:

* Detects occupied and empty seats.
* Calculates occupancy percentage automatically.
* Displays remaining seat capacity.
* Sends real-time updates to Blynk dashboard.
* Activates warning alerts when bus capacity is nearly full.

---

## Future Improvements

* Replace potentiometers with actual pressure sensors.
* Add GPS tracking for bus location monitoring.
* Implement cloud database storage.
* Develop occupancy prediction using Machine Learning.
* Add passenger counting analytics dashboard.

---

## Author

Mochammad Yuga Ranapraja

Informatics Student
Junior Data Science Intern at Vinix7
