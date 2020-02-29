/*
   Lesson 1.1 - Using LEDs
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#include <LED.h>
#include <LazyGalaxy.h>

LED led1(D3);
LED led2(D7);
LED led3(A3);

void setup() {
  Serial.begin(9600);
  scheduleTask(0, lightOn);
  scheduleTask(3000, lightOff);
  scheduleTask(6000, blinkOn);
  scheduleTask(9000, blinkOff);
}

void loop() { update(); }

void blinkOn() {
  led1.setBlink(true);
  led2.setBlink(true);
  led3.setBlink(true);
}

void blinkOff() {
  led1.setBlink(false);
  led2.setBlink(false);
  led3.setBlink(false);
}

void lightOn() {
  led1.setLight(true);
  led2.setLight(true);
  led3.setLight(true);
}

void lightOff() {
  led1.setLight(false);
  led2.setLight(false);
  led3.setLight(false);
}
