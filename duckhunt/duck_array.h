#ifndef __DUCK_ARRAY_H__
#define __DUCK_ARRAY_H__

#include "sprite_array.h"
#include "dead_duck_array.h"
#include "gravity_sprite.h"
#include "left_right.h"
#include "game_data.h"
#include "image_array.h"
#include "SDL_mixer.h"


class duck_array : public sprite_array
{
public:

  duck_array( SDL_Rect bounds);
  ~duck_array();

  virtual void spawn_duck(int howmany, Mix_Chunk * quack);
  virtual void draw(SDL_Surface * screen, Mix_Chunk * quack);
  virtual void hit_duck(SDL_Event * event, dead_duck_array * d,
			Mix_Chunk * shutup);
  virtual void remove_high_ducks( Mix_Chunk * pop ); 
   
protected:

  int _time,_spawn_rate; 
  SDL_Rect _bounds;
 
 

};


#endif
