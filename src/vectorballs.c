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

  vb_game_run(&game);
  vb_game_free(&game);

  return 0;
}
