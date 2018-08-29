/*
   Button.h - Library for Button.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 24, 2018.
   Released into the public domain.
 */

#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
public:
  Button(int pin);
  void updateState();
  int getClicks(int delay = 0);
  boolean isPressed(int duration = 0);

private:
  int _pin;
  unsigned long _firstPressTime = 0;
  unsigned long _lastReleaseTime = 0;
  int _prevValue = HIGH;
  int _clickCounter = 0;
};

#endif
