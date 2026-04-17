🌡️ Temperature Based Fan Speed Controller

📌 Project Overview

This project is a smart temperature-controlled fan system built using Arduino. It automatically adjusts the fan speed based on surrounding temperature, helping maintain an optimal environment without manual intervention.

---

⚙️ Components Used

- Arduino Board
- Temperature Sensor (DHT11/DHT22)
- I2C LCD Display
- DC Fan / Motor
- Motor Driver Module (L298N or similar)
- Breadboard
- Connecting Wires
- USB Cable

---

🚀 Features

- Automatic fan speed control based on temperature
- Real-time temperature display on LCD
- Efficient energy usage
- Simple and low-cost implementation
- Compact and portable design

---

🔧 Working Principle

The temperature sensor continuously reads the ambient temperature and sends data to the Arduino. Based on predefined temperature thresholds, the Arduino adjusts the fan speed using PWM signals through the motor driver. The current temperature and system status are displayed on the I2C LCD.

---

📊 Functionality

- Low Temperature → Fan OFF / Low Speed
- Medium Temperature → Moderate Speed
- High Temperature → Maximum Speed

---

🔌 Circuit Description

- Temperature sensor connected to Arduino input pin
- Motor driver connected to control fan speed
- I2C LCD connected via SDA and SCL pins
- Power supplied through USB cable
- All components mounted on a breadboard

---

🧠 Applications

- Smart home cooling systems
- Automatic ventilation systems
- Electronic device cooling
- Industrial temperature control

---

📈 Future Improvements

- Add IoT monitoring (WiFi/Bluetooth)
- Mobile app control
- More precise sensors
- Auto calibration system

---

📷 Output

Displays real-time temperature and adjusts fan speed accordingly.

---
