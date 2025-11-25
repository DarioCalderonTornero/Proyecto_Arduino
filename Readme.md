# 🛳️ Proyecto: Hundir la Flota Físico (Arduino)

## 👥 Equipo

- **Juan** — Programador  
- **Darío** — Programador  

Ambos participamos en la programación, las pruebas y el montaje del prototipo físico.

---

## 🎯 Objetivo del proyecto

Crear una versión física y en solitario del clásico **Hundir la Flota**, usando un **joystick analógico** 🎮 para seleccionar casillas y una **matriz LED 8×8 (1588BS)** 🔲 como tablero enemigo.

El sistema colocará los “barcos” 🚢 de forma aleatoria. El jugador se moverá por el tablero con el joystick y, al pulsarlo, realizará su disparo:

- 🎯 **Impacto** → el LED se enciende con **máxima intensidad**.  
- 💧 **Agua** → el LED queda con **brillo bajo** para indicar fallo.

---

## 📝 Descripción general

- El Arduino genera **posiciones aleatorias** para los barcos.
- El jugador se desplaza por la matriz usando el **joystick**.
- El **botón del joystick** realiza el disparo.
- La **matriz 8×8** actúa como tablero visual:
  - 🔥 Acierto = brillo alto  
  - 💦 Fallo = brillo bajo  
- Objetivo: **localizar todos los barcos** con el menor número de intentos.

El proyecto combina sensores y actuadores para crear una experiencia interactiva física, tal como pide la guía de Computación Física.

---

## 🔧 Componentes

### Sensores y actuadores

- 🎮 **Joystick analógico** (X, Y y pulsador).
- 🔲 **Matriz LED 8×8 1588BS**.

### Otros componentes

- 💡 Arduino UNO o compatible  
- 🧩 Protoboard  
- 🧵 Cables puente  
- 🔌 Resistencias  

## 📁 Entregables en el repositorio

- `README.md`  
  - Objetivo del proyecto  
  - Equipo  
  - Bitácora  
  - Estado actual  
  - Tareas pendientes  

- **Boceto en Tinkercad/Fritzing**  
  - Esquema del circuito  
  - Capturas de pantalla  
  - Código del prototipo  

  - Lista de sensores  
  - Componentes  
  - Conexiones  

- Carpeta de código (`/src` o `/arduino`)  
  - Código completo del juego

- Extras  
  - 📸 Fotos del montaje  
  - 🎥 Vídeo del prototipo funcionando  

---

## 🚦 Estado actual del proyecto

**Sprint 1**

- ✔️ Idea clara: Hundir la Flota físico con joystick + matriz 8×8  
- ✔️ Equipo definido  
- ✔️ README inicial creado  
- 🔧 Pruebas hechas:
  - Encendido completo de la matriz de leds

---

## 🗂️ Plan de trabajo (sprints)

### 🟩 Sprint 1 (hasta 25/11)

- Definir objetivo y alcance  
- Boceto inicial en Tinkercad  
- Encendido básico de LED  
- Comienzo del README  

### 🟨 Sprint 2 (26/11 – 04/12)

- Movimiento del cursor con joystick  
- Disparo al pulsar el botón  
- Colocación aleatoria de barcos  
- Sistema de impacto/fallo con brillo
- Resolución de problemas

### 🟥 LiveDemo (05/12 – 16/12)

- Ajustes de sensibilidad, tiempos y brillo  
- Preparar explicación del circuito  
- Explicar el código en la presentación  
- Grabar vídeo como respaldo  

## 📒 Bitácora de trabajo

> Registro de avances del equipo, sesión a sesión.

**Definición del proyecto**  

- Decidimos hacer un Hundir la Flota físico 🎮🔲  
- Elegimos joystick + matriz LED como base  
- Revisamos la guía oficial para organizar entregables  

**Pruebas iniciales**  
- Primer encendido de LEDs OK  

## 🧾 Tareas pendientes

- [ ] Diseñar circuito completo en Tinkercad  
- [ ] Mapear coordenadas del joystick a la matriz  
- [ ] Generar barcos aleatorios  
- [ ] Programar impacto/fallo con diferente brillo  
- [ ] Crear condición de victoria  
- [ ] Comentar todo el código  
- [ ] Añadir fotos del montaje  
- [ ] Preparar materiales 
