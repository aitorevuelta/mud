#ifndef UPDATE_H
#define UPDATE_H

void adjustFrameRate(Uint32 frameStart, int targetFPS);
GAMESTATE update(GAMESTATE gameState, GAMEINFO *gameInfo, BUTTON *buttons,BUTTON_JUEGO *buttons_juego, CONTROLS *controls, int fps, SDL_Renderer *renderer, IMAGES *loadedImages);

#endif //UPDATE_H
