int potpin = A0;
int ledPin = 9;
int readval;
int writeval;
void setup()
{
pinMode(potpin,INPUT);
pinMode(ledPin,OUTPUT);
Serial.begin(9600);
}

void loop()
{
 readval = analogRead(potpin);
 writeval = (255./1023.)*readval;
 analogWrite(ledPin,writeval);
 Serial.println(writeval);
}
