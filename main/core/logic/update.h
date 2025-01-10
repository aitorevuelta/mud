#ifndef UPDATE_H
#define UPDATE_H

void adjustFrameRate(Uint32 frameStart, int targetFPS);
<<<<<<< HEAD
GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo,BUTTON *buttons,CONTROLS *controls);
=======
GAMESTATE update(GAMESTATE gameState, GAMEINFO *gameInfo, int fps);
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a

#endif //UPDATE_H
