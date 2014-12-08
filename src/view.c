#include "view.h"

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

VB_View *
vb_view_init()
{
  VB_View *view = malloc(sizeof(VB_View));
  if (view == NULL)
  {
    return NULL;
  }

  //view->window = SDL_CreateWindow("=== V E C T O R B A L L S ===", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_FULLSCREEN | SDL_WINDOW_HIDDEN);
  view->window = SDL_CreateWindow("=== V E C T O R B A L L S ===", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900, SDL_WINDOW_HIDDEN);
  if (view->window == NULL)
  {
    vb_view_free(view);
    return NULL;
  }

  view->renderer = SDL_CreateRenderer(view->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (view->renderer == NULL)
  {
    vb_view_free(view);
    return NULL;
  }

  return view;
}

void
vb_view_free(VB_View *view)
{
  if (view->renderer != NULL)
  {
    SDL_DestroyRenderer(view->renderer);
    view->renderer = NULL;
  }

  if (view->window != NULL)
  {
    SDL_DestroyWindow(view->window);
    view->window = NULL;
  }

  free(view);
}
