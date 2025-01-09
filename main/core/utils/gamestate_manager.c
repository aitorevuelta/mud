#include <global.h>

#include <assets_utils.h>

#include <gamestate_manager.h>

void checkGameStateChange(LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, GAMESTATE* gameState, SDL_Renderer* renderer) {
    static GAMESTATE lastGameState = -1; // Usando -1 como valor inicial

    if (*gameState != lastGameState && lastGameState != -1) {
        lastGameState = *gameState;
        
        LoadImages(loadedImages, *gameState, renderer);
        LoadFonts(loadedFonts, *gameState, renderer);
    }
}
