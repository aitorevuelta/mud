#include <global.h>

#include <assets_utils.h>

#include <loadscreen_render.h>
#include <menu_render.h>
#include <lobby_render.h>
#include <game_render.h>
#include <settings_render.h>
#include <credits_render.h>

#include <render.h>



void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMESTATE *gameState, GAMEINFO* gameInfo, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    
    switch(*gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages, loadedFonts, gameState);
            break;
        case MAIN_MENU:
            SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);
            break;
        case LOBBY:
            renderLobby(renderer, loadedImages);
            break;
        case GAME:
            renderGame(renderer, loadedImages, loadedFonts);
            break;
        case SETTINGS:
            renderSettings(renderer, loadedImages);
            break;
        case CREDITS:
            renderCredits(renderer, loadedImages);
            break;
    }
    
    SDL_RenderPresent(renderer);
}

