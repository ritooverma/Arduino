
 const int ledPin=13;
 const int buzzerPin=12;
// const int ldrPin=A0;
  void setup()
{
   Serial.begin(9600);
 pinMode(ledPin,OUTPUT);
 //pinMode(ldrPin,INPUT);
 pinMode(buzzerPin,OUTPUT);
}

void loop() {
 int ldrStatus = analogRead(A0);
 if(ldrStatus >=200 && ldrStatus<=400)
{
 tone(buzzerPin,10);
 digitalWrite(ledPin,LOW);
 Serial.println("-----------------ALARM ACTIVATED lvl-1-----------------");
 delay(100);
 Serial.println(ldrStatus);
 delay(100);
}
else if(ldrStatus >400 && ldrStatus<=600)
{
 tone(buzzerPin,100);
 digitalWrite(ledPin,LOW);
 Serial.println("-----------------ALARM ACTIVATED----------------");
 delay(100);
 Serial.println(ldrStatus);
 delay(100);
}
else if(ldrStatus >600 && ldrStatus<=800)
{
 tone(buzzerPin,1);
 digitalWrite(ledPin,LOW);
 Serial.println("-----------------ALARM ACTIVATED----------------");
 delay(100);
 Serial.println(ldrStatus);
 delay(100);
}
else if(ldrStatus >800 && ldrStatus<=1000)
{
 tone(buzzerPin,2500);
 digitalWrite(ledPin,LOW);
 Serial.println("-----------------ALARM ACTIVATED----------------");
 delay(100);
 Serial.println(ldrStatus);
 delay(100);
}
else if(ldrStatus >1000 && ldrStatus<=1200)
{
 tone(buzzerPin,25000);
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
