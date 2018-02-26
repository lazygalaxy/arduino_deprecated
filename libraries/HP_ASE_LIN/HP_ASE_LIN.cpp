/*
   HP_ASE_LIN.cpp - Library for HP-ASE-LIN Line Tracking Module.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 24, 2018.
   Released into the public domain.
 */

#include "HP_ASE_LIN.h"

HP_ASE_LIN::HP_ASE_LIN(int pin, int threshold) {
  _pin = pin;
  _threshold = threshold;
}

boolean HP_ASE_LIN::isBlack() {
  int sensorValue = analogRead(_pin);
  return sensorValue > _threshold;
}

boolean HP_ASE_LIN::isWhite() {
  int sensorValue = analogRead(_pin);
  return sensorValue <= _threshold;
}
