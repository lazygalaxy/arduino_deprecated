/*
   Component.h - Base class for all component
   Created by LazyGalaxy - Evangelos Papakonstantis, February 24, 2020.
   Released into the public domain.
 */

#ifndef COMPONENT_h
#define COMPONENT_h

// TODO: maybe share this in LazyGalaxy
class Component {
 public:
  virtual void update(unsigned long time);
};

#endif
