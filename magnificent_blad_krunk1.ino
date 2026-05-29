int boton = 2;
int pir = 7;
int ldr = A0;

int rojo = 9;
int azul = 11;

bool sistemaActivo = false;
bool estadoBotonAnterior = LOW;

void setup() {
  pinMode(boton, INPUT);
  pinMode(pir, INPUT);

  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);

  Serial.begin(9600);
}

void loop() {

  bool estadoBoton = digitalRead(boton);

  if (estadoBoton == HIGH && estadoBotonAnterior == LOW) {
    sistemaActivo = !sistemaActivo;
    delay(200);
  }

  estadoBotonAnterior = estadoBoton;

  int valorLuz = analogRead(ldr);

  Serial.println(valorLuz);

  if (sistemaActivo && valorLuz > 512) {

    if (digitalRead(pir) == HIGH) {

      analogWrite(rojo, 255);
      analogWrite(azul, 255);

    } else {

      analogWrite(rojo, 0);
      analogWrite(azul, 0);
    }

  } else {

    analogWrite(rojo, 0);
    analogWrite(azul, 0);
  }
}