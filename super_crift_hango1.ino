int RED = 13, YELL = 12, BLU = 8;

void setup()
{
  pinMode(RED, OUTPUT);
  pinMode(YELL, OUTPUT);
  pinMode(BLU, OUTPUT);
  
}

void loop()
{
  digitalWrite(RED, HIGH);
  delay(1000);
  digitalWrite(RED, LOW);
  delay(1000);
    
  digitalWrite(YELL, HIGH);
  delay(500);
  digitalWrite(YELL, LOW);
  delay(500);
    
  digitalWrite(BLU, HIGH);
  delay(2000);
  digitalWrite(BLU, LOW);
  delay(2000);
}