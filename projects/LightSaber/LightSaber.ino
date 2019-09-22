/*
   LightSaber.ino - Lightsaber implementation.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Released into the public domain.
*/

#include <Button.h>
#include <NeoPixel.h>
#include <PiezoBuzzer.h>

const int LED_DELAY = 5;

const Melody mainThemeMelody(
    (int[]){C4, G4, F4, E4, D4, C5, G4, F4, E4, D4, C5, G4, F4, E4, F4, D4, TE},
    (int[]){8, 8, 2, 2, 2, 8, 4, 2, 2, 2, 8, 4, 2, 2, 2, 4}, 100);

const Melody imperialMarchMelody(
    (int[]){A4,  A4, A4,  F4,  C5,  A4, F4,  C5,  A4, NT,  E5, E5,
            E5,  F5, C5,  GS4, F4,  C5, A4,  NT,  A5, A4,  A4, A5,
            GS5, G5, FS5, F5,  FS5, NT, AS4, DS5, D5, CS5, C5, AS4,
            C5,  NT, F4,  GS4, F4,  A4, C5,  A4,  C5, E5,  TE},
    (int[]){4, 4, 4, 3, 1, 4, 3, 1, 5, 4, 4, 4, 4, 3, 1, 4,
            3, 1, 5, 4, 4, 3, 1, 4, 3, 1, 1, 1, 2, 4, 2, 4,
            3, 1, 1, 1, 2, 4, 2, 4, 3, 1, 4, 3, 1, 5},
    125);

const Button button(2, 3);
const PiezoBuzzer buzzer(4);
const NeoPixel strip(5, 30);

void setup() {
  Serial.begin(9600);
  strip.setup();
}

void loop() {
  int clicks = button.getClicks();

  if (!button.isOn() && clicks > 0) {
    // when the lightsaber is off and there has been any clicks
    // we set the strip to a random color
    strip.wipeSequence(random(255), random(255), random(255), LED_DELAY);
    button.setOn(true);
  } else if (button.isOn()) {
    playHum();
    // when the light saber is on
    switch (clicks) {
      case 0:
        while (button.isOn() && button.isLongPressed(1000)) {
          buzzer.stopNote();
          // when there is a continuous button press
          // change to another random color
          strip.noSequence(random(255), random(255), random(255));
          delay(1500);
        }
        break;
      case 1:
        // single button click we stop the sound switch the strip off
        buzzer.stopNote();
        strip.wipeSequence(0, 0, 0, LED_DELAY, true);
        button.setOn(false);
        break;
      case 2:
        buzzer.playMelody(mainThemeMelody);
        break;
      case 3:
        buzzer.playMelody(imperialMarchMelody);
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
