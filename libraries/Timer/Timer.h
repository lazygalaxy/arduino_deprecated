/*
   Timer.h - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#ifndef Timer_h
#define Timer_h

#include <Arduino.h>
#include <Component.h>

typedef void (*funcPtr)(void);

class Timer {
 public:
  static Timer* getInstance() {
    static Timer* instance = new Timer();
    return instance;
  }
  void schedule(unsigned long triggerTime, funcPtr callback);
  void schedule(unsigned long triggerTime, Component* component);
  void update(unsigned long time);

 private:
  Timer();
  struct TimerTask {
    TimerTask(unsigned long triggerTime, funcPtr callback) {
      this->triggerTime = triggerTime;
      this->callback = callback;
      this->component = NULL;
      this->next = NULL;
    }

    TimerTask(unsigned long triggerTime, Component* component) {
      this->triggerTime = triggerTime;
      this->callback = NULL;
      this->component = component;
      this->next = NULL;
    }

    unsigned long triggerTime;
    funcPtr callback;
    Component* component;
    TimerTask* next;
  };

  void addTask(TimerTask* task);
  TimerTask* head = NULL;
  TimerTask* tail = NULL;
};

#endif
