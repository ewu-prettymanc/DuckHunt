#include "ford_array.h"

#include <string.h>

ford_array::ford_array(char *filename, int spawn_rate, SDL_Rect bounds)
  : sprite_array(),  _time(0), _spawn_rate(spawn_rate), _bounds(bounds)
{

  _filename = new char[strlen(filename) + 1];
  assert(_filename);

  strcpy(_filename, filename);
}

ford_array::~ford_array()
{
  delete [] _filename;
}

void ford_array::spawn_ford(int howmany)
{
  int i, x, dx;
  gravity_sprite * g;

  for ( i = 0; i < howmany; i ++ )
  {
    g = new gravity_sprite(_filename, _bounds, FORD_GRAVITY, FORD_TERMINAL);
    assert(g);

    x = rand() % ( _bounds.w - g->get_width() ) + _bounds.x;

    dx = rand() % 2;

    if ( dx == 0 )
      dx = -5;
    else
      dx = 5;

    g->set_xy(x,0,0);
    g->set_dxdy(dx, 0);

    add(g);
  }
}

void ford_array::draw(SDL_Surface * screen)
{
  sprite_array::draw(screen);

  _time++;

  if ( _time == _spawn_rate )
  {
    _time = 0;
    spawn_ford(1);
  }
}

void ford_array::remove_stalled_fords()
{
  int i;
  gravity_sprite * g;

  for ( i = 0; i < _curr_size; i ++ )
  {
    g = (gravity_sprite *) _img[i];

    if ( g->at_left_or_right_bounds() )
    {
      kill(i);
      i--;
    }
  }
}


void ford_array::check_platforms(image_array * platforms)
{
  gravity_sprite * s;
  int i;

  for ( i = 0; i < _curr_size; i ++ )
  {
    s = (gravity_sprite *) _img[i];

    s->check_platform(platforms);
  }
  
}
