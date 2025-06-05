#include <AsyncDelay.h>

AsyncDelay delay_1s;
volatile int count = 0;

void setup(void) {
  Serial.begin(9600);
  while (!Serial); // Wait for Serial Monitor to open
  Serial.println("Starting 1s timer...");

  delay_1s.start(1000, AsyncDelay::MILLIS); // Start 1s async delay
}

void loop(void) {
  if (delay_1s.isExpired()) {
    Serial.println(++count);  // Pre-increment: prints incremented value
    delay_1s.repeat();        // Restart the 1s delay
  }
}
// Serial.println(++count); increment before print, output at 1
//Serial.println(count++); prints before increment, output starts at 0