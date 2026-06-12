#include <Servo.h>

Servo servo1;
Servo servo2;

const int pinPIR   = 2;
const int pinBoton = 7;
const int pinTemp  = A0;

int anguloNormal = 90;
bool enPIR = false;
unsigned long tiempoAnterior;

void setup() {
  servo1.attach(9);
  servo2.attach(10);
  pinMode(pinPIR, INPUT);
  pinMode(pinBoton, INPUT_PULLUP);

  servo1.write(45);
  servo2.write(45);
}

void loop() {
  if (digitalRead(pinBoton) == HIGH) {
    botonNoPresionado();
    return;
  }

  if (leerTemperatura() > 35) {
    return;
  }

  if (digitalRead(pinPIR) == HIGH) {
    movimientoDetectado();
    return;
  }

  if (enPIR) {
    esperarPIR();
    return;
  }

  modoNormal();
}

void botonNoPresionado() {
  servo1.write(45);
  servo2.write(45);
  enPIR = false;
}

float leerTemperatura() {
  int valor = analogRead(pinTemp);
  float voltaje = valor * 5.0 / 1023.0;
  return (voltaje - 0.5) * 100.0;
}

void movimientoDetectado() {
  servo1.write(0);
  servo2.write(0);
  enPIR = true;
  tiempoAnterior = millis();
}

void esperarPIR() {
  if (millis() - tiempoAnterior >= 6000) {
    enPIR = false;
    tiempoAnterior = millis();
  }
}

void modoNormal() {
  if (millis() - tiempoAnterior >= 3000) {
    tiempoAnterior = millis();
    servo1.write(anguloNormal);
    servo2.write(anguloNormal);
    anguloNormal = (anguloNormal == 90) ? 180 : 90;
  }
}