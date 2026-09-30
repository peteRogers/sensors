

void setup() {
  Serial.begin(9600);
}

void loop() {
  int sensorReading = analogRead(A0);
  int thisPitch = map(sensorReading, 0, 900, 5000, 0);
  thisPitch = constrain(thisPitch, 0, 5000);
  Serial.println(sensorReading);
  // play the pitch:
  tone(9, thisPitch);
  delay(2);  // delay in between reads for stability
  noTone(9);
  delay(150);
}
