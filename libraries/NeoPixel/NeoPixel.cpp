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

void NeoPixel::setRGBColor(int pixel, int red, int green, int blue,
                           bool mustShow) {
  _strip.setPixelColor(pixel, _strip.Color(red, green, blue));
  if (mustShow) {
    _strip.show();
  }
}

void NeoPixel::setHSVColor(int pixel, int hue, double saturation, double value,
                           bool mustShow) {
  double hh, p, q, t, ff;
  long i;
  double red, green, blue;

  if (saturation <= 0.0) { // < is bogus, just shuts up warnings
    red = value;
    green = value;
    blue = value;
  } else {
    hh = hue;
    if (hh >= 360.0)
      hh = 0.0;
    hh /= 60.0;
    i = (long)hh;
    ff = hh - i;
    p = value * (1.0 - saturation);
    q = value * (1.0 - (saturation * ff));
    t = value * (1.0 - (saturation * (1.0 - ff)));

    switch (i) {
    case 0:
      red = value;
      green = t;
      blue = p;
      break;
    case 1:
      red = q;
      green = value;
      blue = p;
      break;
    case 2:
      red = p;
      green = value;
      blue = t;
      break;

    case 3:
      red = p;
      green = q;
      blue = value;
      break;
    case 4:
      red = t;
      green = p;
      blue = value;
      break;
    case 5:
    default:
      red = value;
      green = p;
      blue = q;
      break;
    }
  }

  _strip.setPixelColor(pixel, _strip.Color(red * 255, green * 255, blue * 255));
  if (mustShow) {
    _strip.show();
  }
}

void NeoPixel::off(int delayMicros) { noSequence(0, 1.0, 0.0); }

void NeoPixel::wipeSequence(int hue, double saturation, double value,
                            int delayMicros, double probability, bool reverse) {
  for (int i = 0; i < _strip.numPixels(); i++) {
    int index = i;
    if (reverse) {
      index = _strip.numPixels() - i - 1;
    }
    if (probability == 1.0 || probability >= (random(100) / 100.0)) {
      setHSVColor(index, hue, saturation, value);
    } else {
      setRGBColor(index, 0, 0, 0);
    }
    delay(delayMicros);
  }
}

void NeoPixel::chaseSequence(int hue, double saturation, double value,
                             int delayMicros, int cycles) {
  for (int c = 0; c < cycles; c++) {
    for (int i = 0; i < _strip.numPixels(); i++) {
      if ((i + c) % 3 == 0) {
        setHSVColor(i, hue, saturation, value, false);
      } else {
        setRGBColor(i, 0, 0, 0);
      }
    }
    _strip.show();
    delay(delayMicros);
  }
}

void NeoPixel::rainbowSequence(double saturation, double value, int delayMicros,
                               int cycles) {
  int colorInc = 360 / _strip.numPixels();
  Serial.println(colorInc);
  for (int c = 0; c < cycles; c++) {
    Serial.println(c);
    for (int i = 0; i < _strip.numPixels(); i++) {
      setHSVColor(i, (colorInc * i) + (colorInc * c), saturation, value);
    }
    delay(delayMicros);
  }
}

void NeoPixel::noSequence(int hue, double saturation, double value,
                          int delayMicros, double probability) {
  for (int i = 0; i < _strip.numPixels(); i++) {
    if (probability == 1.0 || probability >= (random(100) / 100.0)) {
      setHSVColor(i, hue, saturation, value, false);
    } else {
      setRGBColor(i, 0, 0, 0, false);
    }
  }
  _strip.show();
  delay(delayMicros);
}
