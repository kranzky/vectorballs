#ifndef  VB_GAME_H
#define  VB_GAME_H

#include <stdbool.h>
#include <SDL2/SDL.h>
#include "view.h"

typedef struct
{
  VB_View view;
}
VB_Game;

bool vb_game_isok(VB_Game *game);
bool vb_game_init(VB_Game *game);
void vb_game_free(VB_Game *game);
void vb_game_run(VB_Game *game, SDL_Texture *tex);

#endif
