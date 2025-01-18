#include <global.h>

#include <time.h>

//UTILS
#include <sdl_utils.h>
#include <settings_utils.h>
#include <gamestate_utils.h>
#include <assets_utils.h>
#include <buttons_utils.h>

#include <gamecontext.h>

#include <controls.h>

#include <menu.h>
#include <render.h>
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

    srand((unsigned int)time(NULL));

    gameInfo.numPlayers = 2; // Establecer un valor por defecto
    gameInfo.currentMapID = 1; // Empezar en el primer mapa
    gameInfo.numMaps = 3; // Establecer el total de mapas disponibles

    config.current_res = 1;
    config.total_res = 7;
    config.selectedVolume = 0;

    gameInfo.camera.zoom = 1.0f;
    gameInfo.camera.pos[0] = config.window_size.width/2;
    gameInfo.camera.pos[1] = config.window_size.height/2;

    bool is_running = init_sdl(&sdl, config);
    LoadAssets(sdl.renderer, &loadedAssets, gameState);
    
    do {
        is_running = process_events(sdl.window, &controls, &config);
        gameState = update(&sdl, gameState, &loadedAssets, &gameInfo, buttons, &controls, &config);
        render(sdl.renderer, &loadedAssets, gameState, gameInfo, &buttons, config);
    }while(is_running);


    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}