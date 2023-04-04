#include <LiquidCrystal.h>

// Initialisation de l'écran LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int joyX = A0;
int joyY = A1;

void setup() {
  lcd.begin(16, 2);

  lcd.print("Direction: ");

  pinMode(joyX, INPUT);
  pinMode(joyY, INPUT);
}

void loop() {
  int xVal = analogRead(joyX);
  int yVal = analogRead(joyY);

  if (xVal < 300) {
    lcd.setCursor(0, 1);
    lcd.print("Gauche ");
  }
  else if (xVal > 700) {
    lcd.setCursor(0, 1);
    lcd.print("Droite ");
  }
  else if (yVal < 300) {
    lcd.setCursor(0, 1);
    lcd.print("Haut   ");
  }
  else if (yVal > 700) {
    lcd.setCursor(0, 1);
    lcd.print("Bas    ");
  }
  else {
    lcd.setCursor(0, 1);
    lcd.print("Centre ");
  }
}