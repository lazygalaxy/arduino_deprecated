/*
   Circus.ino - Example on how to use the LazyGalaxy NeoPixel library.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 8, 2018.
   Released into the public domain.
*/

#include <NeoPixel.h>

const NeoPixel strip(10, 123);

void setup() {
  Serial.begin(9600);
  strip.setup();
}

void loop() {

  strip.off();
  strip.chaseSequence(0, 1.0, 1.0, 0, 10);
  strip.chaseSequence(90, 1.0, 1.0, 0, 10);
  strip.chaseSequence(180, 1.0, 1.0, 0, 10);
  strip.chaseSequence(270, 1.0, 1.0, 0, 10);

  double prob = 1.0;
  strip.off();
  strip.wipeSequence(0, 0.0, 1.0, 20, prob);
  strip.wipeSequence(0, 1.0, 1.0, 20, prob, true);
  strip.wipeSequence(90, 1.0, 1.0, 20, prob);
  strip.wipeSequence(180, 1.0, 1.0, 20, prob, true);
  strip.wipeSequence(270, 1.0, 1.0, 20, prob);
  strip.wipeSequence(0, 1.0, 0.0, 20, prob, true);

  strip.off();
  strip.noSequence(0, 0.0, 1.0, 1000);
  strip.noSequence(0, 1.0, 1.0, 1000);
  strip.noSequence(90, 1.0, 1.0, 1000);
  strip.noSequence(180, 1.0, 1.0, 1000);
  strip.noSequence(270, 1.0, 1.0, 1000);
}
