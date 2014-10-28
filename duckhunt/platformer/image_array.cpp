#include "image_array.h"


image_array::image_array(int size)
{
  _max_size = size;

  _img = new image*[size];
  assert(_img);

  _curr_size = 0;
}

image_array::~image_array()
{
  int i;

  for ( i = 0; i < _curr_size; i ++ )
    delete _img[i];

  delete [] _img;
}

void image_array::add(image * i)
{
  if ( _curr_size == _max_size )
    grow();

  _img[_curr_size++] = i;
}

void image_array::grow()
{
  int newsize = 3 * _max_size / 2;
  int i;
  image ** newguy = new image*[newsize];

  assert(newguy);

  for ( i = 0; i < _curr_size; i ++ )
    newguy[i] = _img[i];

  delete [] _img;

  _img = newguy;

  _max_size = newsize;
}

void image_array::kill(image *i)
{
  int index;

  for ( index = 0; index < _curr_size; index ++ )
    if ( _img[index] == i )
    {
      kill(index);
      return;
    }
}

void image_array::kill(int i)
{
  assert( i >= 0 && i < _curr_size );

  delete _img[i];

  _img[i] = _img[_curr_size-1];

  _curr_size--;
}

int image_array::get_curr_size()
{
  return _curr_size;
}

int image_array::collide(image * i)
{
  int index;

  for ( index = 0; index < _curr_size; index ++ )
    if ( i->collide( _img[index] ) )
      return index;

  return -1;
}

void image_array::draw(SDL_Surface * screen)
{
   int index;

  for ( index = 0; index < _curr_size; index ++ )
    _img[index]->draw(screen);
}

image * image_array::get_image(int which)
{
  assert(which >= 0 && which < _curr_size);

  return _img[which];
}
