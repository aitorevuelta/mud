#include <global.h>
#include <texturemanager.h>
#include <utils.h>

#include <loadscreen_render.h>
#include <menu_render.h>
#include <lobby_render.h>
#include <game_render.h>
#include <settings_render.h>
#include <credits_render.h>

#include <render.h>



void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, GAMEINFO gameInfo, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    
    switch(*gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages, gameState);
            break;
        case MAIN_MENU:
            //renderMenu(renderer, loadedImages, gameState, config);
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

