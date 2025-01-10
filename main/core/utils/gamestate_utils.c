#include <global.h>

#include <assets_utils.h>

#include <gamestate_utils.h>

static GAMESTATE lastGameState = 0; 

void checkGameStateChange(LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, GAMESTATE* gameState, SDL_Renderer* renderer) {
    if (*gameState != lastGameState) {
        LoadAssets(loadedImages, loadedFonts, *gameState, renderer);
        lastGameState = *gameState;
    }
}
