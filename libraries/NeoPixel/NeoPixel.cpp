/*
   NeoPixel.cpp - Library for ws2812 LED strip.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 7, 2018.
   Released into the public domain.
 */

#include "NeoPixel.h"

NeoPixel::NeoPixel(int digitalPin, int pixels) {
  _strip = Adafruit_NeoPixel(pixels, digitalPin, NEO_GRB + NEO_KHZ800);
}

void NeoPixel::setup() {
  _strip.begin();
  _strip.show();
}

void NeoPixel::setColor(int pixel, int red, int green, int blue,
                        bool mustShow) {
  _strip.setPixelColor(pixel, _strip.Color(red, green, blue));
  if (mustShow) {
    _strip.show();
  }
}

void NeoPixel::off(int delayMicros) {
  for (int i = 0; i < _strip.numPixels(); i++) {
    setColor(i, 0, 0, 0, false);
  }
  _strip.show();
  delay(delayMicros);
}

void NeoPixel::wipeSequence(int red, int green, int blue, int delayMicros,
                            bool reverse) {
  for (int i = 0; i < _strip.numPixels(); i++) {
    int index = i;
    if (reverse) {
      index = _strip.numPixels() - i - 1;
    }
    setColor(index, red, green, blue);
    delay(delayMicros);
  }
}

void NeoPixel::noSequence(int red, int green, int blue, int delayMicros) {
  for (int i = 0; i < _strip.numPixels(); i++) {
    setColor(i, red, green, blue, false);
  }
  _strip.show();
  delay(delayMicros);
}
