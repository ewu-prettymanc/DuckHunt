#include "left_right.h"

left_right::left_right( char * filename, SDL_Rect bounds )
  : bounded_sprite( filename, bounds )
{
  _right =  IMG_Load( (char* ) RIGHT_DUCK ); 
  if ( ! _img )
  {
    cerr<<"Could not load "<<RIGHT_DUCK<<endl;
    cerr<<IMG_GetError()<<endl;
    exit(1);
  } 

  _left = IMG_Load( (char *) LEFT_DUCK ); 
  if ( ! _img )
  {
    cerr<<"Could not load "<<LEFT_DUCK<<endl;
    cerr<<IMG_GetError()<<endl;
    exit(1);
  } 

  move(); 
}
 
left_right::~left_right()
{
  _img = _left; 
  SDL_FreeSurface( _right ); 
} 
  
void left_right::move()
{
  if( _dx < 0 )
    _img = _left; 
  else 
    _img = _right; 
  
  bounded_sprite::move(); 
}
