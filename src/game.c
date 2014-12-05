#include "game.h"

SDL_bool
vb_game_isok(VB_Game *game)
{
  return vb_view_isok(&game->view) &&
         vb_ground_isok(&game->ground);
}

SDL_bool
vb_game_init(VB_Game *game)
{
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
  {
    return SDL_FALSE; 
  }

  return vb_view_init(&game->view) &&
         vb_ground_init(&game->view, &game->ground);
}

void
vb_game_free(VB_Game *game)
{
  vb_view_free(&game->view);
  vb_ground_free(&game->ground);
  SDL_Quit();
}

void
vb_game_run(VB_Game *game)
{
  SDL_ShowWindow(game->view.window);

  SDL_Event e;
  SDL_bool quit = SDL_FALSE;   
  while (!quit)
  {
    while (SDL_PollEvent(&e))
    {
      if (e.type == SDL_QUIT)
      {
        quit = SDL_TRUE;
      }
      if (e.type == SDL_KEYDOWN)
      {
        quit = SDL_TRUE;
      }
      if (e.type == SDL_MOUSEBUTTONDOWN)
      {
        quit = SDL_TRUE;
      }
    }

    SDL_SetRenderDrawColor(game->view.renderer, 255, 0, 0, 255);
    SDL_RenderClear(game->view.renderer);

    vb_ground_update(&game->ground);    
    vb_ground_render(&game->view, &game->ground);    

    SDL_RenderPresent(game->view.renderer);
  }
}
