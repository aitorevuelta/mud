#include <global.h>

#include <assets_utils.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = 0; 

void checkGameStateChange(ASSETS *loadedAssets, GAMESTATE* gameState, SDL_Renderer* renderer) {
    if (*gameState != lastGameState) {
        LoadAssets(loadedAssets, *gameState, renderer);
        lastGameState = *gameState;
    }
}
