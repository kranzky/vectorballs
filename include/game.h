#ifndef  VB_GAME_H
#define  VB_GAME_H

#include <SDL2/SDL.h>
#include "view.h"
#include "ground.h"

typedef struct
{
  VB_View view;
  VB_Ground ground;
}
VB_Game;

SDL_bool vb_game_isok(VB_Game *game);
SDL_bool vb_game_init(VB_Game *game);
void vb_game_free(VB_Game *game);
void vb_game_run(VB_Game *game);

#endif
