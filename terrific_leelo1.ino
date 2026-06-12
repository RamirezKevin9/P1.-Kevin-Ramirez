#include <Servo.h>

Servo servo1;
Servo servo2;

const int pirPin = 2;
const int botonPin = 7;
const int tempPin = A0;

int posicion = 90;
bool estadoServo = false;

unsigned long tiempoCambio = 0;

void setup() {
  servo1.attach(9);
  servo2.attach(10);

  pinMode(pirPin, INPUT);
  pinMode(botonPin, INPUT_PULLUP);

  servo1.write(45);
  servo2.write(45);
}

void loop() {
  
  bool botonPresionado = (digitalRead(botonPin) == LOW);
  
  if (!botonPresionado) {
    servo1.write(45);
    servo2.write(45);
    return;
  }

  int lectura = analogRead(tempPin);
  float voltaje = lectura * (5.0 / 1023.0);
  float temperatura = (voltaje - 0.5) * 100.0;

  if (temperatura > 35) {
    return;
  }

  if (digitalRead(pirPin) == HIGH) {
    servo1.write(0);
    servo2.write(0);
    delay(6000);
    return;
  }

  if (millis() - tiempoCambio >= 3000) {

    if (estadoServo) {
      posicion = 90;
    } else {
      posicion = 180;
    }

    servo1.write(posicion);
    servo2.write(posicion);

    estadoServo = !estadoServo;
    tiempoCambio = millis();
  }
}