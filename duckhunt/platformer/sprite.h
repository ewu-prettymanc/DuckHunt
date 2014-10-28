#ifndef __SPRITE_H__
#define __SPRITE_H__

#include"image.h"


class sprite : public image
{
 public:

  sprite(char *filename);
  ~sprite();

  void set_dxdy(int dx, int dy);
  virtual void move();
  void draw(SDL_Surface * screen);

  virtual void inc_dx(int amt);
  virtual void inc_dy(int amt);

  virtual void set_dx(int amt);
  int is_image();
  int is_sprite();

  int get_dx();
  int get_dy();

 protected:

  int _dx, _dy;

  

};



#endif
