int b1 = 13;
int b2 = 12;
int b3 = 8;
int b4 = 4;
void setup()
{
  pinMode(b1, OUTPUT);
  pinMode(b2, OUTPUT);
  pinMode(b3, OUTPUT);
  pinMode(b4, OUTPUT);
}

void loop()
{
 tone(b1, 500, 400);
   delay(500);
 tone(b2, 700, 300);
   delay(500);
 tone(b3, 1200, 200);
   delay(500);
 tone(b4, 1500, 300);
   delay(500);
}
