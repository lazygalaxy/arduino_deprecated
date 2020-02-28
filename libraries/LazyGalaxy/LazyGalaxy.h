/*
   LazyGalaxy.h - Static classes to make life happy for your projects.
   Created by LazyGalaxy - Evangelos Papakonstantis, February 21, 2020.
   Released into the public domain.
 */

#ifndef LazyGalaxy_h
#define LazyGalaxy_h

#include <Arduino.h>
#include <Timer.h>

struct Pin {
  Pin(boolean isDigital, int number) {
    this->isDigital = isDigital;
    this->number = number;
  }

  boolean isDigital;
  int number;
};

static Pin *P_D2 = new Pin(true, 2);
static Pin *P_D3 = new Pin(true, 3);
static Pin *P_D4 = new Pin(true, 4);
static Pin *P_D5 = new Pin(true, 5);
static Pin *P_D6 = new Pin(true, 6);
static Pin *P_D7 = new Pin(true, 7);
static Pin *P_D8 = new Pin(true, 8);
static Pin *P_D9 = new Pin(true, 9);
static Pin *P_D10 = new Pin(true, 10);
static Pin *P_D11 = new Pin(true, 11);
static Pin *P_D12 = new Pin(true, 12);
static Pin *P_A0 = new Pin(false, 0);
static Pin *P_A1 = new Pin(false, 1);
static Pin *P_A2 = new Pin(false, 2);
static Pin *P_A3 = new Pin(false, 3);
static Pin *P_A4 = new Pin(false, 4);
static Pin *P_A5 = new Pin(false, 5);
static Pin *P_A6 = new Pin(false, 6);
static Pin *P_A7 = new Pin(false, 7);

// TODO: somehow shared as it is also used in LED project
typedef void (*funcPtr)(void);

static void update() { Timer::getInstance()->update(millis()); }

static void scheduleTask(unsigned int delay, funcPtr callback) {
  Timer::getInstance()->schedule(delay + millis(), callback);
}

#endif