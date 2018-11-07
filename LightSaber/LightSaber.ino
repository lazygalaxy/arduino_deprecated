/*
   LightSaber.ino - Lightsaber implementation.
   Created by LazyGalaxy - Evangelos Papakonstantis, August 23, 2018.
   Version - 1.0
   Released into the public domain.
*/

#include <Button.h>
#include <PiezoBuzzer.h>
#include <RGB_LED.h>

Button button(2);
PiezoBuzzer buzzer(4);
RGB_LED led(11, 10, 9);

// when we start we assume the lightsaber is off
boolean lightSaberOn = false;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  digitalWrite(3, 0);
}

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
    digitalWrite(3, 1);
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
      digitalWrite(3, 0);
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
  buzzer.playAndStopNote(d, 1000, 500);
}

// https://gist.github.com/nicksort/4736535
void playTheImperialMarch(PiezoBuzzer buzzer) {
  buzzer.playAndStopNote(a, 500);
  buzzer.playAndStopNote(a, 500);
  buzzer.playAndStopNote(a, 500);
  buzzer.playAndStopNote(f, 350);
  buzzer.playAndStopNote(cH, 150);
  buzzer.playAndStopNote(a, 500);
  buzzer.playAndStopNote(f, 350);
  buzzer.playAndStopNote(cH, 150);
  buzzer.playAndStopNote(a, 650, 500);

  buzzer.playAndStopNote(eH, 500);
  buzzer.playAndStopNote(eH, 500);
  buzzer.playAndStopNote(eH, 500);
  buzzer.playAndStopNote(fH, 350);
  buzzer.playAndStopNote(cH, 150);
  buzzer.playAndStopNote(gS, 500);
  buzzer.playAndStopNote(f, 350);
  buzzer.playAndStopNote(cH, 150);
  buzzer.playAndStopNote(a, 650, 500);

  buzzer.playAndStopNote(aH, 500);
  buzzer.playAndStopNote(a, 300);
  buzzer.playAndStopNote(a, 150);
  buzzer.playAndStopNote(aH, 500);
  buzzer.playAndStopNote(gSH, 325);
  buzzer.playAndStopNote(gH, 175);
  buzzer.playAndStopNote(fSH, 125);
  buzzer.playAndStopNote(fH, 125);
  buzzer.playAndStopNote(fSH, 250, 500);

  buzzer.playAndStopNote(aS, 250);
  buzzer.playAndStopNote(dSH, 500);
  buzzer.playAndStopNote(dH, 325);
  buzzer.playAndStopNote(cSH, 175);
  buzzer.playAndStopNote(cH, 125);
  buzzer.playAndStopNote(b, 125);
  buzzer.playAndStopNote(cH, 250, 500);

  buzzer.playAndStopNote(f, 250);
  buzzer.playAndStopNote(gS, 500);
  buzzer.playAndStopNote(f, 350);
  buzzer.playAndStopNote(a, 125);
  buzzer.playAndStopNote(cH, 500);
  buzzer.playAndStopNote(a, 375);
  buzzer.playAndStopNote(cH, 125);
  buzzer.playAndStopNote(eH, 650, 500);
}
