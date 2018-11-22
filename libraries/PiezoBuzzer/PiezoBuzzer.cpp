/*
   PiezoBuzzer.cpp - Library for Piezo Buzzer speaker.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
 */

#include "PiezoBuzzer.h"

PiezoBuzzer::PiezoBuzzer(int digitalPin) {
  _digitalPin = digitalPin;
  pinMode(_digitalPin, OUTPUT);

  stopSong();
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

void PiezoBuzzer::playSong(Song song) {
  int *notes = song.getNotes();
  int *beats = song.getBeats();
  int tempo = song.getTempo();

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

void PiezoBuzzer::stopSong() {
  stopNote();
  _songToneIndex = -1;
  _songToneTimeEnd = 0;
}

void PiezoBuzzer::setSong(Song song) {
  _song = &song;
  _songToneIndex = 0;
  _songToneTimeEnd = millis();
}

void PiezoBuzzer::playSong() {
  // a positive index indicates we have a song to play
  if (_songToneIndex >= 0) {
    unsigned long currentTime = millis();
    if (currentTime >= _songToneTimeEnd) {
      if (_song->getNotes()[_songToneIndex]) {
        // if we playing a note and the next note is identical
        if (_isTonePlaying && (_song->getNotes()[_songToneIndex] ==
                               _song->getNotes()[_songToneIndex - 1])) {
          // stop the note for 50 millis
          stopNote();
          _songToneTimeEnd = currentTime + 50;
          return;
        }
        playNote(_song->getNotes()[_songToneIndex]);
        _songToneTimeEnd = currentTime + (_song->getBeats()[_songToneIndex] *
                                          _song->getTempo());
        _songToneIndex++;
      } else {
        stopSong();
      }
    }
  }
}
