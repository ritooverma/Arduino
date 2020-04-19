const int sw = 8;
void setup()
{
  Serial.begin(9600);
  pinMode(sw, INPUT);
}

void loop()
{
  if (digitalRead(sw) == HIGH)
  {
    Serial.write(1);
  }
  else
  {
    Serial.write(0);
  }

}


