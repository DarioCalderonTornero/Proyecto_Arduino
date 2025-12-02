const int ROWS = 8;
const int COLS = 8;

const int row[ROWS] = {
  6,
  9,
  7,
  A1,
  3,
  2,
  10,
  12
};

const int col[COLS] = {
  5,
  11,
  A0,
  13,
  4,
  A2,
  8,
  A3
};

const int VRX = A4;
const int VRY = A5;
const int SW  = 1;   
const int BUZZER = 0; 

int playerRow = 0;
int playerCol = 0;

unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150;
const int DEAD_ZONE_MIN = 400;
const int DEAD_ZONE_MAX = 600;

bool lastButtonPressed = false;

// -------------------------
// LÓGICA DEL TABLERO
// -------------------------


const int CELL_EMPTY = 0;
const int CELL_SHIP  = 1;

int board[ROWS][COLS];   
const int NUM_SHIPS = 4;

void initBoard() {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      board[r][c] = CELL_EMPTY;
    }
  }
}


bool canPlaceShip(int startRow, int startCol, int length, bool horizontal) {
  if (horizontal) {
    if (startCol + length > COLS) return false;
    for (int c = startCol; c < startCol + length; c++) {
      if (board[startRow][c] != CELL_EMPTY) {
        return false; // 
      }
    }
  } else {
    if (startRow + length > ROWS) return false;
    for (int r = startRow; r < startRow + length; r++) {
      if (board[r][startCol] != CELL_EMPTY) {
        return false; 
      }
    }
  }
  return true;
}

void placeShip(int startRow, int startCol, int length, bool horizontal) {
  if (horizontal) {
    for (int c = startCol; c < startCol + length; c++) {
      board[startRow][c] = CELL_SHIP;
    }
  } else {
    for (int r = startRow; r < startRow + length; r++) {
      board[r][startCol] = CELL_SHIP;
    }
  }
}

void placeAllShips() {
  initBoard();

  for (int s = 0; s < NUM_SHIPS; s++) {
    bool placed = false;

    while (!placed) {
      int length = random(2, 6); 
      bool horizontal = (random(0, 2) == 0); 

      int startRow, startCol;

      if (horizontal) {
        startRow = random(0, ROWS);              
        startCol = random(0, COLS - length + 1);  
      } else {
        startRow = random(0, ROWS - length + 1);
        startCol = random(0, COLS);               
      }

      if (canPlaceShip(startRow, startCol, length, horizontal)) {
        placeShip(startRow, startCol, length, horizontal);
        placed = true;
      }
      
    }
  }
}


void printBoardToSerial() {
  Serial.println(F("Tablero (1 = barco, 0 = vacío):"));
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      Serial.print(board[r][c]);
      Serial.print(" ");
    }
    Serial.println();
  }
  Serial.println();
}

// -------------------------
// SETUP / LOOP
// -------------------------

void setup() {
  Serial.begin(9600);

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
  digitalWrite(BUZZER, LOW);

  placeAllShips();

  printBoardToSerial();
}

void loop() {
  handleJoystickButtonAndSound();
  updatePlayerPositionWithJoystick();
  lightSingleLED(playerRow, playerCol);
}

// -------------------------
// JOYSTICK Y MATRIZ
// -------------------------

void updatePlayerPositionWithJoystick() {
  unsigned long now = millis();
  if (now - lastMoveTime < MOVE_DELAY) return;

  int x = analogRead(VRX);
  int y = analogRead(VRY);

  bool moved = false;

  if (x < DEAD_ZONE_MIN) {
    if (playerCol > 0) {
      playerCol--;
      moved = true;
    }
  } else if (x > DEAD_ZONE_MAX) {
    if (playerCol < COLS - 1) {
      playerCol++;
      moved = true;
    }
  }

  if (y < DEAD_ZONE_MIN) {
    if (playerRow > 0) {
      playerRow--;
      moved = true;
    }
  } else if (y > DEAD_ZONE_MAX) {
    if (playerRow < ROWS - 1) {
      playerRow++;
      moved = true;
    }
  }

  if (moved) {
    lastMoveTime = now;
  }
}

void lightSingleLED(int r, int c) {

  for (int i = 0; i < ROWS; i++) {
    digitalWrite(row[i], HIGH);
  }
  for (int i = 0; i < COLS; i++) {
    digitalWrite(col[i], LOW);
  }

  digitalWrite(col[c], HIGH);
  digitalWrite(row[r], LOW);
}

void handleJoystickButtonAndSound() {
  bool pressedNow = (digitalRead(SW) == LOW);
  if (pressedNow && !lastButtonPressed) {
    playErrorBeep();
    
  }
  lastButtonPressed = pressedNow;
}

void playErrorBeep() {
  tone(BUZZER, 500, 120);
}
