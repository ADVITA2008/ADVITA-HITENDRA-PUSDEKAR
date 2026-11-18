int ldrPin = A0;
int ledPins[] = {2, 6, 8, 10, 11, 12, 13};
int threshold = 500;

void setup() {
  Serial.begin(9600);
for (int i = 0; i < 7; i++) {
  pinMode(ledPins[i], OUTPUT);
}
}
void loop() {
  int ldrValue = analogRead(ldrPin);
  Serial.println(ldrValue);
  if (ldrValue < threshold) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(ledPins[i], HIGH);
    }
  }
  else {
    for (int i = 0; i < 7; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
  delay(100);
}
