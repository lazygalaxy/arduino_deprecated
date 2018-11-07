/*
   L298N.h - Library for L298N dual H-Bridge motor controller.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 23, 2018.
   Released into the public domain.
 */

#ifndef L298N_h
#define L298N_h

#include "Arduino.h"

class L298N {
public:
  L298N(int enA, int in1, int in2, int in3, int in4, int enB);
  void rightMotorOff();
  void rightMotorForward(int speed);
  void rightMotorBack(int speed);
  void leftMotorOff();
  void leftMotorForward(int speed);
  void leftMotorBack(int speed);
  void motorsOff();
  void moveForward(int speed);
  void moveBack(int speed);
  void turnLeft(int speed);
  void turnRight(int speed);

private:
  int _enA;
  int _in1;
  int _in2;
  int _enB;
  int _in3;
  int _in4;
};

#endif
