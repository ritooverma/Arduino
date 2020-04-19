int echoPin = D1;
int trigPin = D2;
long duration;
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  if(duration==0)
  Serial.println("Infinite");
  else
  {
  distance = (duration*0.0343)/2;

  Serial.print("DISTANCE in cm = ");
  Serial.println(distance);
  }
  Serial.println();
  
}
