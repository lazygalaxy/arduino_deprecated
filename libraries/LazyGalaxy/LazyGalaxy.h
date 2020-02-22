/*
   LazyGalaxy.h - Static classes to make life happy for your projects.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 21, 2020.
   Released into the public domain.
 */

#ifndef LazyGalaxy_h
#define LazyGalaxy_h

#include <Arduino.h>
#include <Timer.h>

typedef void (*funcPtr)(void);

static Timer* timer = new Timer();

static void update() { timer->update(millis()); }

static void scheduleTask(unsigned int delay, funcPtr callback) {
  timer->schedule(delay + millis(), callback);
}

#endif