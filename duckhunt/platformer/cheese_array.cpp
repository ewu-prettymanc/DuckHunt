#include "cheese_array.h"
#include<string.h>

cheese_array::cheese_array(char * filename, int spawn_rate, SDL_Rect bounds)
  : sprite_array(), _time(0),  _spawn_rate(spawn_rate), _bounds(bounds) 
{
  
  _filename = new char[strlen(filename) + 1];
  assert(_filename);

  strcpy(_filename, filename);


}

cheese_array::~cheese_array()
{
  delete [] _filename;
}

void cheese_array::spawn_cheese(int howmany)
{
  int i;
  gravity_sprite * g;
  int x;

  for ( i = 0; i < howmany; i ++ )
  {
    g = new gravity_sprite(_filename, _bounds, 
			   CHEESE_GRAVITY, CHEESE_TERMINAL);
    assert(g);
   
    x = rand() % ( _bounds.w - g->get_width() ) + _bounds.x;

    g->set_xy(x,0,0);

    add(g);
  }
  
}

void cheese_array::draw(SDL_Surface * screen)
{
  sprite_array::draw(screen);

  _time++;

  if ( _time == _spawn_rate )
  {
    _time = 0;
    spawn_cheese(1);
  }
  
}

int cheese_array::run_over_cheese(image * john)
{
  int i;
  int run = 0;

  for ( i = 0; i < _curr_size; i ++ )
    if ( john->collide( _img[i] )  )
    {
      run++;
      kill(i);
      i--;
    }
  
  return run;
}


void cheese_array::check_platforms(image_array * platforms)
{
  gravity_sprite * s;
  int i;

  for ( i = 0; i < _curr_size; i ++ )
  {
    s = (gravity_sprite *) _img[i];

    s->check_platform(platforms);
  }
  
}
