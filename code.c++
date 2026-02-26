#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <TinyGPS++.h>
#include <HardwareSerial.h>

Adafruit_MPU6050 mpu;
TinyGPSPlus gps;

// GSM uses Serial2
HardwareSerial gsm(2);
HardwareSerial gpsSerial(1);

#define MQ3_PIN 34
#define BUZZER  25

float impactThreshold = 18.0;   // Adjust after testing

void setup() {
  Serial.begin(115200);

  pinMode(MQ3_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);

  // MPU6050 setup
  if (!mpu.begin()) {
    Serial.println("MPU6050 not found");
    while (1);
  }

  // GPS
  gpsSerial.begin(9600, SERIAL_8N1, 16, 17);

  // GSM
  gsm.begin(9600, SERIAL_8N1, 26, 27);

  delay(2000);
  Serial.println("Smart Helmet System Ready");
}

void loop() {

  // 🔹 Accident Detection
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  float totalAccel = sqrt(
    a.acceleration.x * a.acceleration.x +
    a.acceleration.y * a.acceleration.y +
    a.acceleration.z * a.acceleration.z
  );

  if (totalAccel > impactThreshold) {
    Serial.println("Accident Detected!");
    digitalWrite(BUZZER, HIGH);
    delay(3000);
    digitalWrite(BUZZER, LOW);

    sendEmergencySMS();
  }

  // 🔹 Alcohol Detection
  int alcoholValue = analogRead(MQ3_PIN);
  if (alcoholValue > 2000) {   // adjust after testing
    Serial.println("Alcohol Detected!");
    digitalWrite(BUZZER, HIGH);
  }

  // GPS Reading
  while (gpsSerial.available()) {
    gps.encode(gpsSerial.read());
  }

  delay(500);
}

void sendEmergencySMS() {

  String latitude = "0";
  String longitude = "0";

  if (gps.location.isValid()) {
    latitude = String(gps.location.lat(), 6);
    longitude = String(gps.location.lng(), 6);
  }

  String message = "Accident Alert! Location: https://maps.google.com/?q=" + latitude + "," + longitude;

  gsm.println("AT+CMGF=1");
  delay(1000);

  gsm.println("AT+CMGS=\"+91XXXXXXXXXX\"");  // Replace with phone number
  delay(1000);

  gsm.print(message);
  delay(1000);

  gsm.write(26);  // CTRL+Z to send
  delay(5000);

  Serial.println("SMS Sent");
}
