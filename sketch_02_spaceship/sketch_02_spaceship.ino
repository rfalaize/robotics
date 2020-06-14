int pushState = 0;

void setup() {
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  pushState = digitalRead(2);
  if (pushState == LOW) {
    // turn on green light
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
  } else {
    // turn off green light
    digitalWrite(3, LOW);
    // blink red light
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    delay(250);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    delay(250);
  }
}
