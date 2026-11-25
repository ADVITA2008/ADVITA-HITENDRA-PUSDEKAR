#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 7, 6, 5, 4, 9);

int ldrVal = 0;
const int ldrPin = A0;
const int ledPin = 10;
const int threshold = 500;

void setup() {
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Street Light");
  delay(1000);
}

void loop() {
  ldrVal = analogRead(ldrPin);
  Serial.println(ldrVal);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Light : ");
  lcd.print(ldrVal);

  lcd.setCursor(0, 1);
  if (ldrVal > threshold) {
    digitalWrite(ledPin, HIGH);
    lcd.print("LIGHT ON ");
  } else {
    digitalWrite(ledPin, LOW);
    lcd.print("LIGHT OFF");
  }

  delay(100);
}
