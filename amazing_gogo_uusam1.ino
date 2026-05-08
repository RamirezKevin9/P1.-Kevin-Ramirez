// Pines
const int pinTemp = A0;
const int pinLuz = A1;

const int pinR = 11;
const int pinB = 10;
const int pinG = 9;
// Variables
float temperatura = 0;
int valorLuz = 0;
float porcentajeLuz = 0; 

void setup() {
  Serial.begin(9600);

  pinMode(pinR, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinB, OUTPUT);
}

void loop() {

  // Leer temperatura (TMP36)
  int lecturaTemp = analogRead(pinTemp);
  float voltaje = lecturaTemp * (5.0 / 1023.0);
  temperatura = (voltaje - 0.5) * 100.0;

  // Leer luz (LDR)
  valorLuz = analogRead(pinLuz);

  // (Convertir a porcentaje)
  porcentajeLuz = map(valorLuz, 0, 1023, 60, 125);

  // Mostrar datos
  Serial.print("El nivel de luz actual es: ");
  Serial.print(porcentajeLuz);
  Serial.println("%");

  Serial.print("La temperatura actual es: ");
  Serial.print(temperatura);
  Serial.println(" C");

  // Control del LED RGB
  // Apagar primero
  analogWrite(pinR, 0);
  analogWrite(pinG, 0);
  analogWrite(pinB, 0);

  // Solo si la luz está entre 30% y 70%
  if (porcentajeLuz >= 30 && porcentajeLuz <= 70) {

    if (temperatura > 90) {
      // ROJO
      analogWrite(pinR, 255);
    }
    else if (temperatura < 18) {
      // AZUL
      analogWrite(pinB, 255);
    }
    else {
      // VERDE
      analogWrite(pinG, 255);
    }
  }

  delay(1000);
}