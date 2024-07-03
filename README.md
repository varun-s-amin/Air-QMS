# Air Quality and Temperature Monitoring System

## Overview
This project is an Air Quality and Temperature Monitoring System using an ESP32, MQ135 gas sensor, DHT11 temperature and humidity sensor, and Blynk platform. The system measures air quality (in terms of PPM), temperature, and humidity, and sends this data to a Blynk app for real-time monitoring. Additionally, the system sends notifications and emails if the air quality or temperature exceeds predefined thresholds.

## Components Used
- **ESP32**: A low-cost, low-power system on a chip microcontroller with integrated Wi-Fi and Bluetooth capabilities.
- **MQ135**: A gas sensor used for detecting a variety of gases including NH3, NOx, alcohol, Benzene, smoke, CO2, etc. It is primarily used for monitoring air quality.
- **DHT11**: A digital sensor used for measuring temperature and humidity.
- **Blynk**: A platform for IoT apps that allows users to build mobile and web applications to control and monitor hardware devices remotely.

## Blynk Version
- **Blynk Version 1**: The original version of the Blynk app used for creating IoT projects.

## Circuit Diagram

### Connect the DHT11 sensor to the ESP32:
- VCC to 3.3V
- GND to GND
- Data pin to GPIO 0

### Connect the MQ135 sensor to the ESP32:
- AOUT pin to GPIO 12
- Other necessary connections according to the datasheet.

## Project Setup

### Prerequisites
1. **Arduino IDE**: Download and install the latest version of the Arduino IDE from [here](https://www.arduino.cc/en/Main/Software).
2. **Blynk Library**: Install the Blynk library in the Arduino IDE. You can do this by going to `Sketch` -> `Include Library` -> `Manage Libraries...` and searching for "Blynk".
3. **DHT Library**: Install the DHT sensor library in the Arduino IDE.
4. **MQ135 Library**: Install the MQ135 sensor library from [GeorgK's GitHub repository](https://github.com/GeorgK/MQ135).

## Blynk App Setup
1. **Create a new project** in the Blynk app.
2. **Add widgets** to the project:
   - **Gauge** for Temperature (Virtual Pin V0)
   - **Gauge** for Humidity (Virtual Pin V1)
   - **Gauge** for Air Quality (Virtual Pin V2)
3. **Configure notifications and emails** in the app settings.

## Working
1. **Initialization**: The ESP32 connects to the Wi-Fi network and initializes the DHT11 and MQ135 sensors.
2. **Data Collection**: The `sendSensorData` function reads data from the DHT11 and MQ135 sensors every 30 seconds.
3. **Data Transmission**: The collected data is sent to the Blynk app for real-time monitoring.
4. **Alerts**: If the temperature exceeds 25°C or the air quality exceeds 300 PPM, notifications and emails are sent to alert the user.

## Need for This Project
Monitoring air quality and temperature is crucial for ensuring a healthy and safe environment. Poor air quality can lead to respiratory problems and other health issues. High temperatures can also be harmful, especially in certain environments. This project provides a simple and effective way to monitor these parameters remotely and receive alerts in case of dangerous conditions, helping to take timely actions to maintain a safe environment.

## Conclusion
This project demonstrates the integration of sensors with an IoT platform to create a smart monitoring system. It is a practical application of IoT, providing real-time monitoring and alerts to ensure safety and health. By using the ESP32, MQ135, DHT11, and Blynk platform, we have created a cost-effective solution for air quality and temperature monitoring.
