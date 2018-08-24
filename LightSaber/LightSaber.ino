/*
   LightSaber.ino - Lightsaber implementation.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
 */

#include <Button.h>
#include <PiezoBuzzer.h>
#include <RGB_LED.h>

Button button(12);
PiezoBuzzer buzzer(8);
RGB_LED led(11, 10, 9);

boolean lightSaberOn = false;

void setup() {}

void loop() {
  if (button.isPressed(200)) {
    lightSaberOn = !lightSaberOn;

    if (lightSaberOn) {
       led.setColor(random(255), random(255), random(255));
    }
  }

  if (lightSaberOn) {
    
  } else {
    led.off();
  }
}

// https://circuits.io/circuits/1542469-music-with-arduino-star-wars-theme-song
void playMainTitleTheme(PiezoBuzzer buzzer) {
  buzzer.playNote(c, 1000);
  buzzer.playNote(g, 1000);
  buzzer.playNote(f, 250);
  buzzer.playNote(e, 250);
  buzzer.playNote(d, 250);
  buzzer.playNote(cH, 1000);
  buzzer.playNote(g, 500);
  buzzer.playNote(f, 250);
  buzzer.playNote(e, 250);
  buzzer.playNote(d, 250);
  buzzer.playNote(cH, 1000);
  buzzer.playNote(g, 500);
  buzzer.playNote(f, 250);
  buzzer.playNote(e, 250);
  buzzer.playNote(f, 250);
  buzzer.playNoteAndStop(d, 1000, 500);
}

// https://gist.github.com/nicksort/4736535
void playTheImperialMarch(PiezoBuzzer buzzer) {
  buzzer.playNoteAndStop(a, 500);
  buzzer.playNoteAndStop(a, 500);
  buzzer.playNoteAndStop(a, 500);
  buzzer.playNoteAndStop(f, 350);
  buzzer.playNoteAndStop(cH, 150);
  buzzer.playNoteAndStop(a, 500);
  buzzer.playNoteAndStop(f, 350);
  buzzer.playNoteAndStop(cH, 150);
  buzzer.playNoteAndStop(a, 650, 500);

  buzzer.playNoteAndStop(eH, 500);
  buzzer.playNoteAndStop(eH, 500);
  buzzer.playNoteAndStop(eH, 500);
  buzzer.playNoteAndStop(fH, 350);
  buzzer.playNoteAndStop(cH, 150);
  buzzer.playNoteAndStop(gS, 500);
  buzzer.playNoteAndStop(f, 350);
  buzzer.playNoteAndStop(cH, 150);
  buzzer.playNoteAndStop(a, 650, 500);

  buzzer.playNoteAndStop(aH, 500);
  buzzer.playNoteAndStop(a, 300);
  buzzer.playNoteAndStop(a, 150);
  buzzer.playNoteAndStop(aH, 500);
  buzzer.playNoteAndStop(gSH, 325);
  buzzer.playNoteAndStop(gH, 175);
  buzzer.playNoteAndStop(fSH, 125);
  buzzer.playNoteAndStop(fH, 125);
  buzzer.playNoteAndStop(fSH, 250, 500);

  buzzer.playNoteAndStop(aS, 250);
  buzzer.playNoteAndStop(dSH, 500);
  buzzer.playNoteAndStop(dH, 325);
  buzzer.playNoteAndStop(cSH, 175);
  buzzer.playNoteAndStop(cH, 125);
  buzzer.playNoteAndStop(b, 125);
  buzzer.playNoteAndStop(cH, 250, 500);

  buzzer.playNoteAndStop(f, 250);
  buzzer.playNoteAndStop(gS, 500);
  buzzer.playNoteAndStop(f, 350);
  buzzer.playNoteAndStop(a, 125);
  buzzer.playNoteAndStop(cH, 500);
  buzzer.playNoteAndStop(a, 375);
  buzzer.playNoteAndStop(cH, 125);
  buzzer.playNoteAndStop(eH, 650, 500);
}
