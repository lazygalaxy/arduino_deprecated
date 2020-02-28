/*
   LED.cpp - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#include <LED.h>

LED::LED(Pin* pin) {
  _pin = pin;
  if (_pin->isDigital) {
    pinMode(_pin->number, OUTPUT);
  } else {
    pinMode(A3, OUTPUT);
  }
}

void LED::setLight(bool flag) {
  if (flag) {
    if (_pin->isDigital) {
      digitalWrite(_pin->number, HIGH);
    } else {
      analogWrite(A3, 255);
    }
  } else {
    if (_pin->isDigital) {
      digitalWrite(_pin->number, LOW);
    } else {
      analogWrite(A3, 0);
    }
  };
}

bool LED::isLight() {
  if (_pin->isDigital) {
    return digitalRead(_pin->number) == HIGH;
  } else {
    return analogRead(A3) > 0;
  }
}

void LED::setBlink(bool flag, unsigned int onDelay, unsigned int offDelay) {
  if (flag && !isBlink()) {
    // we would like to start the blink
    _onDelay = onDelay;
    _offDelay = offDelay;
    LED::update(millis());
  } else if (!flag && isBlink()) {
    // we would like to stop the blink
    _onDelay = 0;
    _offDelay = 0;
    setLight(false);
  }
}

bool LED::isBlink() { return _onDelay > 0 && _offDelay > 0; }

void LED::update(unsigned long time) {
  if (isBlink()) {
    if (isLight()) {
      setLight(false);
      // TODO: should somehow update existing timer
      Timer::getInstance()->schedule(_offDelay + time, this);
    } else {
      setLight(true);
      // TODO: should somehow update existing timer
      Timer::getInstance()->schedule(_onDelay + time, this);
    }
  }
}
