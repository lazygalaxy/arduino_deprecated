/*
   LED.h - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#ifndef LED_h
#define LED_h

#include "Arduino.h"

class LED {
 public:
  LED(unsigned char pin);
  void setLightOn(bool flag);
  bool isLightOn();
  void setBlinkOn(bool flag, unsigned int onDelay = 500,
                  unsigned int offDelay = 500);
  bool isBlinkOn();
  void update();

 private:
  unsigned char _pin;
  unsigned int _onDelay = 0;
  unsigned int _offDelay = 0;
  unsigned long _time = 0;
};

#endif