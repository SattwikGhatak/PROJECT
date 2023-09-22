const int sensor1Pin = 2; // IR sensor 1 pin
const int sensor2Pin = 3; // IR sensor 2 pin
const int ledPin = 4;     // LED pin
//const int buzzerPin = 5;  // Buzzer pin
const int sludgeThreshold = 100; // Adjust this threshold as needed

void setup() {
  pinMode(sensor1Pin, INPUT);
  pinMode(sensor2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  //pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int sensor1Value = digitalRead(sensor1Pin);
  int sensor2Value = digitalRead(sensor2Pin);

  if (sensor1Value == LOW || sensor2Value == LOW) {
    digitalWrite(ledPin, HIGH);
    //digitalWrite(buzzerPin, HIGH);
    Serial.println("Sludge level is high. Clean the tank!");
  } else {
    digitalWrite(ledPin, LOW);
    //digitalWrite(buzzerPin, LOW);
    Serial.println("Sludge level is normal.");
  }

  delay(1000); // Delay for a while to avoid rapid alerts
}
