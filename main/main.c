#include <global.h>

//UTILS
#include <sdl_utils.h>
#include <settings_utils.h>
#include <assets_utils.h>
#include <gamestate_manager.h>

#include <loadscreen_render.h>
#include <controls.h>
#include <render.h>
#include <update.h>


int main(int argc, char *argv[])
{
    SDL sdl;
    CONTROLS controls;
    CONFIG config = readConfig();
    GAMESTATE gameState = LOADSCREEN;
    LOADEDIMAGES* loadedImages = NULL;
    LOADEDFONTS* loadedFonts = NULL;
    GAMEINFO* gameInfo = NULL;
    BUTTON* buttons=NULL;

    bool is_running = init_sdl(&sdl, config);
    LoadImages(&loadedImages, gameState, sdl.renderer);
    LoadFonts(&loadedFonts, gameState, sdl.renderer);
    renderLoadscreen(sdl.renderer, loadedImages, loadedFonts, &gameState);
    do {
        checkGameStateChange(&loadedImages, &loadedFonts, gameState, sdl.renderer);
        is_running = process_events(&controls, sdl.window, &config);
        render(sdl.renderer, loadedImages, loadedFonts, &gameState, gameInfo,&buttons, config);
        gameState = update(gameState, gameInfo,buttons,&controls);
        if(gameState==EXIT_TOTAL){
            is_running=false;
        }
    } while(is_running);

    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}
