#include <global.h>

//UTILS
#include <sdl_utils.h>
#include <settings_utils.h>
#include <assets_utils.h>
#include <gamestate_utils.h>

#include <menu.h>
#include <controls.h>
#include <render.h>
#include <loadscreen_render.h>
#include <update.h>

int main(int argc, char *argv[])
{
    SDL sdl;
    CONTROLS controls;
    CONFIG config = readConfig();
    GAMESTATE gameState = LOADSCREEN;
    ASSETS loadedAssets = {NULL, NULL, NULL};
    BUTTON* buttons = NULL;
    GAMEINFO gameInfo;

    gameInfo.numPlayers = 4;
    gameInfo.mapInfo.numMaps = 1;
    gameInfo.mapInfo.totalMaps = 3;

    bool is_running = init_sdl(&sdl, config);
    LoadAssets(&loadedAssets, gameState, sdl.renderer);

    do {
        is_running = process_events(&controls, sdl.window, &config);
        gameState = update(gameState, &gameInfo, buttons, &controls, config.max_FPS);
        checkGameStateChange(&loadedAssets, &gameState, sdl.renderer);
        render(sdl.renderer, &loadedAssets, gameState, gameInfo, &buttons,config);
    } while(is_running);


    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}