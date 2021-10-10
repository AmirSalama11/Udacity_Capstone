#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "snake.h"

class Controller {
 public:
  void HandleInput(bool &running, Snake<int> &snake) const;

 private:
  void ChangeDirection(Snake<int> &snake, Snake<int>::Direction input,
                       Snake<int>::Direction opposite) const;
};

#endif