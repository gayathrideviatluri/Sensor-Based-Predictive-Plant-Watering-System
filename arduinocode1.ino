#define RELAY_PIN 7
#define MOISTURE_SENSOR_PIN A0
#define TEMP_SENSOR_PIN A1
#define LED_PIN 8

// Threshold values
const int MOISTURE_THRESHOLD = 500; // Adjust as needed
const float TEMPERATURE_THRESHOLD = 25.0; // Temperature threshold in Celsius

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Read sensor data
  int moisture = analogRead(MOISTURE_SENSOR_PIN);
  float temp_voltage = analogRead(TEMP_SENSOR_PIN) * (5.0 / 1023.0);
  float temperature = (temp_voltage - 0.5) * 100; // Convert voltage to temperature in Celsius
  
  // Display sensor readings
  Serial.print("Moisture: ");
  Serial.println(moisture);
  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  // Control the motor based on sensor readings
  if (moisture < MOISTURE_THRESHOLD && temperature > TEMPERATURE_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH); // Turn on motor
    digitalWrite(LED_PIN, HIGH); // Turn on LED for indication
    Serial.println("Motor turned ON");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Turn off motor
    digitalWrite(LED_PIN, LOW); // Turn off LED
    Serial.println("Motor turned OFF");
  }
  
  delay(1000); // Adjust delay as needed
}
