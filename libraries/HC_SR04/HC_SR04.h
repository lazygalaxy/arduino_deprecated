/*
   HC_SR04.h - Library for HC-SR04 ultrasonic sensor module.
   Created by LazyGalaxy - Evangelos Papakonstantis, March 25, 2018.
   Released into the public domain.
 */

#ifndef HC_SR04_h
#define HC_SR04_h

#include "Arduino.h"

class HC_SR04 {
public:
  HC_SR04(int trig, int echo);
  int getDistance();

private:
  int _trig;
  int _echo;
};

#endif
