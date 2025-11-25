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

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW);
}

void loop() {
  handleJoystickButtonAndSound();
  updatePlayerPositionWithJoystick();
  lightSingleLED(playerRow, playerCol);
}

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
