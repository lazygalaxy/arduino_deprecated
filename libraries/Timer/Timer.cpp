/*
   Timer.cpp - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#include <Arduino.h>
#include <Timer.h>

Timer::Timer() {}

unsigned long Timer::schedule(unsigned long triggerTime, funcPtr callback,
                              unsigned int repeatDelay) {
  TimerTask *task = new TimerTask(triggerTime, callback, repeatDelay);
  addTask(task);
  return task->id;
}

unsigned long Timer::schedule(unsigned long triggerTime, Component *component,
                              unsigned int repeatDelay) {
  TimerTask *task = new TimerTask(triggerTime, component, repeatDelay);
  addTask(task);
  return task->id;
}

void Timer::addTask(TimerTask *task) {
  if (head == nullptr) {
    head = task;
    tail = task;
  } else {
    tail->next = task;
    tail = task;
  }
}

bool Timer::unschedule(unsigned long taskId) {
  TimerTask *current = head;
  TimerTask *previous = nullptr;
  while (current != nullptr) {
    if (current->id == taskId) {
      TimerTask *temp = current;
      if (previous == nullptr) {
        head = head->next;
        if (head == nullptr) {
          tail = nullptr;
        }
        current = current->next;
      } else {
        previous->next = current->next;
        if (current->next == nullptr) {
          tail = current;
        }
        current = current->next;
      }
      delete temp;
      return true;
    } else {
      previous = current;
      current = current->next;
    }
  }
  return false;
}

void Timer::update(unsigned long time) {
  TimerTask *current = head;
  TimerTask *previous = nullptr;
  while (current != nullptr) {
    bool remove = false;
    if (current->triggerTime <= time) {
      if (current->callback != nullptr) {
        current->callback();
      } else if (current->component != nullptr) {
        current->component->update(time);
      }

      if (current->repeatDelay > 0) {
        current->triggerTime = time + current->repeatDelay;
      } else {
        TimerTask *temp = current;
        if (previous == nullptr) {
          head = head->next;
          if (head == nullptr) {
            tail = nullptr;
          }
          current = current->next;
        } else {
          previous->next = current->next;
          if (current->next == nullptr) {
            tail = current;
          }
          current = current->next;
        }
        delete temp;
        remove = true;
      }
    }
    if (!remove) {
      previous = current;
      current = current->next;
    }
  }
}