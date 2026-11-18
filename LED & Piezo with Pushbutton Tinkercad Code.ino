int led = 13;
int pb = 2;
int b1 = 8;
void setup()
{
  pinMode(led, OUTPUT);
  pinMode(pb, INPUT_PULLUP);
  pinMode (b1, OUTPUT);
}

void loop()
{
  int buttonState = digitalRead(pb);
  
  if(buttonState == HIGH) {
    digitalWrite(led, HIGH);
    }
  else {
    digitalWrite(led, LOW);
    tone(b1, 1200, 400);
  }
}
  
