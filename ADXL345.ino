#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

// Create an instance of the ADXL345 sensor
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

void setup(void) {
  Serial.begin(115200);
  Wire.begin(21, 22); // SDA, SCL

  // Check if the ADXL345 is connected
  if (!accel.begin()) {
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while (1);
  }

  // Set the range to whatever is appropriate for your project
  accel.setRange(ADXL345_RANGE_16_G);
}

void loop(void) {
  sensors_event_t event;
  accel.getEvent(&event);

  // Display the accelerometer values
  Serial.print("X: "); Serial.print(event.acceleration.x); Serial.print(" ");
  Serial.print("Y: "); Serial.print(event.acceleration.y); Serial.print(" ");
  Serial.print("Z: "); Serial.print(event.acceleration.z); Serial.print(" ");
  Serial.println("m/s^2 ");

  delay(500);
}
