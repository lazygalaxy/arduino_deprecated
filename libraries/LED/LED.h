/*
   LED.h - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#ifndef LED_h
#define LED_h

#include <Arduino.h>
#include <LazyGalaxy.h>

class LED : public Component {
 public:
  LED(uint8_t pin);
  void setLight(bool flag);
  bool isLight();
  void setBlink(bool flag, unsigned int blinkDelay = 500);
  bool isBlink();
  void update(unsigned long time);

 private:
  bool isDigital();
  uint8_t _pin;
  unsigned long _delayTaskId = 0;
};

#endif
