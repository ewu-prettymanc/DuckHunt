#ifndef __DEAD_DUCK_ARRAY_H__
#define __DEAD_DUCK_ARRAY_H__

#include "sprite_array.h"
#include "gravity_sprite.h"
#include "game_data.h"
#include "skeleton_array.h"
#include "SDL_mixer.h"

class dead_duck_array : public sprite_array
{
 public: 
  
  dead_duck_array( SDL_Rect bounds );
  ~dead_duck_array(); 
  
  void spawn_dead_duck( image * duck );
  void remove_dead_ducks( skeleton_array * sk, Mix_Chunk * dead_quack); 
  
 protected: 
  SDL_Rect _bounds; 
  
};

#endif
