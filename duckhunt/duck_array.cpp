#include "duck_array.h"
#include<string.h>

duck_array::duck_array( SDL_Rect bounds)
  : sprite_array(), _time(0), _bounds(bounds) 
{
  // all this data in game_data.h; 
  _spawn_rate = DUCK_SPAWN;
}

duck_array::~duck_array()
{
}


void duck_array::spawn_duck(int howmany, Mix_Chunk * quack)
{
  int i;
  left_right * b; 
  int x;
  int y; // where we want to spawn it
  int dx; 

  for ( i = 0; i < howmany; i ++ )
  {
    Mix_PlayChannel( -1, quack, 1 ); // play the sound 2 quacks 
    dx = rand () % 2; 

    if( dx == 0 )
      {
	dx = POS_DX; 
	b = new left_right((char*) RIGHT_DUCK, _bounds); 		      
	assert(b);
      }
    else 
      {
	dx = NEG_DX;
	b = new left_right( (char*)LEFT_DUCK, _bounds); 
	assert(b);
      } 

    x = rand() % ( _bounds.w - b->get_width() ) + _bounds.x;
    y = _bounds.y + _bounds.h - b->get_height(); 
    
   
    b->set_xy(x,y,0);// ( x, y, center )
    b->set_dxdy( dx, DY); 
    add(b);
  }
  
}


void duck_array::draw(SDL_Surface * screen, Mix_Chunk * quack )
{
  sprite_array::draw(screen);
  
  _time++;

  if ( _time == _spawn_rate )
  {
    _time = 0;
    spawn_duck(1, quack);
  }
  
}


void  duck_array::hit_duck(SDL_Event  * event, dead_duck_array * d,
			   Mix_Chunk * shutup )
{
  int i;
  int mouse_x=0, mouse_y=0;

  SDL_GetMouseState( & mouse_x, & mouse_y );
  if(  event->type == SDL_MOUSEBUTTONDOWN )
    {
      for ( i = 0; i < _curr_size; i++)
	if ( _img[i]->check_point( mouse_x, mouse_y )  )
	  {
	    Mix_PlayChannel(-1, shutup, 0); // play the sounds
	    d->spawn_dead_duck( _img[i] ); 
	    kill(i);
	    i--;// replaced it...not point in checking again. 
	  }
    }
}


void duck_array::remove_high_ducks( Mix_Chunk * pop )
{ 
  bounded_sprite * b;  
  int i;
  
  for( i=0; i<_curr_size; i++ )   
    {
      b = (bounded_sprite * ) _img[i]; 
      if( b->at_top_bounds() )
	{
	  Mix_PlayChannel( -1, pop, 0 ); 
	  kill(i); 
	  i--; 
	}
    }
 }
