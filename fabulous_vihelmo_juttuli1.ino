#define boton 2
#define boton2 4
#include <Servo.h>
bool valorboton;
bool valorboton2;
int rotacion = 0;
Servo servobase;
Servo servobase2;
Servo servobase3;
void setup()
{
  pinMode(boton,INPUT);
  pinMode(boton2,INPUT);
  servobase.attach(A0);
  servobase.write(0);
  servobase2.attach(A1);
  servobase2.write(0);
  Serial.begin(9800);
}

void loop()
{
  valorboton = digitalRead(boton);
  valorboton2 = digitalRead(boton2);
  if (valorboton == LOW){
    rotacion = rotacion + 10;
    servobase.write(rotacion);
    servobase2.write(rotacion);
    delay(2000);
  }
  if (valorboton2 == LOW){
    rotacion = rotacion - 10;
    servobase.write(rotacion);
    servobase2.write(rotacion);
  delay(2000);
  }
  if (rotacion < 0){
    rotacion = 0;
  }
  Serial.println(rotacion);
  Serial.println(valorboton);
  Serial.println("Elvalor del boton 2");
  Serial.println(valorboton2);
}