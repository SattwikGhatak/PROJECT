const int topSensorPin = 2;      // IR sensor at the top of the tank
const int bottomSensorPin = 3;   // IR sensor at the bottom of the tank
const int LED = 4;               // LED for the alert
const int sludgeThreshold = 20;  // Threshold distance in centimeters
const int triggerDistance = 50;  // Distance to trigger the alert

void setup() {
  pinMode(topSensorPin, INPUT);
  pinMode(bottomSensorPin, INPUT);
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

int measureSludgeDistance(int sensorPin) {
  // Variables to hold the sensor values
  int sensorSum = 0;
  int sensorCount = 10;  // Number of readings

  for (int i = 0; i < sensorCount; i++) {
    int sensorValue = digitalRead(sensorPin);
    sensorSum += sensorValue;
    delay(10);  // Delay between readings
  }

  // Calculate the average sensor value
  int averageSensorValue = sensorSum / sensorCount;
  int distance = map(averageSensorValue, 0, 1023, 0, 50); 

  return distance;
}

void loop() {
  int topSensorValue = digitalRead(topSensorPin);
  int bottomSensorValue = digitalRead(bottomSensorPin);

  if (bottomSensorValue == LOW && topSensorValue == HIGH) {
    int sludgeDistance = measureSludgeDistance(bottomSensorPin);
    Serial.print("Sludge level distance: ");
    Serial.print(sludgeDistance);
    Serial.println(" cm");

    if (sludgeDistance <= triggerDistance) {
      // Sludge level has crossed the threshold
      digitalWrite(LED, HIGH); // Turn on the LED
      Serial.println("Sludge level is high. Clean the tank!");
    } else {
      digitalWrite(LED, LOW); // Turn off the LED
      Serial.println("Sludge level is normal.");
    }
  } else {
    digitalWrite(LED, LOW); // Turn off the LED
    Serial.println("Sludge level is normal.");
  }

  delay(1000); // Delay
}
