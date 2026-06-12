#include <Servo.h>

Servo servo1;
Servo servo2;

int pir = 2;
int boton = 7;
int temp = A0;

void setup() {
  servo1.attach(9);
  servo2.attach(10);

  pinMode(pir, INPUT);
  pinMode(boton, INPUT_PULLUP);

  servo1.write(45);
  servo2.write(45);
}

void loop() {

  if (digitalRead(boton) == HIGH) {
    servo1.write(45);
    servo2.write(45);
  }

  else {

    int valor = analogRead(temp);
    float voltaje = valor * 5.0 / 1023.0;
    float temperatura = (voltaje - 0.5) * 100;

    if (temperatura > 35) {
      delay(100);
    }

    else {

      if (digitalRead(pir) == HIGH) {
        servo1.write(0);
        servo2.write(0);
        delay(6000);
      }

      else {

        servo1.write(90);
        servo2.write(90);
        delay(3000);

        servo1.write(180);
        servo2.write(180);
        delay(3000);
      }
    }
  }
}