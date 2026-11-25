#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float tempC = 0.0;
float threshold = 50.0;
const int buzzerPin = 6;
const int sensorPin = A0;

void setup() {
  lcd.begin(16, 2);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int raw = analogRead(sensorPin);
  float voltage = raw * (5.0 / 1024.0);
  tempC = (voltage - 0.5) * 100.0;

  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.println(" C");

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC, 1);
  lcd.print(" C");

  if (tempC > threshold) {
    digitalWrite(buzzerPin, HIGH);
    lcd.setCursor(0, 1);
    lcd.print("ALERT: High Temp");
  } else {
    digitalWrite(buzzerPin, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Status: Normal");
  }

  delay(200);
}
