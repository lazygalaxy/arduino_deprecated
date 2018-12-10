/*
   AsyncMelody.ino - Asynchronous melody playing example.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 22, 2018.
   Released into the public domain.
*/

#include <Melody.h>
#include <PiezoBuzzer.h>

const PiezoBuzzer buzzer(4);
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

const Melody joyToTheWorldMelody(
    (int[]){587, 554, 493, 440, 391, 369, 329, 293, 440, 493, 493, 554,
            554, 587, 587, 587, 554, 493, 440, 440, 391, 369, 587, 587,
            554, 493, 440, 440, 391, 369, 369, 369, 369, 369, 369, 391,
            440, 391, 369, 329, 329, 329, 329, 369, 391, 369, 329, 293,
            587, 440, 391, 369, 391, 369, 329, TE},
    (int[]){4, 3, 1, 6, 2, 4, 4, 6, 2, 6, 2, 6, 2, 6, 2, 2, 2, 2, 2,
            3, 1, 2, 2, 2, 2, 2, 2, 3, 1, 2, 2, 2, 2, 2, 1, 1, 6, 1,
            1, 2, 2, 2, 1, 1, 6, 1, 1, 2, 4, 3, 1, 2, 2, 4, 4},
    100);

void setup() {
  Serial.begin(9600);
  buzzer.setMelody(joyToTheWorldMelody);
}

void loop() { buzzer.playMelody(); }
