#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Initialise l'afficheur LCD avec l'adresse I2C et la taille de l'afficheur
int rectangle = 1; // Variable pour le nombre de rectangles à afficher

void drawRectangle() {
  lcd.setCursor(0,0); // Positionne le curseur en haut à gauche de l'écran
  lcd.print("["); // Affiche le début du rectangle
  for(int i = 0; i < rectangle; i++) {
    lcd.print("="); // Ajoute des "=" pour remplir le rectangle
  }
  for(int i = rectangle; i < 10; i++) {
    lcd.print(" "); // Ajoute des espaces pour compléter le rectangle
  }
  lcd.print("]"); // Affiche la fin du rectangle

  lcd.setCursor(0,1); // Positionne le curseur sur la deuxième ligne
  int percent = rectangle * 10; // Calcule le pourcentage de chargement
  lcd.print(percent); // Affiche le pourcentage
  lcd.print("%"); // Ajoute le symbole pourcentage

  if(rectangle == 10) { // Si le chargement est complet, on affiche un message
    lcd.clear(); // Efface l'écran
    lcd.setCursor(0,0); // Positionne le curseur en haut à gauche de l'écran
    lcd.print("Chargement complet"); // Affiche un message de chargement complet
}
}

void setup() {
lcd.init(); // Initialise l'afficheur
lcd.backlight(); // Allume le rétro-éclairage
}

void loop() {
drawRectangle(); // Affiche le chargement
delay(3000); // Attends 3 secondes
rectangle++; // Incrémente le nombre de rectangles à afficher
if(rectangle > 10) {
rectangle = 1; // Si on a affiché 10 rectangles, on recommence à 1
}
}