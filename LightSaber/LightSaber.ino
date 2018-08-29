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

// when we start we assume the lightsaber is off
boolean lightSaberOn = false;

void setup() { Serial.begin(9600); }

void loop() {
  button.updateState();
  int clicks = button.getClicks(500);
  // Serial.println(clicks);

  if (!lightSaberOn && clicks > 0) {
    // when the lightsaber is off and there has been any clicks
    // we set the led to a random color
    led.setColor(random(255), random(255), random(255));
    // update the lightSaberOn status
    lightSaberOn = true;
  } else if (lightSaberOn) {
    playHum();
    // when the light saber is on
    switch (clicks) {
    case 0:
      while (lightSaberOn && button.isPressed(1000)) {
        buzzer.stopNote();
        // when there is a continuous button press
        // change to another random color
        led.setColor(random(255), random(255), random(255));
        delay(1000);
        // button state needs to be updated if we want to exit the while loop
        button.updateState();
      }
      break;
    case 1:
      // when there is a single button click
      // we switch off the led
      led.off();
      buzzer.stopNote();
      // update the lightSaberOn status
      lightSaberOn = false;
      break;
    case 2:
      playMainTitleTheme(buzzer);
      break;
    case 3:
      playTheImperialMarch(buzzer);
      break;
    }
  }
}

void playHum() {
  unsigned long time = millis();
  int freq = (sin(time * 0.01) + 5) * 10;
  Serial.println(freq);
  buzzer.playNote(freq);
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
