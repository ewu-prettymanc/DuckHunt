#include "dead_duck_array.h"

dead_duck_array::dead_duck_array(SDL_Rect bounds)
  : sprite_array(), _bounds( bounds)
{
}

dead_duck_array::~dead_duck_array()
{
}

void dead_duck_array::spawn_dead_duck( image * duck )
{
  gravity_sprite * g; 
  int x; 
  int y; 
  
  g = new gravity_sprite((char* ) DEAD_DUCK, _bounds,
			  DEAD_DUCK_GRAVITY, DEAD_DUCK_TERMINAL ); 
  assert( g); 
  
  x = duck->get_centerx(); 
  y = duck->get_centery(); 
  g-> set_xy(x,y,1); 
  
  add( g ); 
}


void dead_duck_array::remove_dead_ducks( skeleton_array * sk,
					 Mix_Chunk * dead_quack)
{
  int i; 
  gravity_sprite * g;  
  
  for(i=0; i<_curr_size; i++)
    {
      g = (gravity_sprite * ) _img[i]; 
      
      if( g->at_bottom_bounds() )
	{
	  sk->spawn_skeleton( _img[i], dead_quack ); 
	  kill(i); 
	  i--; 
	}
    }
}
