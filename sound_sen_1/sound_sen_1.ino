int soundSensor=2;
int LED=4;

boolean LEDStatus=false;

void setup() {
 pinMode(soundSensor,INPUT);
 pinMode(LED,OUTPUT);
 pinMode(A0,INPUT);
Serial.begin(9600);
}

void loop() {
  
  int SensorData=digitalRead(soundSensor); 
  int analog = analogRead(A0);
  Serial.println(analog);

  if(SensorData==1){

    if(LEDStatus==false){
        LEDStatus=true;
        digitalWrite(LED,HIGH);
    }
    else{
        LEDStatus=false;
        digitalWrite(LED,LOW);
    }
  }
 } 
