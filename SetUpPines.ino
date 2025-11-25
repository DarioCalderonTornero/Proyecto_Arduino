// -----------------------------
// Configuración matriz 8x8 1588BS
// -----------------------------
const int ROWS = 8;
const int COLS = 8;

// FILAS (en orden fila 1 → fila 8)
const int row[ROWS] = {
  6,    // fila 1
  9,    // fila 2
  7,    // fila 3
  A1,   // fila 4
  3,    // fila 5
  2,    // fila 6
  10,   // fila 7
  12    // fila 8
};

// COLUMNAS (en orden columna 1 → columna 8)
const int col[COLS] = {
  5,    // columna 1
  11,   // columna 2
  A0,   // columna 3
  13,   // columna 4
  4,    // columna 5
  A2,   // columna 6
  8,    // columna 7
  A3    // columna 8
};

// -----------------------------
// Joystick
// -----------------------------
const int VRX = A4;   // Horizontal
const int VRY = A5;   // Vertical
const int SW  = 1;    // Botón (mejor usar otro pin si puedes; el 1 es TX)

// Posición actual del "cursor" (LED encendido)
int playerRow = 0;  // 0 = primera fila del array row[]
int playerCol = 0;  // 0 = primera columna del array col[]

// Control de velocidad de movimiento
unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150; // ms entre movimientos
const int DEAD_ZONE_MIN = 400;        // zona muerta del joystick
const int DEAD_ZONE_MAX = 600;

void setup() {
  // Configurar pines de la matriz
  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);  // Apagamos (asumimos LED ON = row LOW & col HIGH)
  }
  for (int i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW);   // Apagamos columnas
  }

  // Joystick
  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);  // Botón pulsado = LOW
}

void loop() {
  // 1. Leer joystick y actualizar posición
  updatePlayerPositionWithJoystick();

  // 2. Encender sólo el LED en (playerRow, playerCol)
  lightSingleLED(playerRow, playerCol);
}

// ---------------------------------
// Mueve el "cursor" según el joystick
// ---------------------------------
void updatePlayerPositionWithJoystick() {
  unsigned long now = millis();

  // Solo movemos si ha pasado un tiempo (para no ir volando)
  if (now - lastMoveTime < MOVE_DELAY) return;

  int x = analogRead(VRX); // 0 - 1023
  int y = analogRead(VRY); // 0 - 1023

  bool moved = false;

  // EJE X → izquierda/derecha (columnas)
  if (x < DEAD_ZONE_MIN) {
    // Mover a la izquierda
    if (playerCol > 0) {
      playerCol--;
      moved = true;
    }
  } else if (x > DEAD_ZONE_MAX) {
    // Mover a la derecha
    if (playerCol < COLS - 1) {
      playerCol++;
      moved = true;
    }
  }

  // EJE Y → arriba/abajo (filas)
  // Ojo: según cómo tengas el joystick, puedes invertir arriba/abajo
  if (y < DEAD_ZONE_MIN) {
    // Por ejemplo: y pequeño = arriba
    if (playerRow > 0) {
      playerRow--;
      moved = true;
    }
  } else if (y > DEAD_ZONE_MAX) {
    // y grande = abajo
    if (playerRow < ROWS - 1) {
      playerRow++;
      moved = true;
    }
  }

  if (moved) {
    lastMoveTime = now;
  }
}

// ---------------------------------
// Enciende solo el LED (r, c)
// ---------------------------------
void lightSingleLED(int r, int c) {
  // Apagar todo
  for (int i = 0; i < ROWS; i++) {
    digitalWrite(row[i], HIGH); // OFF (asumimos ON = LOW)
  }
  for (int i = 0; i < COLS; i++) {
    digitalWrite(col[i], LOW);  // OFF (asumimos ON = HIGH)
  }

  // Encender sólo el LED elegido
  digitalWrite(col[c], HIGH); // columna activa
  digitalWrite(row[r], LOW);  // fila activa
}
