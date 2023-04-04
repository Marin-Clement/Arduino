#include <LiquidCrystal.h>

#define BUTTON_PIN 7

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

unsigned long timer = 0;

bool buttonState = false;

const unsigned long DISPLAY_DELAY = 500;

void setup() {
  lcd.begin(16, 2);
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  lcd.print("Team diff");
}

void loop() {
  bool newButtonState = digitalRead(BUTTON_PIN) == LOW;
  if (newButtonState != buttonState) {
    buttonState = newButtonState;
    if (buttonState) {
      timer = 0;
        lcd.setCursor(0, 1);
        lcd.print("         ");
    }
  }
  unsigned long elapsedTime = millis() - timer;
  lcd.setCursor(0, 1);
  lcd.print(elapsedTime / 1000);
  delay(DISPLAY_DELAY);
}
