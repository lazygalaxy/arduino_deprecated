/*
RGB_LED.h - Library for RGB LED Module.
Created by LazyGalaxy - Evangelos Papakonstantis, August 24, 2018.
Released into the public domain.
 */

#ifndef RGB_LED_h
#define RGB_LED_h

#include "Arduino.h"

class RGB_LED {
public:
  RGB_LED(int redPin, int greenPin, int bluePin);
  void setColor(int red, int green, int blue);
  void off();

private:
  int _redPin;
  int _greenPin;
  int _bluePin;
};

#endif
