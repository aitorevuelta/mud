#include <global.h>

#include <time.h>

//UTILS
#include <sdl_utils.h>
#include <settings_utils.h>
#include <gamestate_utils.h>
#include <assets_utils.h>
#include <buttons_utils.h>

#include <controls.h>
#include <menu.h>
#include <render.h>
#include <update.h>
#include <gamecontext.h>



int main(int argc, char *argv[])
{  
    SDL sdl;
    CONFIG config = readConfig();
    CONTROLS controls;
    ASSETS loadedAssets = {NULL, NULL, NULL};
    GAMESTATE gameState = MAIN_MENU;
    GAMEINFO gameInfo = { .numPlayers = 4, .currentMapID = 1, .numMaps = 3 };
    BUTTON *buttons;
 
    srand((unsigned int)time(NULL));

    config.current_res = 1;
    config.total_res = 7;
    config.selectedVolume = 0;

    bool is_running = init_sdl(&sdl, config);
    LoadAssets(sdl.renderer, &loadedAssets, gameState);
    
    do {
        is_running = process_events(sdl.window, &controls, &config);
        update(sdl.renderer, &gameState, &loadedAssets, &gameInfo, &buttons, controls, &config);
        render(sdl.renderer, loadedAssets, gameState, gameInfo, buttons, config);
    }while(is_running);


    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}