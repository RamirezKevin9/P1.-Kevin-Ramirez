#include <Adafruit_LiquidCrystal.h>
#include <Servo.h>

#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))

#define Gb3 208
#define C4  262
#define F3  175
#define A3  220

#define pinRojo 8
#define pinAzul 7
#define pinVerde 4
#define pinBuzzer 2
#define pinBoton 12
#define pinServo A0
#define pinPoten A1
#define pinTem A2

Adafruit_LiquidCrystal lcd1(0);
Servo miServo;

const int midi1[10][3] = {
  {Gb3, 115, 0},
  {C4, 115, 0},
  {Gb3, 115, 0},
  {F3, 115, 0},
  {A3, 115, 115},
  {Gb3, 115, 0},
  {C4, 115, 0},
  {Gb3, 115, 0},
  {F3, 115, 0},
  {A3, 115, 0}
};

void setup() {
  pinMode(pinRojo, OUTPUT);
  pinMode(pinAzul, OUTPUT);
  pinMode(pinVerde, OUTPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinBoton, INPUT_PULLUP);

  miServo.attach(pinServo);
  miServo.write(0);

  lcd1.begin(16, 2);
  lcd1.clear();
}

void loop() {
  chequearTemperatura();

  if (digitalRead(pinBoton) == LOW) {
    ejecutarSecuenciaServo();
    reproducirMelodia();
    
    lcd1.clear();
  }
  
  delay(100);
}

void chequearTemperatura() {
  int temperatura = analogRead(pinTem);
  temperatura = map(((temperatura - 20) * 3.04), 0, 1023, -40, 125);  
  	

  if (temperatura > 40) {
    digitalWrite(pinRojo, HIGH);
    digitalWrite(pinAzul, LOW);
  } else {
    digitalWrite(pinRojo, LOW);
    digitalWrite(pinAzul, HIGH);
  }
}

void ejecutarSecuenciaServo() {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Servo moviendose");
  int potencia = analogRead(pinPoten);
  for (int i = 0; i < 10; i++) {
    int potencia = analogRead(pinPoten);
    int tiempoEspera;
	miServo.write(90);
    if (potencia < 256) {
      delay(2000);
    } else if (potencia <= 512) {
      delay(5000);
    } else {
      delay(8000);
    }
    chequearTemperatura();
    
    miServo.write(0);
    if (potencia < 256) {
      delay(2000);
    } else if (potencia <= 512) {
      delay(5000);
    } else {
      delay(8000);
    }
    chequearTemperatura();
  }
}

void reproducirMelodia() {
  lcd1.clear();
  lcd1.setCursor(0, 0);
  lcd1.print("Melodia");

  digitalWrite(pinVerde, HIGH);

  for (size_t i = 0; i < ARRAY_LEN(midi1); i++) {
    chequearTemperatura();
    tone(pinBuzzer, midi1[i][0]);
    delay(midi1[i][1]);
    noTone(pinBuzzer);
    delay(midi1[i][2]);
  }

  digitalWrite(pinVerde, LOW);
}