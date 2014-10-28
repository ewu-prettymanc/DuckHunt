#include "duckhunt_game.h"

duckhunt_game::duckhunt_game()
  : base_game(  (char * ) BACK, 1152, 720) 
{
  SDL_Rect b;

  b.x = 0;
  b.y = 0;
  b.w = _screen->w;
  b.h = _screen->h;
  

  _shutup= Mix_LoadWAV( (char *) SHUTUP ); 
  _quack = Mix_LoadWAV( (char *) QUACK ); 
  _dead_quack = Mix_LoadWAV( (char*) DEAD_QUACK ); 
  _pop = Mix_LoadWAV( (char*) POP ); 
  _music = Mix_LoadMUS( (char* ) MUSIC); 

  if ( ! _shutup  || ! _quack  || ! _dead_quack || ! _pop || ! _music)
  {
    cerr<<"Could not init sound: "<<Mix_GetError()<<endl;
    exit(1);
  } 

  Mix_PlayMusic( _music, -1 ); // loop infinitly streaming the music 

  _ducks = new duck_array( b );
  assert(_ducks);

  _skeletons = new skeleton_array(10); 
  assert( _skeletons ); 
  
  _dead_ducks = new dead_duck_array( b ); 
  assert( _dead_ducks); 
}// SDL apparetently scales the iamge

duckhunt_game::~duckhunt_game()
{
  delete _ducks;
  delete _dead_ducks; 
  delete _skeletons; 

  Mix_FreeChunk( _shutup );
  Mix_FreeChunk( _dead_quack );
  Mix_FreeChunk( _quack );
  Mix_FreeChunk( _pop ); 
  Mix_FreeMusic( _music ); 
  // closed the audio in basegame.cpp
}


void duckhunt_game::handle_events()
{ 
  // mouse polling event will go here 
  if ( _event.type == SDL_KEYDOWN )
  {
    if(_event.key.keysym.sym == SDLK_ESCAPE )
       _done = 1; 
    if( _event.key.keysym.sym == SDLK_q )
      _done = 1;
  }    
    
  base_game::handle_events(); 
}

void duckhunt_game::handle_collisions()
{
  _ducks->hit_duck( & _event , _dead_ducks, _shutup);
  //check to see for mouse collision events 
  _ducks->remove_high_ducks( _pop ); 
  _dead_ducks->remove_dead_ducks( _skeletons, _dead_quack ); 
}


void duckhunt_game::draw()
{
  base_game::draw();
  
  _ducks->draw(_screen, _quack);
  _dead_ducks->draw(_screen); 
  _skeletons->draw(_screen); 
}

void duckhunt_game::set_up()
{
  _ducks->spawn_duck(DUCK_INIT, _quack);
}
