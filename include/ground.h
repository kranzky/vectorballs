#ifndef VB_GROUND_H
#define VB_GROUND_H

#include <SDL2/SDL.h>
#include "view.h"

typedef struct
{
  SDL_Texture *tex;
  struct
  {
    float z;
    float distance;
    float height;
    float gradient;
  }
  raster[900];
}
VB_Ground;

SDL_bool vb_ground_isok(VB_Ground *ground);
SDL_bool vb_ground_init(VB_View *view, VB_Ground *ground);
void vb_ground_free(VB_Ground *ground);
void vb_ground_update(VB_Ground *ground);
void vb_ground_render(VB_View *view, VB_Ground *ground);

#endif
