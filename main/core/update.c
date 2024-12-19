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

    int targetFPS = 60;
    adjustFrameRate(frameStart, 144);
    return gameState;
}
