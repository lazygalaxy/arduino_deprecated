/*
   NeoPixel.h - Library for ws2812 LED strip.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 7, 2018.
   Released into the public domain.
 */

#ifndef NeoPixel_h
#define NeoPixel_h

#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

class NeoPixel {
public:
  NeoPixel(int digitalPin, int pixels);
  void setup();
  void setColor(int pixel, int red, int green, int blue, bool mustShow = true);
  void off(int delayMicros);
  void wipeSequence(int red, int green, int blue, int delayMicros = 0,
                    bool reverse = false);
  void noSequence(int red, int green, int blue, int delayMicros = 0);

private:
  Adafruit_NeoPixel _strip;
};

#endif
