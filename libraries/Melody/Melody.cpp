/*
Melody.cpp - Library to represent a melody.
Created by LazyGalaxy - Evangelos Papakonstantis, November 20, 2018.
Released into the public domain.
 */

#include "Melody.h"

Melody::Melody(int *notes, int *beats, int tempo) {
  _notes = notes;
  _beats = beats;
  _tempo = tempo;
}

int *Melody::getNotes() { return _notes; }

int *Melody::getBeats() { return _beats; }

int Melody::getTempo() { return _tempo; }
