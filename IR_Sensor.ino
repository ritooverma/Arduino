int obstPin = 7;
int hasObstacle = HIGH;//high means no obstacle
long duration;
int distance;

void setup() {
  pinMode(obstPin, INPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  hasObstacle = digitalRead(obstPin);
  if(hasObstacle==HIGH)
  {
    Serial.println("...........");
  }
  else
  {
    Serial.println("obstacle");
  }
}
