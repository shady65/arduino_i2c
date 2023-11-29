#include <Wire.h>
#include <Arduino.h>

void sendData();
// Define the struct
struct SensorData {
  // Data from 1 Gps sensor
  // float cc;
  float gpsLatitude;
  float gpsLongitude;

  // // Data from 1 IMU with 4 readings
  float imuAccX;
  float imuAccY;
  float imuAccZ;
  float imuGyro;

  // // Data from 2 ultrasonic sensors (1 reading each)
  float ultrasonic1;
  float ultrasonic2;
};

// Set the I2C address
const int I2C_ADDRESS = 0x30;  // Choose a unique address for your device

// Initialize a SensorData object
SensorData sensorData;

void setup() {
  Serial.begin(9600);  // Set the baud rate to match your Serial Monitor
  Wire.begin(I2C_ADDRESS);  // Initialize I2C with the specified address
  Serial.print("waiting");
  Wire.onRequest(sendData);  // Set the function to call when data is requested
}

void loop() {
  // Update the sensor data (replace this with your actual sensor data)
  // sensorData.cc = 11.11;


  sensorData.gpsLatitude = 5;  // Example latitude
  sensorData.gpsLongitude = -122.4194;  // Example longitude

  sensorData.imuAccX = 1.2;  // Example accelerometer X reading
  sensorData.imuAccY = 2.3;  // Example accelerometer Y reading
  sensorData.imuAccZ = 9.8;  // Example accelerometer Z reading
  sensorData.imuGyro = 45.6;  // Example gyroscope reading

  sensorData.ultrasonic1 = 20.5;  // Example reading from ultrasonic sensor 1
  sensorData.ultrasonic2 = 15.3;  // Example reading from ultrasonic sensor 2


  delay(1000);  // Delay added for demonstration purposes

}

// Function to send data when requested by the master
void sendData() {
  // Send the struct through I2C
  Wire.write((uint8_t*)&sensorData, sizeof(sensorData));
}
