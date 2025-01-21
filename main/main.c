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


int main(int argc, char *argv[])
{  
    SDL sdl;
    CONFIG config = readConfig();
    CONTROLS controls;
    ASSETS loadedAssets = {NULL, NULL, NULL};
    GAMESTATE gameState = MAIN_MENU;
    GAMEINFO gameInfo = { .numPlayers = 2, .currentMapID = 1, .numMaps = NUM_MAPS};
    BUTTON *buttons = NULL;
    
    config.current_res = 1;
    config.total_res = 7;

    bool is_running = init_sdl(&sdl, config);
    if(!is_running) return 1;
    LoadAssets(sdl.renderer, &loadedAssets, gameState);
    if(!loadedAssets) return 1;
    
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