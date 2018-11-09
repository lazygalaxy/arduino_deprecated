/*
   PiezoBuzzer.cpp - Library for Piezo Buzzer speaker.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
 */

#include "PiezoBuzzer.h"

PiezoBuzzer::PiezoBuzzer(int digitalPin) {
  _digitalPin = digitalPin;

  pinMode(_digitalPin, OUTPUT);
}

void PiezoBuzzer::playNote(int note, int delayMicros) {
  tone(_digitalPin, note);
  delay(delayMicros);
}

void PiezoBuzzer::stopNote(int delayMicros) {
  noTone(_digitalPin);
  delay(delayMicros);
}

void PiezoBuzzer::playAndStopNote(int note, int noteDelayMicros,
                                  int stopDelayMicros) {
  playNote(note, noteDelayMicros);
  stopNote(stopDelayMicros);
}
