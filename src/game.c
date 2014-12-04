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
  SDL_ShowCursor(SDL_FALSE);
  SDL_DisableScreenSaver();
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
          SDL_RenderCopy(game->view.renderer, tex, &src, &dst);
          dst.x += dst.w;
        }
        while (dst.x < 1600);
      }
    }

    SDL_RenderPresent(game->view.renderer);
  }
}
