#ifndef __DUCKHUNT_GAME_H__
#define __DUCKHUNT_GAME_H__

#include "game_data.h"
#include "SDL_mixer.h"

#include "base_game.h"
#include "gravity_sprite.h"
#include "duck_array.h"
#include "dead_duck_array.h"
#include "skeleton_array.h" 

class duckhunt_game : public base_game
{
 public:

  duckhunt_game();
  ~duckhunt_game();

 protected:

  virtual void handle_events();
  virtual void handle_collisions(); 
  virtual void draw();
  virtual void set_up();

  duck_array * _ducks;
  dead_duck_array * _dead_ducks; 
  skeleton_array * _skeletons; 
  Mix_Chunk * _shutup;
  Mix_Chunk * _quack;
  Mix_Chunk * _dead_quack; 
  Mix_Chunk * _pop; 
  Mix_Music * _music; 


};


#endif
