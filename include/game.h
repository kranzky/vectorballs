#ifndef VB_GAME_H
#define VB_GAME_H

#include "ground.h"

//==============================================================================

typedef struct
{
  VB_View *view;
  VB_Ground *ground;
}
VB_Game;

//------------------------------------------------------------------------------

VB_Game * vb_game_init();
void vb_game_free(VB_Game *game);
void vb_game_run(VB_Game *game);

//==============================================================================

#endif
