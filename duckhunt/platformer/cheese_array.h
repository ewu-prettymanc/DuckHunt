#ifndef __CHEESE_ARRAY_H__
#define __CHEESE_ARRAY_H__

#include "sprite_array.h"
#include "gravity_sprite.h"

#define CHEESE_GRAVITY 1
#define CHEESE_TERMINAL 10

class cheese_array : public sprite_array
{
public:

  cheese_array(char * filename, int spawn_rate, SDL_Rect bounds);
  ~cheese_array();

  void spawn_cheese(int howmany);
  void draw(SDL_Surface * screen);
  int run_over_cheese(image * john);
  void check_platforms(image_array * platforms);

protected:

  char * _filename;
  int _time, _spawn_rate;
  SDL_Rect _bounds;

};


#endif
