#include <LiquidCrystal.h>

// Initialiser l'afficheur LCD
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// Définir les broches pour le bouton
const int buttonPin = 7;

// Initialiser les variables
unsigned long startTime;
unsigned long elapsedTime = 0;
bool isRunning = false;

void setup() {
  // Initialiser l'afficheur LCD
  lcd.begin(16, 2);

  // Initialiser le bouton
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  // Vérifier si le bouton a été pressé
  if (digitalRead(buttonPin) == LOW && !isRunning) {
    // Démarrer le chronomètre
    startTime = millis();
    isRunning = true;
  }

  // Vérifier si le chronomètre est en cours d'exécution
  if (isRunning) {
    // Calculer le temps écoulé
    elapsedTime = millis() - startTime;

    // Afficher le temps écoulé sur l'afficheur LCD
    lcd.setCursor(0, 0);
    lcd.print("Temps ecoule: ");
    lcd.setCursor(0, 1);
    lcd.print(elapsedTime / 1000);
    lcd.print(" secondes");
  }
}
s