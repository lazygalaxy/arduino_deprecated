/*
   Button.cpp - Library for Button.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 24, 2018.
   Released into the public domain.
 */

#include "Button.h"

Button::Button(int pin) {
  _pin = pin;

  pinMode(_pin, INPUT_PULLUP);
}

boolean Button::isPressed(int duration) {
  unsigned long time = millis();
  int value = digitalRead(_pin);
  if (value == LOW) {
    if (_firstPressTime == 0) {
      _firstPressTime = time;
    }
    return time - _firstPressTime > duration;
  } else {
    _firstPressTime = 0;
  }
  return false;
}
