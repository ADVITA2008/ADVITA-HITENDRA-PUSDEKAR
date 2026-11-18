#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup() {
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}
void loop() {
  lcd.clear();
  lcd.setCursor(0, 0);
  if (digitalRead(6) == 0){
    digitalWrite(7, HIGH);
    lcd.write("LED ON");
    delay(100);}
  else if (digitalRead(6) == 1){
    digitalWrite(7, LOW);
    lcd.write("LED OFF");
    delay(100);}
}
