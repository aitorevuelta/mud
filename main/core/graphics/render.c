#include <global.h>
#include <assets_utils.h>
#include <loadscreen_render.h>
#include <menu_render.h>
#include <lobby_render.h>
#include <game_render.h>
#include <settings_render.h>
#include <credits_render.h>
#include <howtoplay_render.h>

#include <render.h>


/*
void render(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON **buttons, BUTTON_JUEGO **buttons_juego,CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    static int rend_general = 0, rend_menu = 0;
    
    switch(gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages);
            break;
        case MAIN_MENU:
            rend_menu = renderMenu(rend_menu, renderer, buttons, loadedImages);
            rend_general = 0;
            break;
        case LOBBY:
            rend_general = renderLobby(rend_general, renderer,buttons,buttons_juego, loadedImages, &gameInfo);
            rend_menu = 0;
            break;
        case GAME:
            rend_general = renderGame(renderer, loadedImages, loadedFonts, gameInfo, config, rend_general);
            rend_menu = 0;
            break;
        case SETTINGS:
           rend_general = renderSettings(rend_general, renderer,buttons, loadedImages);
            rend_menu = 0;
            break;
        case CREDITS: 
            rend_general = renderCredits(rend_general, renderer,buttons, loadedImages);
            rend_menu = 0;
            break;
        case HOWTOPLAY:
            rend_general = renderHowtoplay(rend_general, renderer,buttons, loadedImages);
            rend_menu = 0;
            break;
    }

    SDL_RenderPresent(renderer);
}
*/

void render(SDL_Renderer* renderer, ASSETS* assets, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON** buttons, BUTTON_JUEGO** buttons_juego, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);

    static int rend_general = 0, rend_menu = 0;

    switch (gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, assets->images);  // Usar imágenes desde `assets`
            break;
        case MAIN_MENU:
            rend_menu = renderMenu(rend_menu, renderer, buttons, assets->images);
            rend_general = 0;
            break;
        case LOBBY:
            rend_general = renderLobby(rend_general, renderer, buttons, buttons_juego, assets->images, &gameInfo);
            rend_menu = 0;
            break;
        case GAME:
            rend_general = renderGame(renderer, assets->images, assets->fonts, gameInfo, config, rend_general);
            rend_menu = 0;
            break;
        case SETTINGS:
            rend_general = renderSettings(rend_general, renderer, buttons, assets->images);
            rend_menu = 0;
            break;
        case CREDITS:
            rend_general = renderCredits(rend_general, renderer, buttons, assets->images);
            rend_menu = 0;
            break;
        case HOWTOPLAY:
            rend_general = renderHowtoplay(rend_general, renderer, buttons, assets->images);
            rend_menu = 0;
            break;
    }

    SDL_RenderPresent(renderer);
}