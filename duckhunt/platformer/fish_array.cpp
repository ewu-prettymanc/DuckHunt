#include "fish_array.h"
#include<string.h>

fish_array::fish_array(char *filename, SDL_Rect bounds)
  : sprite_array(), _bounds(bounds)
{
  _filename = new char[strlen(filename) + 1];
  assert(_filename);

  strcpy(_filename, filename);
}

fish_array::~fish_array()
{
  delete [] _filename;
}

void fish_array::fire(sprite * john)
{
  int x,y, dx;

  bounded_sprite * b = new bounded_sprite(_filename, _bounds);
  assert(b);

  x = john->get_centerx();
  y = john->get_centery();
  dx = john->get_dx();

  if ( dx > 0 )
    dx = FISH_SPEED;
  else
    dx = -FISH_SPEED;

  b->set_xy(x,y);
  b->set_dxdy(dx,0);
  
  add(b);
  
}

void fish_array::hit_ford(ford_array *fa)
{
  int fishi, fordi;

  for ( fishi = 0; fishi < _curr_size; fishi++ )
  {
    fordi = fa->collide( _img[fishi] );

    if ( fordi >= 0 )
    {
      kill(fishi);
      fa->kill(fordi);
      fishi --;
    }
  }
  
}

void fish_array::remove_dead_fish()
{
  bounded_sprite * b;
  int i;

  for ( i = 0; i < _curr_size; i ++ )
  {
    b =  (bounded_sprite*) _img[i];

    if ( b->at_left_or_right_bounds() )
    {
      kill(i);
      i--;
    }
  }
}


