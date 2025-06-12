#include <Adafruit_CircuitPlayground.h>

// Global Variables
int sequence[5];// Stores the random LED indices
int currentStep = 0;// Tracks player progress through sequence
int flashCount = 1;// start with 1
bool gameActive = false;
bool switchChanged = false;
const int switchPin = 7; // Slide switch pin

// Function Prototypes
void generateSequence();
void playSequence();
void resetGame();
void switchISR();
void playHappyTone();
void playSadTone();
bool checkInput(int ledIndex);

void setup() {
  CircuitPlayground.begin();
  Serial.begin(9600);

  pinMode(switchPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(switchPin), switchISR, CHANGE); //change in switch pin go to ISR and change
  pinMode(4, INPUT_PULLDOWN);
  pinMode(5, INPUT_PULLDOWN);

  generateSequence();
}

void loop() {
  if (switchChanged) {
    delay(10); // debounce
    gameActive = digitalRead(switchPin) == LOW;
    switchChanged = false;
    resetGame();
  }

  if (!gameActive) return; //check if game is still active

  playSequence();
  for (int i = 0; i < flashCount; i++) {
    bool correct = checkInput(sequence[i]);
    if (!correct) {
      playSadTone();
      resetGame();
      return;
    } else {
      playHappyTone();
    }
  }

  delay(300); // small pause before next round
  flashCount++;
  if (flashCount > 5) {
    CircuitPlayground.playTone(880, 300);
    CircuitPlayground.playTone(988, 300);
    CircuitPlayground.playTone(1046, 300);
    resetGame();
  }
}

void generateSequence() {
  for (int i = 0; i < 5; i++) {
    sequence[i] = random(0, 10);
  }
}

void playSequence () {
  for (int i = 0; i < flashCount; i++) {
    int led = sequence[i];
    if (led <= 4) {
      CircuitPlayground.setPixelColor(led, 0, 255, 0); // Green
    } else {
      CircuitPlayground.setPixelColor(led, 255, 0, 0); // Red
    }
    delay(300);
    CircuitPlayground.clearPixels();
    delay(100);
  }
}

bool checkInput(int ledIndex) {
  bool isGreen = (ledIndex <= 4);
  while (true) {
    if (digitalRead(4) == HIGH) return isGreen; //left
    if (digitalRead(5) == HIGH) return !isGreen;//right
  }
}

void resetGame() {
  currentStep = 0;
  flashCount = 1;
  generateSequence();
  CircuitPlayground.clearPixels();
}

void switchISR() {
  switchChanged = true; //flag switch changed
}

void playHappyTone() {
  CircuitPlayground.playTone(523, 100);
}

void playSadTone() {
  CircuitPlayground.playTone(196, 300);
}


