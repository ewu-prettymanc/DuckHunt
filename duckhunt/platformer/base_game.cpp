#include "base_game.h"

base_game::base_game(char *back, int width, int height)
{
  if ( SDL_Init(SDL_INIT_VIDEO | SDL_INIT_NOPARACHUTE) )
  {
    cerr<<"Could not init sdl: "<<SDL_GetError()<<endl;
    exit(1);
  }

  _screen = SDL_SetVideoMode(width, height, 0,0);

  if ( ! _screen )
  {
    cerr<<"Could not init video mode: "<<SDL_GetError()<<endl;
    exit(1);
  }

  _back = new image( back );
  assert(_back);
  
  _back->set_xy(0,0,0);
}

base_game::~base_game()
{
  delete _back;
  SDL_Quit();
}

void base_game::play_game()
{
  _done = 0;

  set_up();
  
  while ( ! _done )
  {
    while ( !_done && SDL_PollEvent(&_event) )
      handle_events();
    
    handle_collisions();

    draw();
    SDL_UpdateRect(_screen, 0,0,0,0);
  }
}

void base_game::handle_events()
{
  if ( _event.type == SDL_QUIT )
    _done = 1;
}


void base_game::draw()
{
  _back->draw(_screen);
}
