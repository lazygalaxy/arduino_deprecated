/*
   LED.h - Library for lighting a LED.
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#ifndef LED_h
#define LED_h

#include <Component.h>
#include <LazyGalaxy.h>

class LED : public Component {
 public:
  LED(unsigned char pin);
  void setLightOn(bool flag);
  bool isLightOn();
  void setBlinkOn(bool flag, unsigned int onDelay = 500,
                  unsigned int offDelay = 500);
  bool isBlinkOn();
  void update(unsigned long time);

 private:
  unsigned char _pin;
  unsigned int _onDelay = 0;
  unsigned int _offDelay = 0;
};

#endif
