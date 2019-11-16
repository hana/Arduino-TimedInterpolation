#include <TimedInterpolation.h>

constexpr unsigned char LED_PIN = 5;

TimedInterpolation interpolation;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  interpolation.begin();
}

void loop() {
  float p = sin(interpolation.getElapsedTimeSec() * 2.0) * 0.5 + 0.5; //0.0 ~ 1.0 
  analogWrite(LED_PIN, p * 255);
}
