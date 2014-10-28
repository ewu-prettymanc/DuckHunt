
#include "gravity_sprite.h"

gravity_sprite::gravity_sprite(char * filename, SDL_Rect bounds, 
			       int accel, int term)
  : bounded_sprite(filename, bounds)
{
  _accel_of_gravity = accel;
  _terminal = term;
  _curr_accel = accel;
  
}

gravity_sprite::~gravity_sprite()
{
}

void gravity_sprite::move()
{
  bounded_sprite::move();

  _dy += _curr_accel;
  if ( _dy >  _terminal )
    _dy = _terminal;
}


void gravity_sprite::hit_left_bound()
{
  _dx = 0;
  _dest.x = 0;
}

void gravity_sprite::hit_right_bound()
{
  _dx = 0;
  _dest.x = _bounds.x + _bounds.w - _dest.w;
}

void gravity_sprite::hit_top_bound()
{
  _dest.y = 0;
  _dy = 0;
}

void gravity_sprite::hit_bottom_bound()
{ 
  _dy = 0;
  _curr_accel = 0;
  _dest.y = _bounds.y + _bounds.h - _dest.h;
}


void gravity_sprite::set_dy(int amt)
{
  if ( _dy == 0 )
    _dy = amt;
}

