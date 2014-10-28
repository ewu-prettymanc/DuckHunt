#ifndef __GRAVITY_SPRITE_H__
#define __GRAVITY_SPRITE_H__


#include "bounded_sprite.h"
#include "image_array.h"


class gravity_sprite : public bounded_sprite
{
  
public:

  gravity_sprite(char * filename, SDL_Rect bounds, int accel, int term);
  ~gravity_sprite();

  void move();

  void set_dy(int amt);
  // top - arc up and then down
  // bottom - stop
  // left - right - stop

protected:

  virtual void hit_left_bound();
  virtual void hit_right_bound();
  virtual  void hit_top_bound();
  virtual void hit_bottom_bound();

  int _curr_accel;
  int _accel_of_gravity;
  int _terminal;

};

#endif
