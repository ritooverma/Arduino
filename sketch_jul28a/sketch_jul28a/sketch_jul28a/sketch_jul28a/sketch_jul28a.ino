#define ledPin 13
void setup()
{
pinMode(ledPin,OUTPUT);//INITIALIZE TIMER
noInterrupts();
TCCR1A = 0;//DISABLE ALL INTERRUPTS
TCCR1B = 0;
TCNT1 = 0;
OCR1A =65535;
TCCR1B = (1<<WGM12);
TCCR1B |=(1<<CS12);//pre scaler
TIMSK1 |=(1<< OCIE1A);
interrupts();
}
ISR(TIMER1_COMPA_vect)
{
  digitalWrite(ledPin,digitalRead(ledPin)^1);
}

void loop() {
  

}
