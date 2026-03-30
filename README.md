# 🚦 Arduino Traffic Light Controller (3 LEDs + 3 Buttons)

A simple and fun Arduino project that simulates a traffic light system and includes multiple LED modes controlled by buttons.

---

## 🧠 Features

* 🚦 **Traffic Light Mode**
  Simulates real traffic light behavior (Red → Yellow → Green)

* 🏃 **LED Chase Mode**
  LEDs turn on one after another in a running pattern

* 💥 **Blink All Mode**
  All LEDs blink together

* 🎮 **Button Control**
  Each mode is activated using a dedicated button

---

## 🧩 Components Required

* Arduino UNO (or compatible board)
* 3 LEDs (Red, Yellow, Green)
* 3 × 220Ω resistors
* 3 push buttons (4-pin)
* Breadboard
* Jumper wires

---

## 🔌 Pin Configuration

### LEDs

| LED Color | Arduino Pin |
| --------- | ----------- |
| Red       | 7           |
| Green     | 6           |
| Yellow    | 5           |

### Buttons

| Function       | Arduino Pin |
| -------------- | ----------- |
| Traffic Mode   | 10          |
| LED Chase Mode | 9           |
| Blink Mode     | 8           |

---

## ⚡ Wiring Guide

### LEDs

* Connect each LED **anode (long leg)** → resistor → Arduino pin
* Connect each LED **cathode (short leg)** → GND

### Buttons

* Place buttons across the breadboard gap
* One side → Arduino pin
* Other side → GND
* Use `INPUT_PULLUP` (no external resistor needed)

---

## 🎮 How It Works

* Press **Traffic Button** → activates traffic light sequence
* Press **Chase Button** → activates LED running effect
* Press **Blink Button** → activates blinking mode

👉 Only one mode runs at a time

---

## 🧾 Code

```cpp
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
```

---

## ⚠️ Notes

* Buttons use **INPUT_PULLUP**, so:

  * Pressed = LOW
  * Not pressed = HIGH

* Add **debouncing** if buttons behave inconsistently

---

## 🚀 Future Improvements

* Add buzzer for sound alerts 🔊
* Add OLED display for status 📟
* Convert to WiFi control using ESP8266 🌐
* Replace LEDs with RGB module 🎨

---

## 👨‍💻 Author

Built by Elisee 💡
A simple step toward mastering embedded systems and IoT 🚀

---
