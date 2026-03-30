int redLED = 7;
int greenLED = 6;
int yellowLED = 5;

int btnTraffic = 10;
int btnChase = 9;
int btnBlink = 8;

int mode = 0;

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);

  pinMode(btnTraffic, INPUT_PULLUP);
  pinMode(btnChase, INPUT_PULLUP);
  pinMode(btnBlink, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(btnTraffic) == LOW) {
    mode = 1;
  }
  if (digitalRead(btnChase) == LOW) {
    mode = 2;
  }
  if (digitalRead(btnBlink) == LOW) {
    mode = 3;
  }

  if (mode == 1) {
    trafficLight();
  }
  else if (mode == 2) {
    ledChase();
  }
  else if (mode == 3) {
    blinkAll();
  }
}

void trafficLight() {
  digitalWrite(redLED, HIGH);
  digitalWrite(greenLED, LOW);
  digitalWrite(yellowLED, LOW);
  delay(3000);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, HIGH);
  delay(1000);

  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, HIGH);
  delay(3000);

  digitalWrite(greenLED, LOW);
}

void ledChase() {
  digitalWrite(redLED, HIGH);
  delay(200);
  digitalWrite(redLED, LOW);

  digitalWrite(yellowLED, HIGH);
  delay(200);
  digitalWrite(yellowLED, LOW);

  digitalWrite(greenLED, HIGH);
  delay(200);
  digitalWrite(greenLED, LOW);
}


void blinkAll() {
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, HIGH);
  digitalWrite(greenLED, HIGH);
  delay(300);

  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(300);
}