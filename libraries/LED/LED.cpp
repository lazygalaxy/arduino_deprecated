/*
   LED.cpp - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#include <LED.h>

LED::LED(unsigned char pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
  setLightOn(false);
}

void LED::setLightOn(bool flag) {
  if (flag) {
    digitalWrite(_pin, HIGH);
  } else {
    digitalWrite(_pin, LOW);
  };
}

bool LED::isLightOn() { return digitalRead(_pin) == HIGH; }

void LED::setBlinkOn(bool flag, unsigned int onDelay = 500,
                     unsigned int offDelay = 500) {
  if (flag && !isBlinkOn()) {
    // we would like to start the blink
    setLightOn(true);
    _onDelay = onDelay;
    _offDelay = offDelay;
    _time = millis();
  } else if (!flag && isBlinkOn()) {
    // we would like to stop the blink
    setLightOn(false);
    _onDelay = 0;
    _offDelay = 0;
  }
}

bool LED::isBlinkOn() { return _onDelay > 0 && _offDelay; }

void LED::update() {
  if (isBlinkOn()) {
    // update the blink
    unsigned long time = millis();
    if (isLightOn() && time >= _time + _onDelay) {
      setLightOn(false);
      _time = time;
    } else if (!isLightOn() && time >= _time + _offDelay) {
      setLightOn(true);
      _time = time;
    }
  }
}
