 int sensorval;
void setup() {
 Serial.begin(9600);

}

void loop() {
  sensorval = analogRead(A0);
  Serial.println(sensorval);
  delay(1000);
}
