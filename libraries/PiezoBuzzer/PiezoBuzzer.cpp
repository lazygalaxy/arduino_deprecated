/*
   PiezoBuzzer.cpp - Library for Piezo Buzzer.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
 */

#include "PiezoBuzzer.h"

PiezoBuzzer::PiezoBuzzer(int pin) {
  _pin = pin;

  pinMode(_pin, OUTPUT);
}

void PiezoBuzzer::playNote(int note, int delayMicros) {
  tone(_pin, note);
  delay(delayMicros);
}

void PiezoBuzzer::stopNote(int delayMicros) {
  noTone(_pin);
  delay(delayMicros);
}

void PiezoBuzzer::playNoteAndStop(int note, int noteDelayMicros,
                                  int stopDelayMicros) {
  playNote(note, noteDelayMicros);
  stopNote(stopDelayMicros);
}
