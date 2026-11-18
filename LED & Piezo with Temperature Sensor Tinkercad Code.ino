int baselineTemp = 0;
int celsius = 0;
int fahranheit = 0;
int led1 = 13, led2 = 8, led3 = 4, buz = 2;


void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buz, OUTPUT);
}

void loop()
{
  baselineTemp = 30;
  
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
  
  fahranheit = ((celsius * 9) / 5 + 32);
  Serial.print(celsius);
  Serial.print("C,");
  Serial.print(fahranheit);
  Serial.println("F");

if(celsius < baselineTemp) {
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

if(celsius >= baselineTemp && celsius < baselineTemp + 10) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}

if(celsius >= baselineTemp + 10 && celsius < baselineTemp + 20) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, LOW);
}

if(celsius >= baselineTemp + 20 && celsius < baselineTemp + 30) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
}
delay(1000);

if(celsius >= baselineTemp + 40) {
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  tone(buz, 1200, 200);
}
}
  
  
  
  
  
