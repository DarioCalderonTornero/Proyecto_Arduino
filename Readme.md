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

### 🗓️ 11/11 – Inicio del proyecto y lluvia de ideas
- Primera sesión del proyecto.
- Pensamos distintas ideas y finalmente elegimos crear un **Hundir la Flota físico** con joystick + matriz LED 8×8.
- Revisamos la guía de Computación Física para entender entregables y sprints.
- Repartimos roles: ambos programación y pruebas.

---

### 🗓️ 13/11 – Investigación de componentes
- Buscamos información sobre cómo funcionan las matrices LED (modelo 1588BS).
- Revisamos las características del joystick analógico (X/Y + pulsador).
- Consultamos ejemplos y documentación de Arduino relacionados con matrices.
- Estudiamos cómo representar un tablero 8×8 mediante filas y columnas.
**Pendiente:** comprobar encendido real de la matriz.

---

### 🗓️ 18/11 – Pruebas de la matriz LED 8×8
- Cableamos por primera vez la matriz 8×8 en protoboard.
- Comprobamos que los LEDs se encendían correctamente controlando filas y columnas.
- Detectamos errores de cableado y corregimos posiciones equivocadas.
- Encendimos LEDs individuales como prueba de funcionamiento.
**Pendiente:** integrar joystick más adelante.

---

### 🗓️ 20/11 – Sesión de análisis y planificación
- Revisamos qué pines de Arduino serían óptimos para la matriz y el joystick.
- Decidimos la estructura del código del proyecto (lectura → lógica → dibujo).
- Analizamos posibles formas de representar los barcos dentro de la matriz.
- Organizamos el repositorio y añadimos archivos base.
**Pendiente:** empezar las pruebas con el joystick.

---

### 🗓️ 25/11 – Lectura del joystick y movimiento inicial
- Conseguimos lectura estable del joystick (ejes X, Y y pulsador).
- Probamos a mover un “cursor” por la matriz LED 8×8 según los valores del joystick.
- Empezamos a plantear la lógica del disparo y la detección de casillas.
Añadimos un buzzer que emite un sonido cada vez que se pulsa el joystick. Más adelante, solo sonará en caso de fallo.- Actualizado el README con avances para el Sprint 1.
**Pendiente:** implementar impacto/fallo y brillo variable según el resultado.

### 🗓️ **02/12 – Implementación de la lógica completa de Hundir la Flota**
- Añadimos la **lógica principal del juego**: el Arduino genera ahora **coordenadas aleatorias** para simular los barcos distribuidos por la matriz 8×8.  
- Implementamos la **detección de impacto**: si el jugador dispara sobre una casilla con barco, el LED correspondiente se enciende.  
- Programamos la **detección de fallo**: en caso de disparar sobre una casilla sin barco, suena el buzzer un error.  
- Integramos estas comprobaciones en el ciclo completo: **lectura del joystick → disparo → actualización visual del tablero**.  
- Dejamos preparada la base para añadir la futura **condición de victoria** cuando todos los barcos sean encontrados.

**Pendiente:** implementar la condición de acierto/fallo.

### 🗓️ **04/12 – Implementación de la lógica completa de Hundir la Flota**
- Implementacion del acierto con feedback (buzzer).
- Marcaje de los aciertos con el led encendido.
- Tanto acierto como fallo con sonidos diferentes.

**Pendiente:** probarlo en fisico.

## 🧾 Tareas pendientes

- [ ] Diseñar circuito completo en Tinkercad  
- [ ] Mapear coordenadas del joystick a la matriz  
- [ ] Generar barcos aleatorios  
- [ ] Programar impacto/fallo con diferente brillo  
- [ ] Crear condición de victoria  
- [ ] Comentar todo el código  
- [ ] Añadir fotos del montaje  
- [ ] Preparar materiales 
