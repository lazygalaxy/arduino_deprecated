/*
   Lesson 1.1 - Using LEDs
   Created by LazyGalaxy - Evangelos Papakonstantis, January 29, 2020.
   Released into the public domain.
 */

#include <LED.h>
#include <Timer.h>

LED led1(3);
LED led2(5);
Timer timer;

void setup() {
  Serial.begin(9600);
  led1.setLightOn(true);
  led2.setBlinkOn(true);
  timer.schedule(3000, swap);
  timer.schedule(6000, stop);
}

void loop() {
  led1.update();
  led2.update();
  timer.update();
}

void swap() {
  stop();
  led1.setBlinkOn(true);
  led2.setLightOn(true);
}

void stop() {
  led1.setLightOn(false);
  led1.setBlinkOn(false);
  led2.setLightOn(false);
  led2.setBlinkOn(false);
}
