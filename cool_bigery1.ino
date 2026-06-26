int pot = A0;

int rojo = 9;
int verde = 10;
int azul = 11;

int notas[] = {8, 7, 9, 6, 10, 5, 8, 7, 6, 9};
int numeros[15] = {12, 7, 9, 4, 18, 25, 30, 11, 6, 2, 15, 21, 8, 17, 10};

void setup() {
  Serial.begin(9600);

  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);

  randomSeed(analogRead(A1));
}

void loop() {

  int valor = analogRead(pot);
  int porcentaje = map(valor, 0, 1023, 0, 100);

  if (porcentaje < 20) {
    ejercicio1();
  }
  else if (porcentaje > 20 && porcentaje < 40) {
    ejercicio2();
  }
  else if (porcentaje < 60 && porcentaje > 40) {
    ejercicio3();
  }
  else if (porcentaje > 60 && porcentaje < 80) {
    ejercicio4();
  }
  else {
    ejercicio5();
  }
}

void color(int r, int g, int b) {
  analogWrite(rojo, r);
  analogWrite(verde, g);
  analogWrite(azul, b);
}

void ejercicio1() {

  int lista[] = {10, 20, 30, 40, 50};
  int nueva[5];
  int factor = 3;

  for (int i = 0; i < 5; i++) {

    nueva[i] = lista[i] * factor;

    Serial.println(nueva[i]);

    int brillo = constrain(nueva[i], 0, 255);

    color(brillo, brillo, brillo);

    delay(1000);
  }
}

void ejercicio2() {

  int suma = 0;

  for (int i = 0; i < 10; i++) {
    suma += notas[i];
  }

  float promedio = suma / 10.0;

  Serial.print("Promedio: ");
  Serial.println(promedio);

  if (promedio >= 1 && promedio <= 5) {
    color(255, 0, 0);
  }
  else if (promedio <= 8) {
    color(0, 255, 0);
  }
  else {
    color(0, 255, 255);
  }

  delay(1000);
}

void ejercicio3() {

  for (int i = 0; i < 15; i++) {

    Serial.println(numeros[i]);

    if (numeros[i] % 2 == 0) {
      color(0, 255, 0);
    }
    else {
      color(255, 0, 0);
    }

    delay(500);
  }
}

void ejercicio4() {

  int v[30];

  for (int i = 0; i < 30; i++) {
    v[i] = random(0, 256);
  }

  int max1 = 0;
  int max2 = 0;
  int max3 = 0;

  for (int i = 0; i < 30; i++) {

    if (v[i] > max1) {
      max3 = max2;
      max2 = max1;
      max1 = v[i];
    }
    else if (v[i] > max2) {
      max3 = max2;
      max2 = v[i];
    }
    else if (v[i] > max3) {
      max3 = v[i];
    }
  }

  Serial.print(max1);
  Serial.print(" ");
  Serial.print(max2);
  Serial.print(" ");
  Serial.println(max3);

  color(max1, max2, max3);

  delay(2000);
}

void ejercicio5() {

  int v[30];

  for (int i = 0; i < 30; i++) {
    v[i] = random(0, 256);
  }

  int min1 = 255;
  int min2 = 255;
  int min3 = 255;

  for (int i = 0; i < 30; i++) {

    if (v[i] < min1) {
      min3 = min2;
      min2 = min1;
      min1 = v[i];
    }
    else if (v[i] < min2) {
      min3 = min2;
      min2 = v[i];
    }
    else if (v[i] < min3) {
      min3 = v[i];
    }
  }

  Serial.print(min1);
  Serial.print(" ");
  Serial.print(min2);
  Serial.print(" ");
  Serial.println(min3);

  color(min1, min2, min3);

  delay(2000);
}