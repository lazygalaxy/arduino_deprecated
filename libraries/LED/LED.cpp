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
    _onDelay = onDelay;
    _offDelay = offDelay;
    LED::update(millis());
  } else if (!flag && isBlinkOn()) {
    // we would like to stop the blink
    _onDelay = 0;
    _offDelay = 0;
    setLightOn(false);
  }
}

bool LED::isBlinkOn() { return _onDelay > 0 && _offDelay > 0; }

void LED::update(unsigned long time) {
  if (isBlinkOn()) {
    if (isLightOn()) {
      setLightOn(false);
      scheduleTask(_offDelay + time, this);
    } else {
      setLightOn(true);
      scheduleTask(_onDelay + time, this);
    }
  }
}
