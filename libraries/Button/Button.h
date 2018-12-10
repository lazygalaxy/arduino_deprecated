/*
   Button.h - Library for a momentary button configured as a pullup.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 24, 2018.
   Released into the public domain.
 */

#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
public:
  Button(int digitalClickPin, int digitalLEDPin = -1);
  int getClicks(int delay = 200);
  boolean isLongPressed(int duration);

  bool isOn();
  void setOn(bool buttonOn);

private:
  int _digitalClickPin = -1;
  int _digitalLEDPin = -1;
  unsigned long _pressTime = 0;
  unsigned long _releaseTime = 0;
  int _prevValue = HIGH;
  int _clickCounter = 0;
  boolean _buttonOn = false;
  boolean _longPressed = false;
};

#endif
