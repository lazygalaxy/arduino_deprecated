/*
   Timer.h - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#ifndef Timer_h
#define Timer_h

#include <stddef.h>

typedef void (*funcPtr)(void);

class Timer {
 public:
  Timer();
  void schedule(unsigned long time, funcPtr callback);
  void update(unsigned long time);

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
