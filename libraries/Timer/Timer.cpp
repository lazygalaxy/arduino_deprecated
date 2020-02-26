/*
   Timer.cpp - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#include <Timer.h>

Timer::Timer() {}

void Timer::schedule(unsigned long triggerTime, funcPtr callback) {
  TimerTask *task = new TimerTask(triggerTime, callback);
  addTask(task);
}

void Timer::schedule(unsigned long triggerTime, Component *component) {
  TimerTask *task = new TimerTask(triggerTime, component);
  addTask(task);
}

void Timer::addTask(TimerTask *task) {
  if (head == NULL) {
    head = task;
    tail = task;
  } else {
    tail->next = task;
    tail = task;
  }
}

void Timer::update(unsigned long time) {
  TimerTask *current = head;
  TimerTask *previous = NULL;
  while (current != NULL) {
    Serial.println(String(current->triggerTime) + " " + String(time));
    if (current->triggerTime <= time) {
      if (current->callback != NULL) {
        current->callback();
      } else if (current->component != NULL) {
        current->component->update(time);
      }
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