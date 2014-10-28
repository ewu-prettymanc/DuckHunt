#ifndef __FISH_ARRAY_H__
#define __FISH_ARRAY_H__

#include "sprite_array.h"
#include "bounded_sprite.h"
#include "ford_array.h"

#define FISH_SPEED 10

class fish_array : public sprite_array
{
 public:

  fish_array(char *filename, SDL_Rect bounds);
  ~fish_array();

  void fire(sprite * john);
  void hit_ford(ford_array *fa);
  void remove_dead_fish();

 protected:

  char * _filename;
  SDL_Rect _bounds;

};


#endif
