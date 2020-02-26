/*
   LazyGalaxy.h - Static classes to make life happy for your projects.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 21, 2020.
   Released into the public domain.
 */

#ifndef LazyGalaxy_h
#define LazyGalaxy_h

#include <Arduino.h>
#include <Component.h>
#include <Timer.h>

typedef void (*funcPtr)(void);

static void update() { Timer::getInstance()->update(millis()); }

static void scheduleTask(unsigned int delay, funcPtr callback) {
  Timer::getInstance()->schedule(delay + millis(), callback);
}

static void scheduleTask(unsigned long triggerTime, Component* component) {
  Timer::getInstance()->schedule(triggerTime, component);
}

#endif