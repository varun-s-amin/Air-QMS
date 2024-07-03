#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <MQ135.h>

char auth[] = "your_blynk_auth_token";  // Your Blynk authentication token n
char ssid[] = "your_wifi_ssid";    // Your Wi-Fi SSID
char pass[] = "your_wifi_password";    // Your Wi-Fi password
BlynkTimer timer;

#define DHT_PIN_DATA 0  // Digital pin for DHT11
#define DHT_TYPE DHT11
#define MQ135_PIN_AOUT 12  // Analog pin for MQ135
#define PIN_MQ135 14

DHT dht(DHT_PIN_DATA, DHT_TYPE);
MQ135 mq135_sensor(PIN_MQ135);

int gasThreshold = 300;
int temperatureThreshold = 25;
float temperature = 21.0; // Assume current temperature. Recommended to measure with DHT22
float humidity = 25.0; // Assume current humidity. Recommended to measure with DHT22

void sendSensorData() {
  // Read temperature and humidity from DHT11
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  // Read gas sensor data from MQ135
  float rzero = mq135_sensor.getRZero();
  float correctedRZero = mq135_sensor.getCorrectedRZero(t, h);
  float resistance = mq135_sensor.getResistance();
  float ppm = mq135_sensor.getPPM();
  float correctedPPM = mq135_sensor.getCorrectedPPM(t, h);

  // Send sensor data to Blynk app
  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);
  Blynk.virtualWrite(V2, ppm);

  // Print sensor data to Serial
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" °C, Humidity: ");
  Serial.print(h);
  Serial.print(" %, MQ135 PPM: ");
  Serial.print(ppm);
  Serial.println(" ppm");

  // Check for temperature threshold
  if (t > temperatureThreshold) {
    Blynk.notify("High Temperature Alert! Temperature is " + String(t) + "°C");
    Blynk.email("your_email@example.com", "High Temperature Alert", "Temperature is " + String(t) + "°C");
  }

  // Check for gas threshold
  if (ppm > gasThreshold) {
    Blynk.notify("Bad Air Quality Alert! PPM is " + String(ppm));
    Blynk.email("your_email@example.com", "Bad Air Quality Alert", "PPM is " + String(ppm));
  }
}

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);
  // Initialize Blynk with auth, Wi-Fi credentials, and server details
  Blynk.begin(auth, ssid, pass, IPAddress(117, 236, 190, 213), 8080);
  // Initialize DHT11 sensor
  dht.begin();
  // Set up a timer to call sendSensorData every 30 seconds
  timer.setInterval(30000L, sendSensorData);
}

void loop() {
  // Run Blynk framework and timer
  Blynk.run();
  timer.run();
}
