/*
   Timer.cpp - Library for scheduling tasks using a timer.
   Created by LazyGalaxy - Evangelos Papakonstantis, Febraury 1, 2020.
   Released into the public domain.
 */

#include "Timer.h"

Timer::Timer() {}

void Timer::schedule(unsigned int delay, funcPtr callback) {
  TimerTask task(delay + millis(), callback);
  for (int i = 0; i < TASK_SIZE; i++) {
    if (tasks[i] == NULL) {
      tasks[i] = &task;
      Serial.println(String(tasks[i]->time) + " " + String(i));
      break;
    }
  }
}

void Timer::update() {
  Serial.println(String(tasks[0]->time));
  Serial.println(String(tasks[1]->time));
  unsigned long time = millis();
  for (int i = 0; i < TASK_SIZE; i++) {
    if (tasks[i] != NULL) {
      // Serial.println(String(tasks[i]->time) + " " + String(i));
      if (tasks[i]->time <= time) {
        Serial.println("Trigger!");
        tasks[i]->callback();
        tasks[i] = NULL;
      }
    }
  }
}