/*
   Button.cpp - Library for a momentary button configured as a pullup.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 24, 2018.
   Released into the public domain.
 */

#include "Button.h"

Button::Button(int digitalClickPin, int digitalLEDPin) {
  _digitalClickPin = digitalClickPin;
  _digitalLEDPin = digitalLEDPin;

  pinMode(_digitalClickPin, INPUT_PULLUP);

  if (_digitalLEDPin > 0) {
    pinMode(_digitalLEDPin, OUTPUT);
    digitalWrite(_digitalLEDPin, 0);
  }
}

int Button::getClicks(int delay) {
  unsigned long time = millis();
  int value = digitalRead(_digitalClickPin);

  if (value == LOW && _pressTime == 0) {
    _pressTime = time;
    _releaseTime = 0;
  } else if (value == HIGH && _prevValue == LOW) {
    _clickCounter += 1;
    _releaseTime = time;
    _pressTime = 0;
  }

  if (_releaseTime != 0 && (time - _releaseTime) >= delay) {
    int clickCounter = _clickCounter;

    if (_longPressed) {
      clickCounter = 0;
    }

    _releaseTime = 0;
    _pressTime = 0;
    _prevValue = HIGH;
    _clickCounter = 0;
    _longPressed = false;

    return clickCounter;
  }

  _prevValue = value;
  return 0;
}

boolean Button::isLongPressed(int duration) {
  int value = digitalRead(_digitalClickPin);
  if (value == LOW) {
    unsigned long time = millis();
    _longPressed = (_clickCounter == 0 && _pressTime != 0 &&
                    (time - _pressTime) >= duration);
    return _longPressed;
  }
  return false;
}

bool Button::isOn() { return _buttonOn; }

void Button::setOn(bool buttonOn) {
  _buttonOn = buttonOn;
  if (_digitalLEDPin > 0 && buttonOn) {
    digitalWrite(_digitalLEDPin, HIGH);
  } else if (_digitalLEDPin > 0 && !buttonOn) {
    digitalWrite(_digitalLEDPin, LOW);
  }
}
