int ledPin = 13;
int dataPin=7;
int val=0;
void setup()
{
Serial.begin(9600);
pinMode(ledPin,OUTPUT);
pinMode(dataPin,INPUT);
}
void loop()
  {
/* if(Serial.read()==HIGH)
  ledPin = HIGH;
  else
  ledPin=LOW;
  }
  }*/
 val= digitalRead(dataPin);
  if(val==HIGH)
  {
    digitalWrite(ledPin,HIGH);
  }
  else
  {
    digitalWrite(ledPin,LOW);
  }
    
  }
