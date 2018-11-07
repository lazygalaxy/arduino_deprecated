/*
   HC_SR04.cpp - Library for HC-SR04 ultrasonic sensor module.
   Created by LazyGalaxy - Evangelos Papakonstantis, March 25, 2018.
   Released into the public domain.
 */

#include "HC_SR04.h"

HC_SR04::HC_SR04(int trig, int echo) {
  _trig = trig;
  _echo = echo;

  pinMode(_trig, OUTPUT);
  pinMode(_echo, INPUT);
}

int HC_SR04::getDistance() {
  // Clears the trigPin
  digitalWrite(_trig, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(_trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(_trig, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  long duration = pulseIn(_echo, HIGH);
  // Calculating the distance
  return duration / 58.2;
}
