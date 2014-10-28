
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
  if ( _dy > _terminal )
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
  //  if ( _dy > 0 )
  
  _dy = 0;
  _curr_accel = 0;
  _dest.y = _bounds.y + _bounds.h - _dest.h;
}


void gravity_sprite::set_dy(int amt)
{
  if ( _dy == 0 )
    _dy = amt;
}

void gravity_sprite::check_platform(image_array * platforms)
{
  int which, top;
  image * p;

  which = platforms->collide(this);

  // if no collisions
  if ( which == -1 )
  {
    if ( _dest.y + _dest.h < _bounds.y + _bounds.h )  // don't start acceleratint
                                                      // if we are at the bottom
      _curr_accel = _accel_of_gravity;
    return;
  }

  p = platforms->get_image(which);

  if ( p->get_centery() > get_centery() ) // sprite is moving down
  {
    // if collision
    _curr_accel = 0;
    
    if ( _dy > 0 )
      _dy = 0;
    
    top = p->get_centery() - p->get_height()/2;
    
    _dest.y = top - _dest.h;
  }
  else if ( _dy < 0 && p->get_centery() < get_centery()  )
  {
    // sprite is moving up and below the platform
    _dest.y = p->get_centery() + p->get_height()/2;
    _dy = 0;
    _curr_accel = _accel_of_gravity;
  }

  
}

