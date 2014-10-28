#include "bounded_sprite.h"


bounded_sprite::bounded_sprite(char * filename, SDL_Rect bounds)
  : sprite(filename)
{
  /*
  _bounds.x = bounds.x;
  _bounds.y = bounds.y;
  _bounds.h = bounds.h;
  _bounds.w = bounds.w;
  */

  _bounds = bounds;
    
}

bounded_sprite::~bounded_sprite()
{
}

void bounded_sprite::set_bounds(SDL_Rect bounds)
{
  _bounds = bounds;
}

void bounded_sprite::move()
{
  sprite::move();

  if ( _dest.x < _bounds.x )  // moved off the left hand side
    hit_left_bound();

  if ( _dest.y < _bounds.y ) // top
    hit_top_bound();

  if ( _dest.x + _dest.w > _bounds.x + _bounds.w ) // right
    hit_right_bound();

  if ( _dest.y + _dest.h > _bounds.y + _bounds.h ) // bottom
    hit_bottom_bound();

}
// 

void bounded_sprite::hit_left_bound()
{
  _dx *= -1;
}

void bounded_sprite::hit_right_bound()
{
  _dx *= -1;
}

void bounded_sprite::hit_top_bound()
{
  _dy *= -1;
}
void bounded_sprite::hit_bottom_bound()
{
  _dy *= -1;
}

int bounded_sprite::at_left_or_right_bounds()
{
  if ( _dest.x <= _bounds.x )
    return 1;
  if ( _dest.x + _dest.w >= _bounds.x + _bounds.w )
    return 1;

  return 0;
}
