#include <Adafruit_NeoPixel.h>
#include <Metro.h>

#include "TimedInterpolation.h"

//NeoPixel settings
constexpr char NEOPIXEL_PIN = 6;
constexpr char NEOPIXEL_LED_NUM = 64;

Adafruit_NeoPixel strip(NEOPIXEL_LED_NUM, NEOPIXEL_PIN, NEO_GBRW + NEO_KHZ800);
Metro metro(4000);
TimedInterpolation interpolation;

void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.setBrightness(50);
  strip.clear();

  strip.show();
}

void drawSin() {
  float t = interpolation.getElapsedTimeSec();
  int val = 255 * (cos(t * PI * 1.2) * 0.5 + 0.5);
  strip.setPixelColor(27, 0, 0, val, 0);
  strip.setPixelColor(28, 0, 0, val, 0);
  strip.setPixelColor(35, 0, 0, val, 0);
  strip.setPixelColor(36, 0, 0, val, 0);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (metro.check()) {
    strip.clear();
    strip.show();
    interpolation.begin(1500);
  }

  strip.clear();
  float val = NEOPIXEL_LED_NUM * pow(interpolation.get(), 2.0);  
  strip.setPixelColor(val, 255, 0, 0, 0);  // ID, Blue, Green, Red, White
  drawSin();
  strip.show();
}
