#include "platform_game.h"

platform_game::platform_game()
  : base_game( (char*) "imgs/back/back.jpg", 1200, 833) 
{
  SDL_Rect b;

  b.x = 0;
  b.y = 0;
  b.w = _screen->w;
  b.h = _screen->h;

  _john = new gravity_sprite((char*) "imgs/john/john.png",b,
			     JOHN_GRAVITY, JOHN_TERMINAL);
  assert(_john);
		
  _platforms = new platform_array( (char*) "imgs/platform/platform.png",
				   (char*) "level1.txt");
  assert(_platforms);
	     
  _fords = new ford_array( (char*) "imgs/ford/ford.png", FORD_SPAWN, b);
  assert(_fords);

  _cheeses = new cheese_array( (char*) "imgs/cheese/cheese.png", 
			       CHEESE_SPAWN, b);
  assert(_cheeses);

  _fishes = new fish_array( (char*) "imgs/fish/fish.png", b);
  assert(_fishes);
			   
}

platform_game::~platform_game()
{
  delete _john;
  delete _platforms;
  delete _fords;
  delete _cheeses;
  delete _fishes;
}


void platform_game::handle_events()
{



  if ( _event.type == SDL_KEYDOWN )
  {
    if ( _event.key.keysym.sym == SDLK_ESCAPE )
    {
      _done = 1;
      return;
    }
    if ( _event.key.keysym.sym == SDLK_w )
      _john->set_dy(JOHN_JUMP);
    if ( _event.key.keysym.sym == SDLK_a )
      _john->set_dx(-JOHN_MOVE);
    if ( _event.key.keysym.sym == SDLK_d )
      _john->set_dx(JOHN_MOVE);

    if ( _event.key.keysym.sym == SDLK_SPACE )
      _fishes->fire(_john);

    return;
  }


  base_game::handle_events();
}

void platform_game::handle_collisions()
{
  // john

  if ( _fords->collide(_john) != -1 )
  {
    cout<<"John is dead"<<endl;
    _done = 1;
  }

  _cheeses->run_over_cheese(_john);

  _john->check_platform(_platforms);
  
  // fishes
  _fishes->hit_ford( _fords );
  _fishes->remove_dead_fish();

  // fords
  _fords->remove_stalled_fords();
  _fords->check_platforms(_platforms);

  // cheese
  _cheeses->check_platforms(_platforms);
  
}

void platform_game::draw()
{
  base_game::draw();
  
  _cheeses->draw(_screen);
  _platforms->draw(_screen);
  _fishes->draw(_screen);
  _fords->draw(_screen);
  _john->draw(_screen);
}

void platform_game::set_up()
{
  _john->set_xy( _screen->w/2, _screen->h/2 );

  _cheeses->spawn_cheese(CHEESE_INIT);

  _fords->spawn_ford(FORD_INIT);
}
