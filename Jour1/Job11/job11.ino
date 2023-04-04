// Assignation des broches de la LED et du bouton
int ledPin = 9;
int buttonPin = 2;

// Initialisation des variables
int buttonState = 0;
int lastButtonState = 0;
int buttonCount = 0;
bool isLongPress = false;

// Définition des constantes pour les temps d'allumage et d'extinction de la LED
const int onTime = 500;
const int offTime = 500;

// Définition de la variable pour le temps du dernier changement de l'état du bouton
unsigned long lastDebounceTime = 0;

// Fonction qui permet de faire clignoter la LED
void blinkLED() {
  digitalWrite(ledPin, HIGH);
  delay(onTime);
  digitalWrite(ledPin, LOW);
  delay(offTime);
  Serial.println("click-clack");
}

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); // initialize serial communication
}

void loop() {
  // Lecture de l'état du bouton
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonCount);

  // Vérification si le bouton est appuyé
  if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonCount++;
      isLongPress = false;
      if (buttonCount == 1) {
        // Allumage de la LED
        digitalWrite(ledPin, HIGH);
      } else if (buttonCount == 2) {
        // Maintien de la LED allumée
        digitalWrite(ledPin, HIGH);
      } else if (buttonCount == 3) {
        // Clignotement de la LED
        while (buttonCount == 3) {
          blinkLED();
          buttonState = digitalRead(buttonPin);
          if (buttonState == HIGH) {
            buttonCount++;
          }
        }
      }
    } else {
      // Vérification si le bouton a été appuyé de manière prolongée
      if (isLongPress == true) {
        // Extinction de la LED
        digitalWrite(ledPin, LOW);
        buttonCount = 0;
      }
    }
    // Mise à jour de la variable lastDebounceTime
    lastDebounceTime = millis();
  }

  // Vérification si le bouton est appuyé de manière prolongée
  if (buttonState == HIGH && millis() - lastDebounceTime > 1000) {

    isLongPress = true;
  }
  if (buttonCount > 3) {
    buttonCount = 3;
  }


  // Mise à jour de l'état précédent du bouton
  lastButtonState = buttonState;
}