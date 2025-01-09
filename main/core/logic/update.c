#include <global.h>

#include <controls.h>
#include <assets_utils.h>
#include <gamestate_manager.h>

#include <update.h>



GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo, LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, SDL_Renderer* renderer) {

    Uint32 frameStart = SDL_GetTicks();

    switch (gameState) {
        case LOADSCREEN:

            break;
        case MAIN_MENU:

            break;
        case LOBBY:
            break;
        case GAME:

            break;
        case SETTINGS:
            break;
        case CREDITS:
        
            break;
    }

    checkGameStateChange(loadedImages, loadedFonts,gameState, renderer);
    adjustFrameRate(frameStart, 144);
    return gameState;
}

void adjustFrameRate(Uint32 frameStart, int targetFPS) {
    Uint32 frameDelay = 1000 / targetFPS;
    Uint32 frameTime = SDL_GetTicks() - frameStart;

    if (frameDelay > frameTime) {
        SDL_Delay(frameDelay - frameTime); 
    }
}
