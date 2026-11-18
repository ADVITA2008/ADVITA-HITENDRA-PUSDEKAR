#include <LiquidCrystal.h>

int BuzPin = 10;
int LedR = 12;
int LedG = 11;
int SoilMoistureSensor = A0;
int WaterPump = 13;
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

void setup() {
  pinMode(WaterPump, OUTPUT);
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(BuzPin, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  
  lcd.clear();
  lcd.setCursor(0, 0);
  String message1 = "Automated Plant";
  String message2 = "Watering System";
  for(int i = 0; i < message1.length(); i++) {
    lcd.print(message1.charAt(i));
    delay(100);
  }
  lcd.setCursor(0, 1);
  
  for(int i = 0; i < message2.length(); i++) {
    lcd.print(message2.charAt(i));
    delay(100);
  }
  
  delay(2500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Moisture = ");
  lcd.setCursor(0, 1);
  lcd.print("Water Pump = ");
}

void loop()
{
  int Sensor=
    analogRead(SoilMoistureSensor);
  int mappedValue = map(Sensor, 0, 876, 0, 99);
  
  lcd.setCursor(11, 0);
  lcd.print(mappedValue);
  lcd.setCursor(14, 0);
  lcd.print("%");
  lcd.setCursor(13, 1);
  
  if(mappedValue < 50) {
    digitalWrite(WaterPump, HIGH);
    digitalWrite(LedG, HIGH);
    digitalWrite(LedR, LOW);
    lcd.print("ON ");
    playSound();
  }
  else {
    digitalWrite(WaterPump, LOW);
    digitalWrite(LedG, LOW);
    digitalWrite(LedR, HIGH);
    lcd.print("OFF ");
  }
}

void playSound() {
tone(BuzPin, 87, 100);
  delay(100);
}
    
