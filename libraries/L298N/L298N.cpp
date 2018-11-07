/*
   L298N.cpp - Library for L298N dual H-Bridge motor controller.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 23, 2018.
   Released into the public domain.
 */

#include "L298N.h"

L298N::L298N(int enA, int in1, int in2, int in3, int in4, int enB) {
  _enA = enA;
  _in1 = in1;
  _in2 = in2;
  _in3 = in3;
  _in4 = in4;
  _enB = enB;

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);

  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);

  motorsOff();
}

void L298N::rightMotorOff() {
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, LOW);
}

void L298N::rightMotorForward(int speed) {
  digitalWrite(_in1, LOW);
  digitalWrite(_in2, HIGH);
  analogWrite(_enA, speed);
}

void L298N::rightMotorBack(int speed) {
  digitalWrite(_in1, HIGH);
  digitalWrite(_in2, LOW);
  analogWrite(_enA, speed);
}

void L298N::leftMotorOff() {
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, LOW);
}

void L298N::leftMotorForward(int speed) {
  digitalWrite(_in3, LOW);
  digitalWrite(_in4, HIGH);
  analogWrite(_enB, speed);
}

void L298N::leftMotorBack(int speed) {
  digitalWrite(_in3, HIGH);
  digitalWrite(_in4, LOW);
  analogWrite(_enB, speed);
}

void L298N::motorsOff() {
  leftMotorOff();
  rightMotorOff();
}

void L298N::moveForward(int speed) {
  rightMotorForward(speed);
  leftMotorForward(speed);
}

void L298N::moveBack(int speed) {
  rightMotorBack(speed);
  leftMotorBack(speed);
}

void L298N::turnLeft(int speed) {
  rightMotorForward(speed);
  leftMotorBack(speed);
}

void L298N::turnRight(int speed) {
  rightMotorBack(speed);
  leftMotorForward(speed);
}
