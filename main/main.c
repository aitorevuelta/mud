#include <global.h>

//UTILS
#include <sdl_utils.h>
#include <settings_utils.h>
#include <assets_utils.h>
#include <gamestate_manager.h>

#include <menu.h>
#include <controls.h>
#include <render.h>
#include <loadscreen_render.h>
#include <update.h>


GAMESTATE loadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages);

int main(int argc, char *argv[])
{
    SDL sdl;
    CONTROLS controls;
    CONFIG config = readConfig();
    GAMESTATE gameState = LOADSCREEN;
    LOADEDIMAGES* loadedImages = NULL;  
    LOADEDFONTS* loadedFonts = NULL;
    GAMEINFO* gameInfo = NULL;

    bool is_running = init_sdl(&sdl, config);
    LoadImages(&loadedImages, gameState, sdl.renderer);
    LoadFonts(&loadedFonts, gameState, sdl.renderer);

    gameState = loadscreen(sdl.renderer, loadedImages);

    do {
        is_running = process_events(&controls, sdl.window, &config);
        
        //gameState = update(gameState, gameInfo);
        //render(sdl.renderer, loadedImages, loadedFonts, &gameState, gameInfo, config);
        checkGameStateChange(&loadedImages, &loadedFonts, &gameState, sdl.renderer);
    } while(is_running);

    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}

GAMESTATE loadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages)
{
    Uint32 frameStart = SDL_GetTicks();
    adjustFrameRate(frameStart, 144);

    SDL_RenderClear(renderer);

    renderLoadscreen(renderer, loadedImages);

    SDL_RenderPresent(renderer);

    return MAIN_MENU;
}