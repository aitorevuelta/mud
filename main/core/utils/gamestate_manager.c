#include <global.h>

#include <assets_utils.h>

#include <gamestate_manager.h>

void checkGameStateChange(LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer) {
    static GAMESTATE lastGameState = false; 

    if (gameState != lastGameState && lastGameState != false) {
        lastGameState = gameState;
        
        LoadImages(loadedImages, gameState, renderer);
        LoadFonts(loadedFonts, gameState, renderer);
    }
}