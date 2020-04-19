int LED = 13; // Use the onboard Uno LED
int obstaclePin = 7;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.begin(9600);  
}
void loop() {
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  if (hasObstacle == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Stop something is ahead!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
  }
  else
  {
    Serial.println("Path is clear");
    digitalWrite(LED, LOW);
  }
  delay(200);
}



#include<Servo.h>
Servo myservo;

int servo_pos=0;
int dataPin = 7;
int ledPin = 13;

void setup() {
  
  Serial.begin(115200);
  pinMode(dataPin, INPUT);
  pinMode(ledPin, OUTPUT);
  myservo.attach(9);
  myservo.write(0);
  loopingFn();
  startbot();
}

void loopingFn() {
  int flag=0;
  do
  {
    int data= digitalRead(dataPin);
    if(data==LOW)
    {
      digitalWrite(ledPin, HIGH);
      Serial.println("No Obstacle...........................................");
    }
    else
    {
      digitalWrite(ledPin, LOW);
      Serial.println("Obstacle Detected");
      flag=1;
    }
  }while(flag==0);
}

void startbot()
{
  Serial.println("Starting bot");
  delay(700);
}
 void loop(){}

