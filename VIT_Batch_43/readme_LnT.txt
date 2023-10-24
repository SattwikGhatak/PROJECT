Sludge Level Monitoring System for Water Tanks

Overview
This project aims to create a reliable and cost-effective system for monitoring the sludge level in a water tank. The system alerts the user when the sludge level exceeds a predefined threshold, indicating the need for cleaning. It provides real-time feedback through a visual alert using an LED indicator. This system is designed to be interfaced with an Arduino microcontroller and allows users to customize the sludge threshold value.


Components

Hardware Components
Arduino Uno R3: Microcontroller board.
Infrasonic Sensor: Measures sludge level in the tank.
LED: Visual indicator for sludge level alert.
Resistor: Limits current flow to the LED.
Breadboard and Jumper Wires: Used for circuit connections.
Power Supply for Arduino: Powers the Arduino board.

Software Components
Arduino IDE: Used for programming the Arduino board.

Wiring Instructions
IR Sensor Connections:

VCC (IR Sensor) -> 5V (Arduino)
GND (IR Sensor) -> GND (Arduino)
Top (IR Sensor) -> Pin 2 (Arduino)
Bottom (IR Sensor) -> Pin 3 (Arduino)
LED Connections:
Anode  -> Resistor -> Pin 4 (Arduino)
Cathode -> GND (Arduino)

Explanation
The microcontroller checks for the level of sludge based on the defined threshold value. 
If the sludge level is below the lower IR sensor, or if it is between the lower and the upper 
sensors, The sludge level is normal and the same is printed. When it crosses the upper sensor, the LED glows and cleaning alert is given. 

Limitations
Accuracy: Depends on the precision of the sensor; may not be suitable for very large or irregularly shaped tanks.
Alert Type: Provides visual alert (LED) only; no remote notifications.
User Adjustment: Users need to manually adjust the sludge threshold value in the code.

Sattwik Ghatak
21BEC1373
VIT Chennai 