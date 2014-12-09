#ifndef VB_GROUND_H
#define VB_GROUND_H

#include "view.h"

//==============================================================================

#define DEPTH 1000

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
  raster[HEIGHT];

  struct
  {
    float z;
    float height;
  }
  points[DEPTH];
}
VB_Ground;

//------------------------------------------------------------------------------

VB_Ground * vb_ground_init(VB_View *view);
void vb_ground_free(VB_Ground *ground);
void vb_ground_update(VB_Ground *ground);
void vb_ground_render(VB_View *view, VB_Ground *ground);

//==============================================================================

#endif
