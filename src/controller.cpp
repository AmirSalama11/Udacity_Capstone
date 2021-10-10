#include "controller.h"
#include <iostream>
#include "SDL.h"
#include "snake.h"

void Controller::ChangeDirection(Snake<int> &snake, Snake<int>::Direction input,
                                 Snake<int>::Direction opposite) const {
  if (snake.direction != opposite || snake.size == 1) snake.direction = input;
  return;
}

void Controller::HandleInput(bool &running, Snake<int> &snake) const {
  SDL_Event e;
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_QUIT) {
      running = false;
    } else if (e.type == SDL_KEYDOWN) {
      switch (e.key.keysym.sym) {
        case SDLK_UP:
          ChangeDirection(snake, Snake<int>::Direction::kUp,
                          Snake<int>::Direction::kDown);
          break;

        case SDLK_DOWN:
          ChangeDirection(snake, Snake<int>::Direction::kDown,
                          Snake<int>::Direction::kUp);
          break;

        case SDLK_LEFT:
          ChangeDirection(snake, Snake<int>::Direction::kLeft,
                          Snake<int>::Direction::kRight);
          break;

        case SDLK_RIGHT:
          ChangeDirection(snake, Snake<int>::Direction::kRight,
                          Snake<int>::Direction::kLeft);
          break;
      }
    }
  }
}