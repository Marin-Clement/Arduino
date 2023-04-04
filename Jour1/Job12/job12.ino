// Broches pour les LED
const int ledPin1 = 9;
const int ledPin2 = 10;

// Broche pour le potentiomètre
const int potPin = A0;

void setup() {
  // Initialisation des broches en sortie pour les LED
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);

  // Initialisation de la communication série
  Serial.begin(9600);
}

void loop() {
  // Lecture de la valeur du potentiomètre
  int potValue = analogRead(potPin);

  // Calcul de la luminosité des LED en fonction de la valeur du potentiomètre
  int ledBrightness1 = potValue / 4;
  int ledBrightness2 = 255 - ledBrightness1;

  // Mise à jour de la luminosité des LED
  analogWrite(ledPin1, ledBrightness1);
  analogWrite(ledPin2, ledBrightness2);

  // Affichage de la valeur du potentiomètre pour le débogage
  Serial.println(potValue);

  // Attente d'un court instant avant de continuer
  delay(10);
}