
const int ROWS = 8;
const int COLS = 8;

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

const int VRX = A4;  
const int VRY = A5;   
const int SW  = 1;    


int playerRow = 0;  
int playerCol = 0;  


unsigned long lastMoveTime = 0;
const unsigned long MOVE_DELAY = 150; 
const int DEAD_ZONE_MIN = 400;   
const int DEAD_ZONE_MAX = 600;

void setup() {
  
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
}

void loop() {
  
  updatePlayerPositionWithJoystick();

  
  lightSingleLED(playerRow, playerCol);
}


void updatePlayerPositionWithJoystick() {
  unsigned long now = millis();

 
  if (now - lastMoveTime < MOVE_DELAY) return;

  int x = analogRead(VRX); // 0 - 1023
  int y = analogRead(VRY); // 0 - 1023

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
