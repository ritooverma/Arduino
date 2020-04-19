#include<Wire.h>
int x=0;
void setup() {
  Wire.begin(9);
Wire.onReceive(receiveEvent);
Serial.begin(9600);
}
void receiveEvent(int bytes)
{
  x=Wire.read();
  Serial.println(x);
}

void loop() {
  

}
