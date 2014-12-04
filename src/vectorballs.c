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

  SDL_Texture *tex = IMG_LoadTexture(game.view.renderer, "assets/checkerboard.jpg");
  if (tex == NULL)
  {
    fprintf(stderr, "SDL_CreateTextureFromSurface Error: %s\n", SDL_GetError());
    vb_game_free(&game);
    return 1;
  }

  vb_game_run(&game, tex);
  vb_game_free(&game);

  return 0;
}
