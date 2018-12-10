/*
Melody.h - Library to represent a melody.
Created by LazyGalaxy - Evangelos Papakonstantis, November 20, 2018.
Released into the public domain.
 */

#ifndef Melody_h
#define Melody_h

#include "Arduino.h"

class Melody {
public:
  Melody(int notes[], int beats[], int tempo);
  int *getNotes();
  int *getBeats();
  int getTempo();

private:
  int *_notes;
  int *_beats;
  int _tempo;
};

#endif
