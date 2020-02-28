/*
   LED.h - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#ifndef LED_h
#define LED_h

#include <Component.h>
#include <LazyGalaxy.h>
#include <Timer.h>

class LED : public Component {
 public:
  LED(Pin* pin);
  void setLight(bool flag);
  bool isLight();
  void setBlink(bool flag, unsigned int onDelay = 500,
                unsigned int offDelay = 500);
  bool isBlink();
  void update(unsigned long time);

 private:
  Pin* _pin;
  unsigned int _onDelay = 0;
  unsigned int _offDelay = 0;
};

#endif
