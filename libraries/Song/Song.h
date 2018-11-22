/*
Song.h - Library to represent a song.
Created by LazyGalaxy - Evangelos Papakonstantis, November 20, 2018.
Released into the public domain.
 */

#ifndef Song_h
#define Song_h

#include "Arduino.h"

class Song {
public:
  Song(int notes[], int beats[], int tempo);
  int *getNotes();
  int *getBeats();
  int getTempo();

private:
  int *_notes;
  int *_beats;
  int _tempo;
};

#endif
