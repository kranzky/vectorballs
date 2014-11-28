#include <SDL2_image/SDL_image.h>

#include "game.h"

int main(int argc, const char *argv[])
{
  VB_Game game;

  if (!vb_game_init(&game))
  {
    fprintf(stderr, "vb_game_init Error: %s\n", SDL_GetError());
    vb_game_free(&game);
    return 1;
  }

  SDL_Texture *tex = IMG_LoadTexture(game.view.renderer, "assets/avatar.jpg");
  if (tex == NULL)
  {
    fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    vb_game_free(&game);
    return 1;
  }

  // TODO: draw and move a sprite
  // TODO: add checkerboard plane
  // TODO: colourise sprite
  // TODO: scale sprite
  // TODO: move sprite in a circle
  // TODO: add a shadow on the plane
  // TODO: fade with distance
  // TODO: input controls
  // TODO: move the camera
  // TODO: add FPS display
  // TODO: add a second sprite with depth culling
  // TODO: test how many at 60fps
  // TODO: basic collisions between sprites
  // TODO: aggregate objects that move together
  // TODO: object rotation
  // TODO: build on windows and linux

  vb_game_run(&game, tex);
  vb_game_free(&game);

  return 0;
}
