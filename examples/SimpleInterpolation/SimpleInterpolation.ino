#include <TimedInterpolation.h>

constexpr char LED_PIN = 5;
constexpr unsigned int INTERPOLATION_TIME = 3000;

TimedInterpolation interpolation;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  interpolation.begin(INTERPOLATION_TIME);
}

void loop() {
  float v = interpolation.get();
  analogWrite(LED_PIN, 255 * v);

  if (v >= 1.0) { //restart
    interpolation.begin(INTERPOLATION_TIME);
  }
}
