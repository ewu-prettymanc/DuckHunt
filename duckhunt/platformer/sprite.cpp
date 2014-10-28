
#include "sprite.h"

sprite::sprite(char *filename)
  : image(filename)
{
  _dx = _dy = 0;
  //  cerr<<"calling sprite constructor."<<endl;
}

sprite::~sprite()
{
  // cerr<<"calling sprite destructor"<<endl;
}

void sprite::set_dxdy(int dx, int dy)
{
  _dx = dx;
  _dy = dy;
}

void sprite::set_dx(int amt)
{
  _dx = amt;
}

void sprite::move()
{
  _dest.x += _dx;
  _dest.y += _dy;
}

void sprite::draw(SDL_Surface * screen)
{
  //cerr<<"calling sprite's draw"<<endl;
  move();
  image::draw(screen);
}


int sprite::is_image()
{
  return 0;
}

int sprite::is_sprite()
{
  return 1;
}

void sprite::inc_dx(int amt)
{
  _dx += amt;
}

void sprite::inc_dy(int amt)
{
  _dy += amt;
}


int sprite::get_dx()
{
  return _dx;
}

int sprite::get_dy()
{
  return _dy;
}
