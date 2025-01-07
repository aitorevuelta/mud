#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <controls.h>
#include <update.h>
#include <utils.h>


GAMESTATE update(GAMESTATE gameState) {
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
