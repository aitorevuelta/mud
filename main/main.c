#include <global.h>

//UTILS
#include <sdl_utils.h>
#include <settings_utils.h>
#include <assets_utils.h>
#include <gamestate_utils.h>

#include <menu.h>
#include <controls.h>
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
    GAMEINFO gameInfo = {0};

    gameInfo.numPlayers = 2; // Establecer un valor por defecto
    gameInfo.mapInfo.numMaps = 1; // Empezar en el primer mapa
    gameInfo.mapInfo.totalMaps = 3; // Establecer el total de mapas disponibles
    
    bool is_running = init_sdl(&sdl, config);
    LoadAssets(sdl.renderer, &loadedAssets, gameState);

    
    do {
        is_running = process_events(sdl.window, &controls, &config);
        gameState = update(&sdl, gameState, &gameInfo, buttons, &controls, &config);
        checkGameStateChange(sdl.renderer, &loadedAssets, &gameState);
        render(sdl.renderer, &loadedAssets, gameState, gameInfo, &buttons, config);
    } while(is_running);


    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}