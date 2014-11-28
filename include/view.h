#ifndef VB_VIEW_H
#define VB_VIEW_H

#include <stdbool.h>
#include <SDL2/SDL.h>

typedef struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
VB_View;

bool vb_view_isok(VB_View *view);
bool vb_view_init(VB_View *view);
void vb_view_free(VB_View *view);

#endif