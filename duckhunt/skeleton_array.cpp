#include "skeleton_array.h"

skeleton_array::skeleton_array( int size )
  : image_array(size ) 
{

}

skeleton_array::~skeleton_array()
{

}


void skeleton_array::spawn_skeleton( image * i , Mix_Chunk * dead_quack)
{
  image * skeleton; 
  int x, y; 
  
  Mix_PlayChannel( -1, dead_quack, 0 ); 

  x = i->get_centerx(); 
  y = i->get_centery(); 
   
  skeleton = new image ( (char * ) SKELETON_DUCK ); 
  assert( skeleton ); 
  
  skeleton->set_xy( x, y, 1 ); 
  
  add( skeleton );  
}
