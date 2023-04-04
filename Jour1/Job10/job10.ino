 const int ledPin = 9;

const int animationTime = 2000;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(animationTime/255); //Attendre un temps défini pour chaque étape
  }

  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(animationTime/255); //Attendre un temps défini pour chaque étape
  }
}