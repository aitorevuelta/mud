#ifndef UPDATE_H
#define UPDATE_H


void update(SDL sdl, GAMESTATE *gameState, ASSETS *loadedAssets, GAMEINFO *gameInfo, BUTTON buttons[], CONTROLS controls, CONFIG* config);
void adjustFrameRate(Uint32 frameStart, int targetFPS);

#endif //UPDATE_H
