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

GAMESTATE update(GAMESTATE gameState) {
    switch(gameState) {
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
    return gameState;
}
