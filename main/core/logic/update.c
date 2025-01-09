#include <global.h>

#include <controls.h>
#include <texturemanager.h>

#include <update.h>



GAMESTATE update(GAMESTATE gameState, GAMEINFO* gameInfo) {
    Uint32 frameStart = SDL_GetTicks();

    switch (gameState) {
        case MAIN_MENU:

            break;
        case LOBBY:
            break;
        case GAME:
            

            break;
        case SETTINGS:
            break;
        default:
            break;
    }

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
