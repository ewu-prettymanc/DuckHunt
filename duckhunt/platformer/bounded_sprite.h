#ifndef __BOUNDED_SPRITE_H__
#define __BOUNDED_SPRITE_H__

#include "sprite.h"

class bounded_sprite : public sprite
{
public:

  bounded_sprite(char * filename, SDL_Rect bounds);
  ~bounded_sprite();

  void set_bounds(SDL_Rect bounds);
  
  void move();
  
  int at_left_or_right_bounds();


protected:

  virtual void hit_left_bound();
  virtual void hit_right_bound();
  virtual void hit_top_bound();
  virtual void hit_bottom_bound();

  SDL_Rect _bounds;
  
};



#endif
