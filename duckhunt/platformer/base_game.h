#ifndef __BASE_GAME_H__
#define __BASE_GAME_H__

#include "image.h"


// an abstract class is a class with an abstract method
//  you can never have an instance of an abstract class in your program
class base_game
{
 public:

  base_game(char *back, int width, int height);
  virtual ~base_game();

  virtual void play_game();
  
 protected:

  virtual void handle_events();
  virtual void handle_collisions()=0;  //abstract method -- no body
  virtual void set_up()=0;
  virtual void draw();

  SDL_Surface * _screen;
  image * _back;
  SDL_Event _event;
  int _done;
  

};

#endif
