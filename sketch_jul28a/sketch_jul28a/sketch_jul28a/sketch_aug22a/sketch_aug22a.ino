
 const int ledPin=13;
 const int buzzerPin=12;
 const int ldrPin=A0;
  void setup()
{
   Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 pinMode(ldrPin,INPUT);
 pinMode(buzzerPin,OUTPUT);
}

void loop() {
 int ldrStatus = analogRead(ldrPin);
/* Serial.println(ldrStatus);
 delay(500);*/
 if(ldrStatus >= 700)
{
  tone(buzzerPin,100);
  digitalWrite(ledPin,LOW);
  Serial.println("-----------------ALARM ACTIVATED----------------");
   delay(100);
  Serial.println(ldrStatus);
   delay(100);
}
else
{
  noTone(buzzerPin);
  digitalWrite(ledPin,HIGH);
  Serial.println("alarm deactivated");
  Serial.println(ldrStatus);
  delay(500);
  delay(500);
}

}
