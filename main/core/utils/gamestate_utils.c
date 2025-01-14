#include <global.h>

#include <assets_utils.h>

#include <gamestate_utils.h>


void checkGameStateChange(ASSETS *loadedAssets, GAMESTATE* gameState, SDL_Renderer* renderer) {
    static GAMESTATE lastGameState = 0; 
    if (*gameState != lastGameState) {
        LoadAssets(loadedAssets, *gameState, renderer);
        lastGameState = *gameState;
    }
}