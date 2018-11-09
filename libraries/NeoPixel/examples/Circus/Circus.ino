/*
   Circus.ino - Example on how to use the LazyGalaxy NeoPixel library.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 8, 2018.
   Released into the public domain.
*/

#include <NeoPixel.h>

NeoPixel strip(5, 30);

void setup() {
  Serial.begin(9600);
  strip.setup();
}

void loop() {
  strip.wipeSequence(255, 255, 255, 20);
  strip.wipeSequence(255, 255, 0, 20, true);
  strip.wipeSequence(255, 0, 255, 20);
  strip.wipeSequence(255, 0, 0, 20, true);
  strip.wipeSequence(0, 255, 255, 20);
  strip.wipeSequence(0, 255, 0, 20, true);
  strip.wipeSequence(0, 0, 255, 20);
  strip.wipeSequence(0, 0, 0, 20, true);

  strip.noSequence(255, 255, 255, 1000);
  strip.noSequence(255, 255, 0, 1000);
  strip.noSequence(255, 0, 255, 1000);
  strip.noSequence(255, 0, 0, 1000);
  strip.noSequence(0, 255, 255, 1000);
  strip.noSequence(0, 255, 0, 1000);
  strip.noSequence(0, 0, 255, 1000);
  strip.noSequence(0, 0, 0, 1000);
}
