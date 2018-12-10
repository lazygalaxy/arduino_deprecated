/*
   PiezoBuzzer.cpp - Library for Piezo Buzzer speaker.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
 */

#include "PiezoBuzzer.h"

PiezoBuzzer::PiezoBuzzer(int digitalPin) {
  _digitalPin = digitalPin;
  pinMode(_digitalPin, OUTPUT);

  stopMelody();
}

void PiezoBuzzer::playNote(int note, int delayMicros) {
  tone(_digitalPin, note);
  _isTonePlaying = true;
  delay(delayMicros);
}

void PiezoBuzzer::stopNote(int delayMicros) {
  noTone(_digitalPin);
  _isTonePlaying = false;
  delay(delayMicros);
}

void PiezoBuzzer::playAndStopNote(int note, int noteDelayMicros,
                                  int stopDelayMicros) {
  playNote(note, noteDelayMicros);
  stopNote(stopDelayMicros);
}

void PiezoBuzzer::playMelody(Melody melody) {
  int *notes = melody.getNotes();
  int *beats = melody.getBeats();
  int tempo = melody.getTempo();

  // repeat until there are actual notes and beats in the array
  for (int i = 0; notes[i]; i++) {
    int duration = beats[i] * tempo;
    switch (notes[i]) {
    case NT:
      stopNote(duration);
      break;
    default:
      playNote(notes[i], duration);
      // if the next note is the same as the current one, stop for 50 millis
      if (notes[i] == notes[i + 1]) {
        stopNote(50);
      }
    }
  }
}

void PiezoBuzzer::stopMelody() {
  stopNote();
  _toneIndex = -1;
  _toneTimeEnd = 0;
}

void PiezoBuzzer::setMelody(Melody melody) {
  _melody = &melody;
  _toneIndex = 0;
  _toneTimeEnd = millis();
}

void PiezoBuzzer::playMelody(void (*_playCallback)(int),
                             void (*_stopCallback)(void)) {
  // a positive index indicates we have a melody to play
  if (_toneIndex >= 0) {
    unsigned long currentTime = millis();
    if (currentTime >= _toneTimeEnd) {
      if (_melody->getNotes()[_toneIndex]) {
        // if the previous note we are playing is not identical to the next one
        if (_isTonePlaying && _toneIndex > 0 &&
            (_melody->getNotes()[_toneIndex - 1] ==
             _melody->getNotes()[_toneIndex])) {
          // stop the note for 50 millis
          stopNote();
          _toneTimeEnd = currentTime + 50;
          return;
        }
        playNote(_melody->getNotes()[_toneIndex]);
        _toneTimeEnd = currentTime +
                       (_melody->getBeats()[_toneIndex] * _melody->getTempo());
        _playCallback(_toneIndex);
        _toneIndex++;
      } else {
        stopMelody();
        _stopCallback();
      }
    }
  }
}
