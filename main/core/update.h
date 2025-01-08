#ifndef UPDATE_H
#define UPDATE_H

#include <game_logic.h>

void adjustFrameRate(Uint32 frameStart, int targetFPS);
GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo);

#endif //UPDATE_H
