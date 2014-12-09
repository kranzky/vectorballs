//==============================================================================

#include "game.h"

//------------------------------------------------------------------------------

VB_Game *
vb_game_init()
{
  VB_Game *game = malloc(sizeof(VB_Game));
  if (game == NULL)
  {
    return NULL;
  }

  game->view = vb_view_init();
  if (game->view == NULL)
  {
    vb_game_free(game);
    return NULL;
  }

  game->ground = vb_ground_init(game->view);
  if (game->ground == NULL)
  {
    vb_game_free(game);
    return NULL;
  }

  return game;
}

//------------------------------------------------------------------------------

void
vb_game_free(VB_Game *game)
{
  if (game->view != NULL)
  {
    vb_view_free(game->view);
    game->view = NULL;
  }

  if (game->ground != NULL)
  {
    vb_ground_free(game->ground);
    game->ground = NULL;
  }

  free(game);
}

//------------------------------------------------------------------------------

void
vb_game_run(VB_Game *game)
{
  SDL_ShowWindow(game->view->window);

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

    SDL_SetRenderDrawColor(game->view->renderer, 255, 0, 0, 255);
    SDL_RenderClear(game->view->renderer);

    vb_ground_update(game->ground);    
    vb_ground_render(game->view, game->ground);    

    SDL_RenderPresent(game->view->renderer);
  }
}

//==============================================================================
