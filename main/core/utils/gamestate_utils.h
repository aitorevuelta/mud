#ifndef GAMESTATE_UTILS_H
#define GAMESTATE_UTILS_H

void gameStateManager(SDL_Renderer* renderer, BUTTON **buttons, ASSETS *loadedAssets, GAMESTATE gameState, GAMEINFO* gameInfo, CONFIG* config);
void loadGameStateVariables(SDL_Renderer *renderer, ASSETS loadedAssets, GAMESTATE gameState, GAMEINFO *gameInfo, CONFIG* config);
void handleMusicChange(GAMESTATE newState, ASSETS *loadedAssets);
#endif //GAMESTATE_UTILS_H