/*
   Timer.h - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

#define TASK_SIZE 5

class Timer {
 public:
  Timer();

  void schedule(unsigned int delay, void (*taskCallback)(void));
  void update();

 private:
  typedef void (*funcPtr)(void);

  struct TimerTask {
    TimerTask(unsigned long time, funcPtr callback) {
      this->time = time;
      this->callback = callback;
    }

    unsigned long time;
    funcPtr callback;
  };

  TimerTask** tasks[TASK_SIZE] = {NULL};
};

#endif
