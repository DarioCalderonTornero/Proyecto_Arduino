// --- Matriz 8x8 ---
const int ROWS = 8;
const int COLS = 8;

const int row[ROWS] = {6, 9, 7, A1, 3, 2, 10, 12};
const int col[COLS] = {5, 11, A0, 13, 4, A2, 8, A3};

// --- Joystick / Buzzer ---
const int VRX = A4;
const int VRY = A5;
const int SW  = 1;      // botón
const int BUZZER = 0;   // sonido

// Cursor del jugador
int playerRow = 0;
int playerCol = 0;

unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150;
const int DEAD_ZONE_MIN = 400;
const int DEAD_ZONE_MAX = 600;

bool lastButtonPressed = false;

// --- Tablero ---
const int CELL_EMPTY = 0;
const int CELL_SHIP  = 1;
const int CELL_HIT   = 2;

int board[ROWS][COLS];
const int NUM_SHIPS = 4;

// --- Vidas ---
const int INITIAL_LIVES = 5;
int lives = INITIAL_LIVES;


// ------------------------------
// Utilidades del tablero
// ------------------------------

void initBoard() {
  for (int r = 0; r < ROWS; r++)
    for (int c = 0; c < COLS; c++)
      board[r][c] = CELL_EMPTY;
}

bool canPlaceShip(int r, int c, int length, bool horizontal) {
  if (horizontal) {
    if (c + length > COLS) return false;
    for (int x = c; x < c + length; x++)
      if (board[r][x] != CELL_EMPTY) return false;
  } else {
    if (r + length > ROWS) return false;
    for (int y = r; y < r + length; y++)
      if (board[y][c] != CELL_EMPTY) return false;
  }
  return true;
}

void placeShip(int r, int c, int length, bool horizontal) {
  if (horizontal)
    for (int x = c; x < c + length; x++) board[r][x] = CELL_SHIP;
  else
    for (int y = r; y < r + length; y++) board[y][c] = CELL_SHIP;
}

void placeAllShips() {
  initBoard();
  for (int s = 0; s < NUM_SHIPS; s++) {
    bool placed = false;
    while (!placed) {
      int length = random(2, 6);
      bool horizontal = random(0, 2) == 0;

      int r = random(0, ROWS - (horizontal ? 0 : length - 1));
      int c = random(0, COLS - (horizontal ? length - 1 : 0));

      if (canPlaceShip(r, c, length, horizontal)) {
        placeShip(r, c, length, horizontal);
        placed = true;
      }
    }
  }
}

bool allShipsHit() {
  for (int r = 0; r < ROWS; r++)
    for (int c = 0; c < COLS; c++)
      if (board[r][c] == CELL_SHIP) return false;
  return true;
}


// ------------------------------
// Efectos visuales
// ------------------------------

void blinkHits(int times) {
  for (int t = 0; t < times; t++) {
    unsigned long endTime = millis() + 200;
    while (millis() < endTime) {
      for (int r = 0; r < ROWS; r++) {
        for (int i = 0; i < ROWS; i++) digitalWrite(row[i], HIGH);
        for (int i = 0; i < COLS; i++) digitalWrite(col[i], LOW);
        digitalWrite(row[r], LOW);
        for (int c = 0; c < COLS; c++)
          digitalWrite(col[c], board[r][c] == CELL_HIT ? HIGH : LOW);
        delayMicroseconds(300);
      }
    }
    for (int i = 0; i < ROWS; i++) digitalWrite(row[i], HIGH);
    for (int i = 0; i < COLS; i++) digitalWrite(col[i], LOW);
    delay(200);
  }
}

void blinkAllLeds(int times) {
  for (int t = 0; t < times; t++) {
    unsigned long endTime = millis() + 200;
    while (millis() < endTime) {
      for (int r = 0; r < ROWS; r++) {
        for (int i = 0; i < ROWS; i++) digitalWrite(row[i], HIGH);
        for (int i = 0; i < COLS; i++) digitalWrite(col[i], LOW);
        digitalWrite(row[r], LOW);
        for (int c = 0; c < COLS; c++) digitalWrite(col[c], HIGH);
        delayMicroseconds(300);
      }
    }
    for (int i = 0; i < ROWS; i++) digitalWrite(row[i], HIGH);
    for (int i = 0; i < COLS; i++) digitalWrite(col[i], LOW);
    delay(200);
  }
}


// ------------------------------
// Reiniciar partida completa
// ------------------------------

void resetGame() {
  playerRow = 0;
  playerCol = 0;
  lives = INITIAL_LIVES;
  placeAllShips();
}



// ------------------------------
// Setup
// ------------------------------

void setup() {
  randomSeed(analogRead(VRX));

  for (int i = 0; i < ROWS; i++) {
    pinMode(row[i], OUTPUT);
    digitalWrite(row[i], HIGH);
  }
  for (int i = 0; i < COLS; i++) {
    pinMode(col[i], OUTPUT);
    digitalWrite(col[i], LOW);
  }

  pinMode(VRX, INPUT);
  pinMode(VRY, INPUT);
  pinMode(SW, INPUT_PULLUP);

  pinMode(BUZZER, OUTPUT);

  resetGame();
}



// ------------------------------
// Mostrar tablero + cursor
// ------------------------------

void displayBoardAndCursor() {
  for (int r = 0; r < ROWS; r++) {
    for (int i = 0; i < ROWS; i++) digitalWrite(row[i], HIGH);
    for (int i = 0; i < COLS; i++) digitalWrite(col[i], LOW);

    digitalWrite(row[r], LOW);

    for (int c = 0; c < COLS; c++) {
      bool hit = board[r][c] == CELL_HIT;
      bool cursor = (r == playerRow && c == playerCol);
      digitalWrite(col[c], hit || cursor ? HIGH : LOW);
    }

    delayMicroseconds(300);
  }
}



// ------------------------------
// Movimiento del cursor
// ------------------------------

void updatePlayerPositionWithJoystick() {
  unsigned long now = millis();
  if (now - lastMoveTime < MOVE_DELAY) return;

  int x = analogRead(VRX);
  int y = analogRead(VRY);
  bool moved = false;

  if (x < DEAD_ZONE_MIN && playerCol > 0) { playerCol--; moved = true; }
  else if (x > DEAD_ZONE_MAX && playerCol < COLS - 1) { playerCol++; moved = true; }

  if (y < DEAD_ZONE_MIN && playerRow > 0) { playerRow--; moved = true; }
  else if (y > DEAD_ZONE_MAX && playerRow < ROWS - 1) { playerRow++; moved = true; }

  if (moved) lastMoveTime = now;
}



// ------------------------------
// Sonidos
// ------------------------------

void playErrorBeep() {
  tone(BUZZER, 400, 120);
  delay(140);
  tone(BUZZER, 250, 150);
  delay(170);
}

void playHitBeep() {
  tone(BUZZER, 700, 80);
  delay(100);
  tone(BUZZER, 1000, 100);
  delay(120);
  tone(BUZZER, 1400, 150);
  delay(170);
}



// ------------------------------
// Lógica del disparo
// ------------------------------

void handleShot() {

  // Si acierta
  if (board[playerRow][playerCol] == CELL_SHIP) {

    board[playerRow][playerCol] = CELL_HIT;
    lives += 2;
    playHitBeep();

    if (allShipsHit()) {
      blinkHits(4);
      resetGame();
    }

  } 
  else {
    // Si falla
    lives -= 1;
    playErrorBeep();

    if (lives <= 0) {
      blinkAllLeds(4);
      resetGame();
    }
  }
}



// ------------------------------
// Botón del joystick
// ------------------------------

void handleJoystickButtonAndSound() {
  bool pressedNow = (digitalRead(SW) == LOW);

  if (pressedNow && !lastButtonPressed)
    handleShot();

  lastButtonPressed = pressedNow;
}



// ------------------------------
// Loop principal
// ------------------------------

void loop() {
  handleJoystickButtonAndSound();
  updatePlayerPositionWithJoystick();
  displayBoardAndCursor();
}
