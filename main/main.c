#include <global.h>


// utils
#include <sdl_utils.h>
#include <settings_utils.h>
#include <gamestate_utils.h>
#include <assets_utils.h>
#include <buttons_utils.h>

#include <controls.h>
#include <menu.h>
#include <render.h>
#include <update.h>
#include <game.h>


int main(int argc, char *argv[])
{  
    SDL sdl;
    CONFIG config = readConfig();
    CONTROLS controls;
    ASSETS loadedAssets = {NULL, NULL, NULL};
    GAMESTATE gameState = LOADSCREEN;
    GAMEINFO gameInfo = loadGameInfo();
    BUTTON* buttons = NULL;

    srand((unsigned int)time(NULL));
    
    bool is_running = init_sdl(&sdl, config);
    if(!is_running) return LOADSCREEN;
    LoadAssets(sdl.renderer, &loadedAssets, gameState);

    do {
        is_running = process_events(sdl.window, &controls, &config);
        update(sdl.renderer, &gameState, &loadedAssets, &gameInfo, &buttons, controls, &config);
        render(sdl.renderer, loadedAssets, gameState, gameInfo, buttons, config);
    }while(is_running);

    FreeAssets(&loadedAssets);
    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}