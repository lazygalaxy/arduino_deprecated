/*
   LazyGalaxy.h - Static classes to make life happy for your projects.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 21, 2020.
   Released into the public domain.
 */

#ifndef LazyGalaxy_h
#define LazyGalaxy_h

#include <Component.h>
#include <Timer.h>

static const uint8_t D0 = 0;
static const uint8_t D1 = 1;
static const uint8_t D2 = 2;
static const uint8_t D3 = 3;
static const uint8_t D4 = 4;
static const uint8_t D5 = 5;
static const uint8_t D6 = 6;
static const uint8_t D7 = 7;
static const uint8_t D8 = 8;
static const uint8_t D9 = 9;
static const uint8_t D10 = 10;
static const uint8_t D11 = 11;
static const uint8_t D12 = 12;
static const uint8_t D13 = 13;

// TODO: somehow shared as it is also used in LED project
typedef void (*funcPtr)(void);

static void update() { Timer::getInstance()->update(millis()); }

static void scheduleTask(unsigned int delay, funcPtr callback,
                         unsigned int repeatDelay = 0) {
  Timer::getInstance()->schedule(delay + millis(), callback, repeatDelay);
}

#endif