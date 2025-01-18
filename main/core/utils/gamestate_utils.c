#include <global.h>

#include <assets_utils.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = 0; 

void checkGameStateChange(SDL_Renderer* renderer, ASSETS *loadedAssets, GAMESTATE* gameState) {
    if (*gameState != lastGameState) {
        LoadAssets(renderer, loadedAssets, *gameState);
        lastGameState = *gameState;
    }
}
