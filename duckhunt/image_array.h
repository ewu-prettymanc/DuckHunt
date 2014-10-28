#ifndef __IMAGE_ARRAY_H__
#define __IMAGE_ARRAY_H__

#include "image.h"

class image_array
{
 public:

  image_array(int size=10);
  virtual ~image_array();

  virtual void add(image * i);
  virtual void kill(image *i);
  virtual void kill(int i);

  int get_curr_size();
  
  virtual int collide(image * i);
  virtual void draw(SDL_Surface * screen);
  virtual image * get_image(int which);

 protected:

  void grow();

  image ** _img;
  int _max_size, _curr_size;

};

#endif
