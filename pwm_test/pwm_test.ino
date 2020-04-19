int P1=4;
int P2=7;
int pwm = 5;

void setup() {
// int P1=4;
// int P2=7;
 //int pwm = 5;
 pinMode(P1,OUTPUT);
 pinMode(P2,OUTPUT);
 pinMode(pwm,OUTPUT);
 Serial.begin(115200);
 
}

void loop() {
 for(int i=0; i<255; i++)
{
  digitalWrite(P1,LOW);
  //digitalWrite(P2,HIGH);
  Serial.println(i);
  analogWrite(pwm, i);
  delay(5); 
}
 for(int i=255; i>0; i--)
{
 // digitalWrite(P1,HIGH);
  digitalWrite(P2,LOW);
  Serial.println(i);
  analogWrite(pwm, i);
  delay(5); 
}
}
