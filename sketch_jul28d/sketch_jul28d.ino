const int led = 13;
int a;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(led,OUTPUT);
}
void loop() {
 if(Serial.available())
 {
  a=Serial.read();
  Serial.println(a);
  digitalWrite(led,a);// put your main code here, to run repeatedly:
 }

}
