#include "sprite_array.h"



sprite_array::sprite_array(int size)
  : image_array(size)
{
}

sprite_array::~sprite_array()
{
}

void sprite_array::add(image * i)
{
  assert( i->is_sprite() );
  
  image_array::add(i);
}

void sprite_array::move()
{
  int i;
  sprite * s;

  for ( i = 0; i < _curr_size; i ++ )
  {
    s = (sprite *) _img[i];
    s->move();
  }
  
}

sprite * sprite_array::get_sprite(int which)
{
  return (sprite*) get_image(which);
}
  
