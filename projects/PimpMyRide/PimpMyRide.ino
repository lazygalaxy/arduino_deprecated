/*
   PimpMyRide.ino - Add some cool features to your car.
   Created by LazyGalaxy - Evangelos Papakonstantis, April 7, 2019.
   Released into the public domain.
*/

// 3rd party libs/vars
#define SD_ChipSelectPin 10
#include "TMRpcm.h"
TMRpcm tmrpcm;

// lazygalaxy libs/vars
#include <Button.h>
const Button startStopButton(2, 3);

// inner classes to handle states
class State {
 public:
  virtual void State::loop() {
    if (!tmrpcm.isPlaying()) {
      tmrpcm.disable();
    }
  };
  virtual State* State::startStopButtonPressed() { return this; };
};

class OffState : public State {
 public:
  State* OffState::startStopButtonPressed();
};

class IdleState : public State {
 public:
  State* IdleState::startStopButtonPressed();
  void IdleState::loop();
};

const State* OFF_STATE = new OffState();
const State* IDLE_STATE = new IdleState();

// off state implementations
State* OffState::startStopButtonPressed() {
  tmrpcm.play("start.wav");
  startStopButton.setOn(true);

  return IDLE_STATE;
}

// idle state implementations
State* IdleState::startStopButtonPressed() {
  startStopButton.setOn(false);
  tmrpcm.play("6.wav");

  return OFF_STATE;
};

void IdleState::loop() {
  if (!tmrpcm.isPlaying()) {
    tmrpcm.play("1.wav");
  }
}

class StateContext {
 private:
  State* state;

 public:
  StateContext() { state = OFF_STATE; }

  void loop() { state->loop(); }
  void startStopButtonPressed() { state = state->startStopButtonPressed(); }
};

StateContext context = StateContext();

void setup() {
  Serial.begin(9600);

  // amplifier
  tmrpcm.speakerPin = 9;
  tmrpcm.setVolume(2);
  tmrpcm.quality(1);

  // sd card reader
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }

  Serial.println("setup ok");
}

void loop() {
  int startStopButtonClicks = startStopButton.getClicks();
  if (startStopButtonClicks > 0) {
    context.startStopButtonPressed();
  }
  context.loop();
}
