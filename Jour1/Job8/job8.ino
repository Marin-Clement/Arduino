const int ledPin1 = 7;
const int ledPin2 = 5;

const int delayTime = 500;

void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
}

void loop() {
  digitalWrite(ledPin1, HIGH);
  digitalWrite(ledPin2, LOW);
  delay(delayTime);

  digitalWrite(ledPin1, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(delayTime); 
} 