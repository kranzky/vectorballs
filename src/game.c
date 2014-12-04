#include "game.h"

bool
vb_game_isok(VB_Game *game)
{
  return vb_view_isok(&game->view);
}

bool
vb_game_init(VB_Game *game)
{
  // TODO: check view
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return false; 
  }
  return vb_view_init(&game->view);
}

void
vb_game_free(VB_Game *game)
{
  vb_view_free(&game->view);
  SDL_Quit();
}

void
vb_game_run(VB_Game *game, SDL_Texture *tex)
{
  SDL_ShowWindow(game->view.window);
  SDL_Rect dst;
  dst.x = 100;
  dst.y = 100;
  dst.w = 200;
  dst.h = 200;

  SDL_Event e;
  bool quit = false;   
  while (!quit)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        quit = true;
      }
      if (e.type == SDL_KEYDOWN)
      {
        quit = true;
      }
      if (e.type == SDL_MOUSEBUTTONDOWN)
      {
        quit = true;
      }
    }
    SDL_SetRenderDrawColor(game->view.renderer, 255, 0, 0, 255);
    SDL_RenderClear(game->view.renderer);
    SDL_RenderCopy(game->view.renderer, tex, NULL, &dst);
    SDL_RenderPresent(game->view.renderer);
  }
}
