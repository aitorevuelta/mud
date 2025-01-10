#ifndef UPDATE_H
#define UPDATE_H

void adjustFrameRate(Uint32 frameStart, int targetFPS);
GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo,BUTTON *buttons,CONTROLS *controls);

#endif //UPDATE_H
