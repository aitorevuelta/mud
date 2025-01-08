#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <utils.h>

#include <renderLoadscreen.h>
#include <renderMenu.h>
#include <renderLobby.h>
#include <renderGame.h>
#include <renderSettings.h>
#include <renderCredits.h>

#include <render.h>



void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    
    switch(*gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages, gameState);
            break;
        case MAIN_MENU:
            renderCredits(renderer, loadedImages, gameState);
            break;
        case LOBBY:
            renderLobby(renderer, loadedImages, gameState);
            break;
        case GAME:
            renderGame(renderer, loadedImages, gameState, config);
            break;
        case SETTINGS:
            renderSettings(renderer, loadedImages, gameState);
            break;
        case CREDITS:
            renderCredits(renderer, loadedImages, gameState);
            break;
    }
    
    SDL_RenderPresent(renderer);
}

