const int ledpin = 9;
void setup()
{
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() 
{
 double sensorval = analogRead(A0);
 sensorval = (sensorval*255)/1023;
 analogWrite(9,sensorval);
 Serial.println(sensorval);
 delay(1000);
}
