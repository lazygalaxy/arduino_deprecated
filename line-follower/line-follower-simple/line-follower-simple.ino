/*
   line-follower-simple.ino - Simple line following implementation.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 26, 2018.
   Released into the public domain.
 */

#include <HP_ASE_LIN.h>
#include <L298N.h>

L298N motorController(5, 6, 7, 8, 9, 10);
HP_ASE_LIN leftSensor(0, 100);
HP_ASE_LIN rightSensor(1, 100);

void setup() {}

void loop() {
  if (leftSensor.isBlack()) {
    motorController.turnLeft(255);
  } else if (rightSensor.isBlack()) {
    motorController.turnRight(255);
  } else {
    motorController.moveForward(255);
  }
}
