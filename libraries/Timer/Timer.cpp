/*
   Timer.cpp - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#include "Timer.h"

Timer::Timer() {}

void Timer::schedule(unsigned int delay, funcPtr callback) {
  TimerTask *task = new TimerTask(delay + millis(), callback);
  if (head == NULL) {
    head = task;
    tail = task;
  } else {
    tail->next = task;
    tail = task;
  }
}

void Timer::update() {
  unsigned long time = millis();

  TimerTask *current = head;
  TimerTask *previous = NULL;
  while (current != NULL) {
    if (current->time <= time) {
      current->callback();
      TimerTask *temp = current;
      if (previous == NULL) {
        head = head->next;
        if (head == NULL) {
          tail = NULL;
        }
        current = current->next;
      } else {
        previous->next = current->next;
        if (current->next == NULL) {
          tail = current;
        }
        current = current->next;
      }
      delete temp;
    } else {
      previous = current;
      current = current->next;
    }
  }
}