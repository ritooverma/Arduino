const int trigPin = 2;  
const int echoPin = 3;
long duration;
int distance;

#include <Servo.h>
 Servo myservo; 
 int pos = 0; 
 
void setup()
{
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT); 
 Serial.begin(9600);
 myservo.attach(9); 
 void ultra();
}

void loop()
{
 for (pos = 0; pos <= 180; pos += 10) 
 {
  myservo.write(pos);
  ultra();
 }
     
 for (pos = 180; pos >= 0; pos -= 10) 
 { 
  myservo.write(pos);
  ultra();                      
 }
}

void ultra()
{
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH);
 distance= duration*0.034/2;
 Serial.print("Distance: ");
 Serial.println(distance);
 Serial.print("Angle: ");
 Serial.println(pos);
 delay(500);
}

