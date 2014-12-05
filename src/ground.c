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
  for (int y = 0; y < 900; ++y)
  {
    ground->raster[y].z = 0.0;
    ground->raster[y].distance = 0.0;
    ground->raster[y].height = 0.0;
    ground->raster[y].gradient = 0.0;
  }
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
vb_ground_update(VB_Ground *ground)
{
  float h = -80000;
  for (int z = 10000; z > 0; --z)
  {
    int y = (int)(h/(1.0+(float)z));
    if (y<=-450 || y> 450)
    {
      continue;
    }
    ground->raster[450-y].z = (float)z;
    ground->raster[450-y].height = (float)h;
  }
}

void
vb_ground_render(VB_View *view, VB_Ground *ground)
{
  SDL_Rect src = {0, 0, 256, 1};
  SDL_Rect dst = {0, 0, 256, 1};

  for (int y = 0; y < 900; ++y)
  {
    if (ground->raster[y].z <= 0.0 || ground->raster[y].z >= 10000.0)
    {
      continue;
    }
    src.y = (int)ground->raster[y].z % 256;
    dst.y = y;
    dst.w = 100000 / ground->raster[y].z;
    dst.x = 0;
    do
    {
      SDL_RenderCopy(view->renderer, ground->tex, &src, &dst);
      dst.x += dst.w;
    }
    while (dst.x < 1600);
  }
}
