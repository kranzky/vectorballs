#ifndef VB_VIEW_H
#define VB_VIEW_H

#include <SDL2/SDL.h>

typedef struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
VB_View;

VB_View * vb_view_init();
void vb_view_free(VB_View *view);

#endif
