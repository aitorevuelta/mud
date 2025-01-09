#ifndef UPDATE_H
#define UPDATE_H

void adjustFrameRate(Uint32 frameStart, int targetFPS);
GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo, LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, SDL_Renderer* renderer);

#endif //UPDATE_H
