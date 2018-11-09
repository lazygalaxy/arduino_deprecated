/*
   PiezoBuzzer.h - Library for Piezo Buzzer speaker.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
 */

#ifndef PiezoBuzzer_h
#define PiezoBuzzer_h

#include "Arduino.h"

const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;

class PiezoBuzzer {
public:
  PiezoBuzzer(int digitalPin);
  void playNote(int note, int delayMicros = 0);
  void stopNote(int delayMicros = 0);
  void PiezoBuzzer::playAndStopNote(int note, int noteDelayMicros,
                                    int stopDelayMicros = 50);

private:
  int _digitalPin;
};

#endif
