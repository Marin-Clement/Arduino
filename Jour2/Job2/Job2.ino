#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2); 
}

void loop() {
  voltage = analogRead(AO) * (5.0 / 1023.0);
  lcd.clear();
  lcd.print("Voltage:");
  lcd.setCursor(0, 1);
  lcd.print(voltage);
  delay(1000);
}