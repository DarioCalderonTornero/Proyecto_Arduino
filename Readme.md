# Proyecto: Hundir la Flota Físico (Arduino)

## Equipo

- **Juan** — Programador  
- **Darío** — Programador  

Ambos participamos en la parte de programación, pruebas y montaje del prototipo físico.

---

## Objetivo del proyecto

Crear una versión física y en solitario del clásico **Hundir la Flota**, usando un **joystick analógico** para seleccionar casillas y una **matriz LED 8×8 (1588BS)** como tablero enemigo.

El sistema colocará los “barcos” aleatoriamente en la matriz. El jugador se moverá por las casillas con el joystick y, al pulsarlo, realizará el disparo:

- Si acierta → el LED de esa casilla se ilumina con **máxima intensidad**.
- Si falla → el LED se enciende con **baja luminosidad** para marcar el fallo.

---

## Descripción general

- El Arduino genera **posiciones aleatorias** para los barcos en la matriz 8×8.
- El **joystick** controla la posición actual del “cursor” sobre el tablero (ejes X/Y).
- El **botón del joystick** confirma el disparo en la casilla seleccionada.
- La **matriz 8×8 1588BS** actúa como tablero visual:
  - Impacto: LED encendido con brillo alto.
  - Agua: LED encendido con brillo bajo.
- El objetivo del jugador es **localizar todos los barcos** con el menor número de intentos posibles.

Este proyecto integra sensores y actuadores para crear una experiencia de juego física interactiva, acorde con la guía de Computación Física.

---

## Componentes

### Sensores y actuadores

- **Joystick analógico de Arduino** (ejes X/Y + pulsador).
- **Matriz LED 8×8 1588BS**.

### Otros componentes

- Placa **Arduino** (UNO o compatible).
- Protoboard.
- Cables puente (M-M / M-H).
- Resistencias (según el montaje de la matriz y el joystick).

> La descripción detallada del hardware y las conexiones se documentará en `hardware.md`.

---

## Entregables en el repositorio

- `README.md` (este documento), que actuará como:
  - Descripción del proyecto.
  - Definición de objetivo y alcance mínimo.
  - Presentación del equipo y roles.
  - Bitácora de trabajo (sesión a sesión).
  - Estado actual y tareas pendientes.

- **Boceto del circuito en Tinkercad/Fritzing**:
  - Esquema de conexión de joystick y matriz 8×8 a Arduino.
  - Capturas de pantalla del circuito.
  - Código de Arduino asociado al boceto.

- `hardware.md`:
  - Lista de sensores y actuadores.
  - Lista de componentes (resistencias, cables, protoboard, etc.).
  - Esquema de conexiones (texto y/o capturas del esquema).

- Carpeta de código (por ejemplo `/src` o `/arduino`):
  - Código fuente de Arduino para el juego.

- Material opcional:
  - Imágenes del montaje físico.
  - Vídeo corto del prototipo en funcionamiento (útil para la LiveDemo).

---

## Estado actual del proyecto

**Sprint 1**

- Idea del proyecto definida: Hundir la Flota físico en solitario con joystick + matriz 8×8.
- Equipo formado y roles acordados (ambos programadores).
- Primera versión del README creada.
- Pruebas iniciales:
  - Lectura del joystick (movimiento por ejes X/Y y pulsador).
  - Encendido simple de LEDs en la matriz (test de funcionamiento).

*(Esta sección se irá actualizando a medida que avancemos.)*

---

## Plan de trabajo (sprints)

### Sprint 1 (hasta 25/11)

- Definir claramente el objetivo y el alcance mínimo.
- Crear el primer boceto en Tinkercad/Fritzing con:
  - Joystick conectado a Arduino.
  - Matriz 8×8 conectada a Arduino.
- Primeras pruebas de código:
  - Lectura de joystick.
  - Encendido básico de LEDs en la matriz.
- Iniciar el README y la bitácora.

### Sprint 2 (26/11 – 04/12)

- Implementar el movimiento del “cursor” por el tablero usando el joystick.
- Implementar el disparo al pulsar el joystick (selección de casilla).
- Añadir lógica de:
  - Colocación aleatoria de barcos.
  - Detección de impacto/fallo.
  - Diferencias de brillo en los LEDs según resultado.
- Completar y subir `hardware.md` con la lista de sensores y componentes.
- Actualizar la bitácora con los problemas encontrados y soluciones.

### LiveDemo (05/12 – 16/12)

- Ajuste final del comportamiento del juego (tiempos, sensibilidad del joystick, brillo de LEDs).
- Pruebas de estabilidad del circuito físico (cables, contactos, ruido).
- Preparar una breve presentación:
  - Explicación del objetivo y funcionamiento del juego.
  - Explicación básica del circuito.
  - Resumen del código.
- Grabar, si es posible, un vídeo corto del prototipo funcionando para respaldo.

---

## Bitácora de trabajo (ejemplo inicial)

> Esta sección funcionará como diario del proyecto. Se irán añadiendo entradas por fecha.

**23/11 – Definición del proyecto**  
- Se decide el tema del proyecto: Hundir la Flota físico en solitario.  
- Se confirman los componentes principales: joystick + matriz LED 8×8 1588BS.  
- Se revisa la guía de Computación Física para adaptar los entregables.

**24/11 – Primeras pruebas de hardware**  
- Lectura correcta de los valores del joystick (X, Y, botón).  
- Primera prueba de encendido de LEDs en la matriz para verificar conexiones.  

*(Se seguirán añadiendo sesiones nuevas.)*

---

## Tareas pendientes

- [ ] Terminar el diseño completo del circuito en Tinkercad/Fritzing.  
- [ ] Mapear correctamente las coordenadas del joystick a la matriz 8×8.  
- [ ] Implementar la colocación aleatoria de barcos en la matriz.  
- [ ] Programar el sistema de impacto/fallo con diferentes niveles de brillo.  
- [ ] Añadir condiciones de victoria (todos los barcos hundidos).  
- [ ] Documentar el código y comentar las funciones principales.  
- [ ] Añadir imágenes del montaje físico al repositorio.  
- [ ] Preparar el material para la presentación de la LiveDemo.
