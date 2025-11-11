# 🔌 Proyecto Arduino

Este proyecto utiliza una placa **Arduino UNO** para controlar sensores y actuadores, permitiendo realizar mediciones y acciones automáticas de forma sencilla.

---

## 🧠 Descripción

El objetivo de este proyecto es leer los datos de un sensor (por ejemplo, de temperatura o luz) y activar un actuador (como un LED o un motor) según los valores recibidos.

---

## ⚙️ Componentes necesarios

- Arduino UNO  
- Sensor de temperatura **DHT11**  
- LED y resistencia de 220 Ω  
- Cables de conexión  
- Protoboard  

---

## 💻 Código de ejemplo

```cpp
#include <DHT.h>

#define DHTPIN 2       // Pin del sensor
#define DHTTYPE DHT11  // Tipo de sensor
#define LEDPIN 13      // Pin del LED

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(LEDPIN, OUTPUT);
}

void loop() {
  float temperatura = dht.readTemperature();

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" °C");

  if (temperatura > 25) {
    digitalWrite(LEDPIN, HIGH); // Enciende el LED
  } else {
    digitalWrite(LEDPIN, LOW);  // Apaga el LED
  }

  delay(2000);
}
