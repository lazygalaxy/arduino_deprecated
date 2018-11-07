/*
   HP_ASE_LIN.h - Library for HP-ASE-LIN line tracking module.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 24, 2018.
   Released into the public domain.
 */

#ifndef HP_ASE_LIN_h
#define HP_ASE_LIN_h

#include "Arduino.h"

class HP_ASE_LIN {
public:
  HP_ASE_LIN(int pin, int threshold);
  boolean isBlack();
  boolean isWhite();

private:
  int _pin;
  int _threshold;
};

#endif
