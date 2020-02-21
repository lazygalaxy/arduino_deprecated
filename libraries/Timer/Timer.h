/*
   Timer.h - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#ifndef Timer_h
#define Timer_h

#include "Arduino.h"

class Timer {
 public:
  typedef void (*funcPtr)(void);

  Timer();
  void schedule(unsigned int delay, funcPtr callback);
  void update();

 private:
  struct TimerTask {
    TimerTask(unsigned long time, funcPtr callback) {
      this->time = time;
      this->callback = callback;
      this->next = NULL;
    }

    unsigned long time;
    funcPtr callback;
    TimerTask* next;
  };

  TimerTask* head = NULL;
  TimerTask* tail = NULL;
};

#endif
