#ifndef UPDATE_H
#define UPDATE_H

void adjustFrameRate(Uint32 frameStart, int targetFPS);
GAMESTATE update(SDL *sdl, GAMESTATE gameState, GAMEINFO *gameInfo, BUTTON *buttons, CONTROLS *controls, CONFIG* config, SDL_Window *window);

#endif //UPDATE_H
