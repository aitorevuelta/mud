#include <global.h>

#include <assets_utils.h>

#include <gamestate_manager.h>
static GAMESTATE lastGameState = false; 
void checkGameStateChange(LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, GAMESTATE gameState, SDL_Renderer* renderer) {

    if (gameState != lastGameState) {
        lastGameState = gameState;
        
        LoadImages(loadedImages, gameState, renderer);
        LoadFonts(loadedFonts, gameState, renderer);
    }
    
}