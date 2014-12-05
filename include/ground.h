#ifndef VB_GROUND_H
#define VB_GROUND_H

#include <SDL2/SDL.h>
#include "view.h"

typedef struct
{
  // TODO: z buffer
  SDL_Texture *tex;
}
VB_Ground;

SDL_bool vb_ground_isok(VB_Ground *ground);
SDL_bool vb_ground_init(VB_View *view, VB_Ground *ground);
void vb_ground_free(VB_Ground *ground);
void vb_ground_render(VB_View *view, VB_Ground *ground);

#endif
