int LED = 10;
int KNOB = A4;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(KNOB);
  int ledPower = map(val, 1, 1024, 0, 254);
  
  String stringOne = "Sensor Value: ";
  Serial.println(stringOne + ledPower);
  analogWrite(LED, ledPower);
}
  
