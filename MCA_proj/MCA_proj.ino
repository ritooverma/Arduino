#include <dht.h>


#define dht_apin A2 // Analog Pin sensor is connected to
 
dht DHT;

#include <Servo.h>

int sensorPin = A0;
int servoPin  = 9;

int sensorValue = 0;
int servoGrad = 90;
int tolerance = 10;

Servo myservo;

 
void setup(){
  pinMode( sensorPin, INPUT);
  myservo.attach( servoPin );
  myservo.write( servoGrad );
 
  Serial.begin(9600);
  delay(500);//Delay to let system boot
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);//Wait before accessing Sensor
 
}
 
void loop(){
  //Start of Program 
  
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  if ( sensorValue < (650-tolerance) )
  {
    if (servoGrad < 180) servoGrad++;
  }

  if ( sensorValue > (650+tolerance) )
  {
    if (servoGrad > 0) servoGrad--;
  }

  myservo.write( servoGrad ); 

  delay(100);
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(DHT.temperature); 
    Serial.println("C  ");
    
    delay(5000);//Wait 5 seconds before accessing sensor again.
 
  //Fastest should be once every two seconds.
 
}// end loop(
