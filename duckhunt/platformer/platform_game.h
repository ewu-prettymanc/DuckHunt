#ifndef __PLATFORM_GAME_H__
#define __PLATFORM_GAME_H__

#include "base_game.h"
#include "gravity_sprite.h"
#include "platform_array.h"
#include "ford_array.h"
#include "cheese_array.h"
#include "fish_array.h"

#define JOHN_GRAVITY 1
#define JOHN_TERMINAL 10
#define JOHN_JUMP -20
#define JOHN_MOVE 5

#define FORD_SPAWN 100
#define CHEESE_SPAWN 100

#define FORD_INIT 5
#define CHEESE_INIT 5

class platform_game : public base_game
{
 public:

  platform_game();
  ~platform_game();

 protected:

  virtual void handle_events();
  virtual void handle_collisions(); 
  virtual void draw();
  virtual void set_up();

  gravity_sprite * _john;
  platform_array * _platforms;
  ford_array * _fords;
  cheese_array * _cheeses;
  fish_array * _fishes;

};


#endif
