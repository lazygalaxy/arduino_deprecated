/*
   ChristmasTree.ino - Christmas tree implementation.
   Created by LazyGalaxy - Evangelos Papakonstantis, November 17, 2018.
   Released into the public domain.
*/

#include <PiezoBuzzer.h>
#include <Song.h>

PiezoBuzzer buzzer(4);
Song santaClausSong((int[]){G4, E4, F4, G4, G4, G4, A4, B4, C5, C5,
                            C5, E4, F4, G4, G4, G4, A4, G4, F4, F4,
                            E4, G4, C4, E4, D4, F4, B3, C4, TE},
                    (int[]){2, 2, 2, 4, 4, 4, 2, 2, 4, 4, 4, 2, 2, 4, 4,
                            4, 2, 2, 4, 8, 4, 4, 4, 4, 4, 8, 4, 8},
                    100);

Song jingleBellsSong((int[]){E5, E5, E5, E5, E5, E5, E5, G5, C5,
                             D5, E5, F5, F5, F5, F5, F5, E5, E5,
                             E5, E5, E5, D5, D5, E5, D5, G5, TE},
                     (int[]){2, 2, 4, 2, 2, 4, 2, 2, 2, 2, 8, 2, 2, 2,
                             2, 2, 2, 2, 1, 1, 2, 2, 2, 2, 4, 4},
                     100);

Song merryChristmasSong((int[]){B3, F4, F4, G4, F4, E4, D4, D4, D4, G4, G4,
                                A4, G4, F4, E4, E4, E4, A4, A4, B4, A4, G4,
                                F4, D4, B3, B3, D4, G4, E4, F4, TE},
                        (int[]){4, 4, 2, 2, 2, 2, 4, 4, 4, 4, 2, 2, 2, 2, 4, 4,
                                4, 4, 2, 2, 2, 2, 4, 4, 2, 2, 4, 4, 4, 8},
                        100);

void setup() {
  Serial.begin(9600);
   buzzer.setSong(jingleBellsSong);
}

void loop() {
   buzzer.playSong();
  //buzzer.playSong(jingleBellsSong);
}
