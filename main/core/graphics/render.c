#include <global.h>
#include <assets_utils.h>
#include <loadscreen_render.h>
#include <menu_render.h>
#include <lobby_render.h>
#include <game_render.h>
#include <settings_render.h>
#include <credits_render.h>
<<<<<<< HEAD
#include <howtoplay_render.h>

#include <render.h>



void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMESTATE *gameState, GAMEINFO* gameInfo,BUTTON **buttons, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    static int rend_menu = 0, rend_sett = 0, rend_cre = 0, rend_h2p = 0, rend_game = 0, rend_lbby = 0;
    
    switch(*gameState) {
        case LOADSCREEN:
            break;
        case MAIN_MENU:
            rend_menu = renderMenu(rend_menu, renderer,buttons,loadedImages);
            rend_lbby = 0;
            rend_cre = 0;
            rend_sett = 0;
            rend_h2p = 0;
=======
#include <render.h>

void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMESTATE gameState, GAMEINFO gameInfo, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);

    switch(gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages);
            break;
        case MAIN_MENU:
        
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
            break;
        case LOBBY:
            rend_lbby= renderLobby(rend_lbby, renderer, loadedImages);
            rend_menu=0;
            break;
        case GAME:
<<<<<<< HEAD
            rend_game=renderGame(rend_game, renderer, loadedImages, gameInfo, config);
            rend_menu=0;
=======
            renderGame(renderer, loadedImages, loadedFonts, gameInfo, config);
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
            break;
        case SETTINGS:
           rend_sett= renderSettings(rend_sett, renderer,buttons, loadedImages);
            rend_menu=0;
            break;
        case CREDITS: 
            rend_cre = renderCredits(rend_cre, renderer,buttons, loadedImages);
            rend_menu=0;
            break;
        case HOWTOPLAY:
            rend_h2p = renderHowtoplay(rend_h2p, renderer,buttons, loadedImages);
            rend_menu=0;
            break;
    }

    SDL_RenderPresent(renderer);
}
