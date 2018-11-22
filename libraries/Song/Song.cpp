/*
Song.cpp - Library to represent a song.
Created by LazyGalaxy - Evangelos Papakonstantis, November 20, 2018.
Released into the public domain.
 */

#include "Song.h"

Song::Song(int *notes, int *beats, int tempo) {
  _notes = notes;
  _beats = beats;
  _tempo = tempo;
}

int *Song::getNotes() { return _notes; }

int *Song::getBeats() { return _beats; }

int Song::getTempo() { return _tempo; }
