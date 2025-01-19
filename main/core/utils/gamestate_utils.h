#ifndef GAMESTATE_UTILS_H
#define GAMESTATE_UTILS_H

void checkGameStateChange(SDL_Renderer* renderer, ASSETS *loadedAssets, GAMESTATE* gameState);
void loadGameStateVariables(GAMESTATE gameState, GAMEINFO *gameInfo, ASSETS *loadedAssets);

#endif //GAMESTATE_UTILS_H