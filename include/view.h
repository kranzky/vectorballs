#ifndef VB_VIEW_H
#define VB_VIEW_H

#include <SDL2/SDL.h>

//==============================================================================

#define WIDTH 1024
#define HEIGHT 576

typedef struct
{
  SDL_Window *window;
  SDL_Renderer *renderer;
}
VB_View;

//------------------------------------------------------------------------------

VB_View * vb_view_init();
void vb_view_free(VB_View *view);

//==============================================================================

#endif
