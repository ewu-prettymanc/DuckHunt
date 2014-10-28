#ifndef __FORD_ARRAY_H__
#define __FORD_ARRAY_H__

#include "sprite_array.h"
#include "gravity_sprite.h"

#define FORD_GRAVITY 1
#define FORD_TERMINAL 10

class ford_array : public sprite_array
{
 public:

  ford_array(char *filename, int spawn_rate, SDL_Rect bounds);
  ~ford_array();

  void spawn_ford(int howmany);
  void draw(SDL_Surface * screen);
  void remove_stalled_fords();
  void check_platforms(image_array * platforms);

 protected:

  char * _filename;
  int _time, _spawn_rate;
  SDL_Rect _bounds;
  
};


#endif
