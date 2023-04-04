const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9};

//Temps en millisecondes entre chaque clignotement
const int delayTime = 500;

void setup() {
  //Initialisation des pins de sortie pour les LED
  for (int i = 0; i < 8; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  //Allumer les LED une par une
  for (int i = 0; i < 8; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime); //Attendre le temps défini
    digitalWrite(ledPins[i], LOW);
  }
}