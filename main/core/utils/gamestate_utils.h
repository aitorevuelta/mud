#ifndef GAMESTATE_UTILS_H
#define GAMESTATE_UTILS_H

void gameStateManager(SDL_Renderer* renderer, BUTTON* buttons, ASSETS *loadedAssets, GAMESTATE* gameState, GAMEINFO* gameInfo, CONFIG* config);
void loadGameStateVariables(BUTTON** buttons, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config);

#endif //GAMESTATE_UTILS_H