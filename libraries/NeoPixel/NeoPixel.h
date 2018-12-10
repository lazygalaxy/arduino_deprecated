/*
   NeoPixel.h - Library for ws2812 LED strip.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 7, 2018.
   Released into the public domain.
 */

#ifndef NeoPixel_h
#define NeoPixel_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>
#include <math.h>

class NeoPixel {
public:
  NeoPixel(int digitalPin, int pixels);
  void setup();
  void setRGBColor(int pixel, int red, int green, int blue,
                   bool mustShow = true);
  void setHSVColor(int pixel, int hue, double saturation, double value,
                   bool mustShow = true);
  void off(int delayMicros = 0);
  void wipeSequence(int hue, double saturation, double value,
                    int delayMicros = 0, double probability = 1.0,
                    bool reverse = false);
  void chaseSequence(int hue, double saturation, double value,
                     int delayMicros = 0, int cycles = 1);
  void rainbowSequence(double saturation, double value, int delayMicros = 0,
                       int cycles = 1);
  void noSequence(int hue, double saturation, double value, int delayMicros = 0,
                  double probability = 1.0);

private:
  Adafruit_NeoPixel _strip;
};

#endif
