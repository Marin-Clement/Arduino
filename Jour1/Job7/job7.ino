const int ledPin1 = 9;
const int ledPin2 = 9;

const int delayTime = 100;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, HIGH);
  delay(delayTime);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, LOW);
  delay(delayTime); 
}
