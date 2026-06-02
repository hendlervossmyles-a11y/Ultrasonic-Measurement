// Credits:
// Rachel De Barros for major contributions to the code.

const int trigPin = 11; // Defines where the trig pin will recieve inputs to emit a pulse.
const int echoPin = 10; // // Defines where data from the echo pin will be directed.

float duration; // variable to store pulse duration
float distanceCM; // variable to store distance in CM
float distanceIN; // variable to store distance in IN

void setup() {
  Serial.begin(9600); // Starts serical comunication, so output data can be read from the Serial Monitor
  pinMode(trigPin, OUTPUT); // Defines the Trig Pin as an Output
  pinMode(echoPin, INPUT); // Defines the Echo Pin as a Input
}

void loop() {
  // start with a clean signal
  digitalWrite(trigPin, LOW); // Turns off the trigger pin temporally to prevent a continious trigger.
  delayMicroseconds(2); // Delays the tirgger by 2 microseconds to prevent errors
  // send trigger signal
  digitalWrite(trigPin, HIGH); // Triggers the sensor to emit a sound wave
  delayMicroseconds(10); // Delays the sensor by 10 microseconds to keep the sensor emmitting waves.
  digitalWrite(trigPin, LOW); // Turns off the sensor
  // return pulse duration in microseconds
  // if set to HIGH, pulseIn() waits for the pin to go from LOW to HIGH
  // stops timing when pin goes back LOW
  duration = pulseIn(echoPin, HIGH); // Times how long it takes the echo pin or reciever to set to high. (Recieve a signal back)
  // convert m/s to cm/microsecond
  // 343 m/s = .034 cm/microseconds
  distanceCM = (duration * 0.034) / 2; // convert to inches, 1in = 2.54cm
  distanceIN = distanceCM / 2.54; // print distance to Serial Monitor

  // Printing Results to the serial monitor.
  Serial.print("Distance: ");
  Serial.print(distanceCM);
  Serial.print(" cm | ");
  Serial.print(distanceIN);
  Serial.println(" in");

  delay(300); // Delays the code 300 microseconds before taking another measurement.
}