#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "view.h"

SDL_bool
vb_view_isok(VB_View *view)
{
  return (view->window != NULL) && (view->renderer != NULL);
}

SDL_bool
vb_view_init(VB_View *view)
{
  //view->window = SDL_CreateWindow("=== V E C T O R B A L L S ===", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_HIDDEN);
  view->window = SDL_CreateWindow("=== V E C T O R B A L L S ===", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_HIDDEN);
  if (view->window != NULL)
  {
    view->renderer = SDL_CreateRenderer(view->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  }
  return vb_view_isok(view);
}

void
vb_view_free(VB_View *view)
{
  if (view->renderer)
  {
    SDL_DestroyRenderer(view->renderer);
    view->renderer = NULL;
  }
  if (view->window)
  {
    SDL_DestroyWindow(view->window);
    view->window = NULL;
  }
}
