// 1. INCLUSIÓN DE LA LIBRERÍA USADA
#include "DHT.h"

// 2. CONFIGURACIÓN DE PINES Y VARIABLES
#define DHTPIN 2          // Pin digital donde conectamos el sensor DHT11
#define DHTTYPE DHT11     // Definimos que el sensor es un DHT11
#define PIN_ALERTA 13     // Pin digital para el LED o actuador de alerta

float limiteTemperatura = 30.0; // Umbral de temperatura para activar la alerta

// Inicializamos el objeto del sensor
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Inicializamos la comunicación serie para ver los datos en la terminal
  Serial.begin(9600);
  Serial.println("--- Sistema de Monitoreo Ambiental Iniciado ---");
  
  // Configurar el pin de alerta como salida
  pinMode(PIN_ALERTA, OUTPUT);
  
  // Arrancar el sensor DHT11
  dht.begin();
}

void loop() {
  // El DHT11 es un sensor lento, debemos esperar al menos 2 segundos entre lecturas
  delay(2000);

  // Leer la humedad relativa (%)
  float humedad = dht.readHumidity();
  // Leer la temperatura en grados Celsius (°C)
  float temperatura = dht.readTemperature();

  // VALIDACIÓN: Comprobar si la lectura falló (por cables sueltos o mal sensor)
  if (isnan(humedad) || isnan(temperatura)) {
    Serial.println("Error crítico: No se puede leer el sensor DHT11.");
    return; // Sale del loop actual y vuelve a intentar en el siguiente ciclo
  }

  // IMPRESIÓN DE DATOS: Mostramos las lecturas en el Monitor Serie
  Serial.print("Humedad Actual: ");
  Serial.print(humedad);
  Serial.print(" %  |  ");
  Serial.print("Temperatura Actual: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  // LÓGICA DE CONTROL (Manejo del actuador/alerta)
  if (temperatura > limiteTemperatura) {
    // Si la temperatura supera el límite, encendemos la alerta
    digitalWrite(PIN_ALERTA, HIGH);
    Serial.println("[ALERTA] ¡Temperatura alta detectada! Ventilador/Alarma ENCENDIDO.");
  } else {
    // Si las condiciones son normales, apagamos la alerta
    digitalWrite(PIN_ALERTA, LOW);
  }
}
