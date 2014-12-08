#include "game.h"

int
main(int argc, const char *argv[])
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return 1;
  }

  VB_Game *game = vb_game_init();
  if (game == NULL)
  {
    fprintf(stderr, "vb_game_init Error: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  vb_game_run(game);
  vb_game_free(game);

  SDL_Quit();

  return 0;
}
