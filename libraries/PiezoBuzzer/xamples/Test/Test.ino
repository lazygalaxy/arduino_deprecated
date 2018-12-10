// Credit:
// Midi to Arduino Converter
//     - Andy Tran (extramaster), 2015
// https://www.extramaster.net/tools/midiToArduino/
//
// Process:
// Midi -> Midi tracks -> Note mappings -> Frequency
//
// CC0

// Set this to be the pin that your buzzer resides in. (Note that you can only have one buzzer actively using the PWM signal at a time).
int tonePin = 4;
void setup() {

}

void midi() {

    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 391, 225.0);
    delay(250.0);
    tone(tonePin, 293, 450.0);
    delay(500.0);
    delay(250.0);
    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 391, 225.0);
    delay(250.0);
    tone(tonePin, 329, 450.0);
    delay(500.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 587, 450.0);
    delay(500.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 659, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 493, 675.0);
    delay(750.0);
    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 391, 225.0);
    delay(250.0);
    tone(tonePin, 293, 450.0);
    delay(500.0);
    delay(250.0);
    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 293, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 391, 225.0);
    delay(250.0);
    tone(tonePin, 329, 450.0);
    delay(500.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 329, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 659, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 391, 450.0);
    delay(500.0);
    tone(tonePin, 587, 450.0);
    delay(500.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 450.0);
    delay(500.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 450.0);
    delay(500.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 391, 337.5);
    delay(375.0);
    tone(tonePin, 440, 112.5);
    delay(125.0);
    tone(tonePin, 493, 450.0);
    delay(500.0);
    delay(500.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 523, 337.5);
    delay(375.0);
    tone(tonePin, 523, 112.5);
    delay(125.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 112.5);
    delay(125.0);
    tone(tonePin, 493, 112.5);
    delay(125.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 440, 450.0);
    delay(500.0);
    tone(tonePin, 587, 450.0);
    delay(500.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 450.0);
    delay(500.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 450.0);
    delay(500.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 391, 337.5);
    delay(375.0);
    tone(tonePin, 440, 112.5);
    delay(125.0);
    tone(tonePin, 493, 450.0);
    delay(500.0);
    delay(500.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 523, 337.5);
    delay(375.0);
    tone(tonePin, 523, 112.5);
    delay(125.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 225.0);
    delay(250.0);
    tone(tonePin, 493, 112.5);
    delay(125.0);
    tone(tonePin, 493, 112.5);
    delay(125.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 587, 225.0);
    delay(250.0);
    tone(tonePin, 523, 225.0);
    delay(250.0);
    tone(tonePin, 440, 225.0);
    delay(250.0);
    tone(tonePin, 391, 675.0);
    delay(750.0);

}

void loop() {
    // Play midi
    midi();
}
