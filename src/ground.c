#include <SDL2_image/SDL_image.h>

#include "ground.h"

SDL_bool
vb_ground_isok(VB_Ground *ground)
{
  return ground->tex != NULL;
}

SDL_bool
vb_ground_init(VB_View *view, VB_Ground *ground)
{
  ground->tex = IMG_LoadTexture(view->renderer, "assets/checkerboard.jpg");
  return vb_ground_isok(ground);
}

void
vb_ground_free(VB_Ground *ground)
{
  if (ground->tex)
  {
    // TODO: free tex
    ground->tex = NULL;
  }
}

void
vb_ground_render(VB_View *view, VB_Ground *ground)
{
  SDL_Rect src;
  src.x = 0;
  src.y = 0;
  src.w = 256;
  src.h = 1;

  SDL_Rect dst;
  dst.x = 0;
  dst.y = 0;
  dst.w = 256;
  dst.h = 1;

  int h = -80000;
  for (int y = 450; y > -450; y -= 1)
  {
    int z = (y == 0) ? -1 : (h - y)/y;
    if (z > 0 && z < 10000) {
      src.y = z % 256;
      dst.y = 450 - y;
      dst.w = 100000 / z;
      dst.x = 0;
      do
      {
        SDL_RenderCopy(view->renderer, ground->tex, &src, &dst);
        dst.x += dst.w;
      }
      while (dst.x < 1600);
    }
  }
}
