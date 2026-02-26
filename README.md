# Smart-Accident-Detection-Emergency-Alert-System# 🪖 Smart Helmet 2.0 – IoT Based Accident Detection System

An IoT-based Smart Helmet system designed to reduce road accident fatalities by detecting crashes and automatically sending emergency alerts with live GPS location.

---

## 🚀 Features

- 🚨 Accident Detection using MPU6050
- 🍺 Alcohol Detection using MQ-3 Sensor
- 📍 Live GPS Location Tracking
- 📩 Automatic SMS Alert via GSM Module
- 🔔 Buzzer Alert System
- 🔌 ESP32 Microcontroller

---

## 🧠 Working Principle

1. MPU6050 detects sudden acceleration (impact).
2. If impact exceeds threshold → Accident detected.
3. GPS module retrieves current coordinates.
4. GSM module sends SMS with Google Maps location link.
5. MQ-3 checks for alcohol level.
6. Buzzer activates for warning.

---

## 🛠 Hardware Components

- ESP32
- MPU6050 (Accelerometer + Gyroscope)
- MQ-3 Alcohol Sensor
- NEO-6M GPS Module
- SIM800L GSM Module
- Buzzer
- Power Supply (Battery)

---

## 🔌 Pin Configuration (ESP32)

| Component | ESP32 Pin |
|------------|------------|
| MPU6050 SDA | 21 |
| MPU6050 SCL | 22 |
| MQ-3 | 34 |
| Buzzer | 25 |
| GPS TX | 16 |
| GPS RX | 17 |
| GSM TX | 26 |
| GSM RX | 27 |

---

## ⚙️ Software Requirements

- Arduino IDE
- ESP32 Board Package
- Required Libraries:
  - Adafruit MPU6050
  - TinyGPS++
  - Adafruit Sensor

---

---

## 🎯 Applications

- Road Safety
- Emergency Response System
- Drunk Driving Prevention
- Smart Transportation

---

## 🚀 Future Improvements

- Helmet Wearing Detection
- Ignition Lock System
- Cloud Dashboard Integration
- Mobile App Monitoring
- Fall Detection Delay Confirmation

---

## 👨‍💻 Developed By

Achuthan Rameshkumar  
IoT & Full Stack Developer  

---

## 📜 License

This project is for academic and research purposes.

## 📩 SMS Format
