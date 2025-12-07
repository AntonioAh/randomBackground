#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <string>
#include <random>

constexpr int kScreenWidth{640};
constexpr int kScreenHeight{480};


bool init();
void close();

SDL_Window *gWindow{nullptr};
SDL_Surface *gScreenSurface{nullptr};
SDL_Surface *gHelloWord {nullptr};

bool init(){
  bool success{true};

  if (SDL_Init(SDL_INIT_VIDEO) == false){
    SDL_Log( "SDL could not initialize! SDL error: %s\n", SDL_GetError() );
    success = false;
  }
  else{
    if (gWindow = SDL_CreateWindow("Sprouts", kScreenWidth, kScreenHeight, 0); gWindow == nullptr){
      SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
      success = false;
    }
    else
      gScreenSurface = SDL_GetWindowSurface(gWindow);
  }

  return success;
}

void close(){
  SDL_DestroySurface( gHelloWord );
  gHelloWord = nullptr;

  SDL_DestroyWindow( gWindow );
  gWindow = nullptr;
  gScreenSurface = nullptr;

  SDL_Quit();
}

int main(){
  int exitCode{ 0 };

  if ( init() == false ){
    SDL_Log( "Unable to initialize program!\n" );
    exitCode = 1;
  }
  else{
    bool quit{ false };
    std::srand( std::time( {} ) );



    SDL_Event e;
    SDL_zero( e );

    while ( quit == false ){
      while ( SDL_PollEvent( &e ) == true ){
        if ( e.type == SDL_EVENT_QUIT || ( e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_Q ))
          quit = true;
        else if (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_R){
          const Uint8 r = std::rand() % 256, g = std::rand() % 256, b = std::rand() % 256;
          SDL_FillSurfaceRect( gScreenSurface, nullptr, SDL_MapSurfaceRGB( gScreenSurface, r, g, b ) );
        }
      }

      SDL_UpdateWindowSurface( gWindow );
    }
  }

  close();
  return exitCode;
}