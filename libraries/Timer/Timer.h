/*
   Timer.h - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#ifndef Timer_h
#define Timer_h

#include <Component.h>

typedef void (*funcPtr)(void);

static unsigned long idCounter = 0;

class Timer {
 public:
  static Timer* getInstance() {
    static Timer* instance = new Timer();
    return instance;
  }

  unsigned long schedule(unsigned long triggerTime, funcPtr callback,
                         unsigned int repeatDelay);
  unsigned long schedule(unsigned long triggerTime, Component* component,
                         unsigned int repeatDelay);
  bool unschedule(unsigned long taskId);
  void update(unsigned long time);

 private:
  struct TimerTask {
    TimerTask(unsigned long triggerTime, funcPtr callback,
              unsigned int repeatDelay) {
      this->id = ++idCounter;
      this->triggerTime = triggerTime;
      this->callback = callback;
      this->component = nullptr;
      this->repeatDelay = repeatDelay;
      this->next = nullptr;
    }

    TimerTask(unsigned long triggerTime, Component* component,
              unsigned int repeatDelay) {
      this->id = ++idCounter;
      this->triggerTime = triggerTime;
      this->callback = nullptr;
      this->component = component;
      this->repeatDelay = repeatDelay;
      this->next = nullptr;
    }

    unsigned long id;
    unsigned long triggerTime;
    unsigned int repeatDelay;
    funcPtr callback;
    Component* component;
    TimerTask* next;
  };

  Timer();
  void addTask(TimerTask* task);
  void removeTask(TimerTask* current, TimerTask* previous);

  TimerTask* head = nullptr;
  TimerTask* tail = nullptr;
};

#endif
