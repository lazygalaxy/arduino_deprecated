/*
   Button.cpp - Library for a momentary button configured as a pullup.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 24, 2018.
   Released into the public domain.
 */

#include "Button.h"

Button::Button(int pin) {
  _pin = pin;

  pinMode(_pin, INPUT_PULLUP);
}

void Button::updateState() {
  unsigned long time = millis();
  int value = digitalRead(_pin);
  if (value == LOW) {
    if (_firstPressTime == 0) {
      _firstPressTime = time;
      _lastReleaseTime = 0;
    }
  } else {
    if (_prevValue == LOW) {
      _clickCounter += 1;
      _lastReleaseTime = time;
      _firstPressTime = 0;
    }
  }
  _prevValue = value;
}

int Button::getClicks(int delay) {
  unsigned long time = millis();
  if (_lastReleaseTime != 0 && (time - _lastReleaseTime) >= delay) {
    _lastReleaseTime = 0;
    _firstPressTime = 0;

    int temp = _clickCounter;
    _clickCounter = 0;
    return temp;
  }
  return 0;
}

boolean Button::isPressed(int duration) {
  unsigned long time = millis();
  return (_firstPressTime != 0 && (time - _firstPressTime) >= duration);
}
