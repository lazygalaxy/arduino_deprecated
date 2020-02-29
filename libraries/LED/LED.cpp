/*
   LED.cpp - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#include <LED.h>

LED::LED(uint8_t pin) {
  _pin = pin;
  pinMode(_pin, OUTPUT);
}

bool LED::isDigital() { return _pin < 14; }

void LED::setLight(bool flag) {
  if (flag) {
    if (isDigital()) {
      digitalWrite(_pin, HIGH);
    } else {
      analogWrite(_pin, 255);
    }
  } else {
    if (isDigital()) {
      digitalWrite(_pin, LOW);
    } else {
      analogWrite(_pin, 0);
    }
  };
}

bool LED::isLight() {
  if (isDigital()) {
    return digitalRead(_pin) == HIGH;
  } else {
    return analogRead(_pin) > 0;
  }
}

void LED::setBlink(bool flag, unsigned int blinkDelay) {
  if (flag && !isBlink()) {
    // we would like to start the blink
    _delayTaskId =
        Timer::getInstance()->schedule(blinkDelay + millis(), this, blinkDelay);
  } else if (!flag && isBlink()) {
    // we would like to stop the blink
    if (Timer::getInstance()->unschedule(_delayTaskId)) {
      _delayTaskId = 0;
      setLight(false);
    }
  }
}

bool LED::isBlink() { return _delayTaskId > 0; }

void LED::update(unsigned long time) {
  if (isBlink()) {
    if (isLight()) {
      setLight(false);
    } else {
      setLight(true);
    }
  }
}
