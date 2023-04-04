#include <LiquidCrystal.h>
#include <TimeLib.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  lcd.begin(16, 2);

  Serial.begin(9600);

  setTime(0);
}

void loop() {
  time_t t = now();

  lcd.setCursor(0, 0);
  lcd.print(formatTime(hour(t)));
  lcd.print(":");
  lcd.print(formatTime(minute(t)));
  lcd.print(":");
  lcd.print(formatTime(second(t)));

  delay(1000);
}

// Fonction pour formater une valeur numérique en chaîne de caractères
String formatTime(int value) {
  if (value < 10) {
    return "0" + String(value);
  } else {
    return String(value);
  }
}