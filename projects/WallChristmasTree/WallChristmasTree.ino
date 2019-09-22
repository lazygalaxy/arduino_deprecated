/*
   WallChristmasTree.ino - Wall christmas tree implementation.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 17, 2018.
   Released into the public domain.
*/

#include <Button.h>
#include <Melody.h>
#include <NeoPixel.h>
#include <PiezoBuzzer.h>

const Button button1(2, 3);
const Button button2(4, 5);
const Button button3(6, 7);
const Button button4(8, 9);
const NeoPixel strip(10, 123);
const PiezoBuzzer buzzer(11);

const Melody santaClausMelody((int[]){G4, E4, F4, G4, G4, G4, A4, B4, C5, C5,
                                      C5, E4, F4, G4, G4, G4, A4, G4, F4, F4,
                                      E4, G4, C4, E4, D4, F4, B3, C4, TE},
                              (int[]){2, 2, 2, 4, 4, 4, 2, 2, 4, 4, 4, 2, 2, 4,
                                      4, 4, 2, 2, 4, 8, 4, 4, 4, 4, 4, 8, 4, 8},
                              100);

const Melody jingleBellsMelody((int[]){E5, E5, E5, E5, E5, E5, E5, G5, C5,
                                       D5, E5, F5, F5, F5, F5, F5, E5, E5,
                                       E5, E5, E5, D5, D5, E5, D5, G5, TE},
                               (int[]){2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 8, 2, 2,
                                       2, 2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 4, 4},
                               100);

const Melody merryChristmasMelody(
    (int[]){B3, F4, F4, G4, F4, E4, D4, D4, D4, G4, G4, A4, G4, F4, E4, E4,
            E4, A4, A4, B4, A4, G4, F4, D4, B3, B3, D4, G4, E4, F4, TE},
    (int[]){4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4,
            4, 4, 4, 2, 2, 2, 2, 4, 4, 2, 2, 4, 4, 4, 8},
    100);

const Melody imperialMarchMelody(
    (int[]){A4,  A4, A4,  F4,  C5,  A4, F4,  C5,  A4, NT,  E5, E5,
            E5,  F5, C5,  GS4, F4,  C5, A4,  NT,  A5, A4,  A4, A5,
            GS5, G5, FS5, F5,  FS5, NT, AS4, DS5, D5, CS5, C5, AS4,
            C5,  NT, F4,  GS4, F4,  A4, C5,  A4,  C5, E5,  TE},
    (int[]){4, 4, 4, 3, 1, 4, 3, 1, 5, 4, 4, 4, 4, 3, 1, 4,
            3, 1, 5, 4, 4, 3, 1, 4, 3, 1, 1, 1, 2, 4, 2, 4,
            3, 1, 1, 1, 2, 4, 2, 4, 3, 1, 4, 3, 1, 5},
    125);

void setup() {
  Serial.begin(9600);
  strip.setup();
}

void loop() {
  int clicks1 = button1.getClicks();
  if (!button1.isOn() && clicks1 > 0) {
    button1.setOn(true);
    button2.setOn(false);
    button3.setOn(false);
    button4.setOn(false);
    buzzer.setMelody(merryChristmasMelody);
  }

  int clicks2 = button2.getClicks();
  if (!button2.isOn() && clicks2 > 0) {
    button1.setOn(false);
    button2.setOn(true);
    button3.setOn(false);
    button4.setOn(false);
    buzzer.setMelody(jingleBellsMelody);
  }

  int clicks3 = button3.getClicks();
  if (!button3.isOn() && clicks3 > 0) {
    button1.setOn(false);
    button2.setOn(false);
    button3.setOn(true);
    button4.setOn(false);
    buzzer.setMelody(santaClausMelody);
  }

  int clicks4 = button4.getClicks();
  if (!button4.isOn() && clicks4 > 0) {
    button1.setOn(false);
    button2.setOn(false);
    button3.setOn(false);
    button4.setOn(true);
    buzzer.setMelody(imperialMarchMelody);
  }

  buzzer.playMelody(playRandomCallback, stopCallback);
}

void playRandomCallback(int counter) {
  strip.noSequence(random(360), 1.0, 1.0, 0, 0.5);
}

void stopCallback() {
  strip.off();
  button1.setOn(false);
  button2.setOn(false);
  button3.setOn(false);
  button4.setOn(false);
}
