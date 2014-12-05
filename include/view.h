#ifndef VB_VIEW_H
#define VB_VIEW_H

#include <SDL2/SDL.h>

typedef struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
VB_View;

SDL_bool vb_view_isok(VB_View *view);
SDL_bool vb_view_init(VB_View *view);
void vb_view_free(VB_View *view);

#endif
