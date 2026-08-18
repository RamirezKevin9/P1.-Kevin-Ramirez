#include <Servo.h>

#define PIR_ENTRADA 2
#define PIR_SALIDA 3
#define BUZZER 8
#define SERVO_1 9
#define SERVO_2 10
#define FOCO 7
#define LDR A0

Servo servo1;
Servo servo2;

int limiteLuz = 400;
int puertasAbiertas = 0;

void detectarMovimiento(int pin, int &movimiento)
{
  movimiento = digitalRead(pin);
}

void detectarLuz(int pin, int limite, int &oscuro)
{
  int valor = analogRead(pin);

  if (valor < limite)
  {
    oscuro = 1;
  }
  else
  {
    oscuro = 0;
  }
}

void prenderFoco(int pin, int estado)
{
  digitalWrite(pin, estado);
}

void abrirPuertas(int posicion1, int posicion2)
{
  servo1.write(posicion1);
  servo2.write(posicion2);
  puertasAbiertas = 1;
}

void cerrarPuertas(int posicion1, int posicion2)
{
  servo1.write(posicion1);
  servo2.write(posicion2);
  puertasAbiertas = 0;
}

void cancionAbrir(int pin)
{
  tone(pin, 262, 200);
  delay(250);
  tone(pin, 294, 200);
  delay(250);
  tone(pin, 330, 200);
  delay(250);
  tone(pin, 349, 200);
  delay(250);
  tone(pin, 392, 300);
  delay(350);
}

void cancionCerrar(int pin)
{
  tone(pin, 392, 200);
  delay(250);
  tone(pin, 349, 200);
  delay(250);
  tone(pin, 330, 200);
  delay(250);
  tone(pin, 294, 200);
  delay(250);
  tone(pin, 262, 300);
  delay(350);
}

void cambiarPuertas()
{
  if (puertasAbiertas == 0)
  {
    abrirPuertas(0, 180);
    cancionAbrir(BUZZER);
  }
  else
  {
    cerrarPuertas(90, 90);
    cancionCerrar(BUZZER);
  }
}

void setup()
{
  pinMode(PIR_ENTRADA, INPUT);
  pinMode(PIR_SALIDA, INPUT);
  pinMode(FOCO, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  servo1.attach(SERVO_1);
  servo2.attach(SERVO_2);

  cerrarPuertas(90, 90);
}

void loop()
{
  int movimientoEntrada;
  int movimientoSalida;
  int oscuro;

  detectarMovimiento(PIR_ENTRADA, movimientoEntrada);
  detectarMovimiento(PIR_SALIDA, movimientoSalida);
  detectarLuz(LDR, limiteLuz, oscuro);

  prenderFoco(FOCO, oscuro);

  if (movimientoEntrada == HIGH)
  {
    cambiarPuertas();
    delay(500);
  }

  if (movimientoSalida == HIGH)
  {
    cambiarPuertas();
    delay(500);
  }
}