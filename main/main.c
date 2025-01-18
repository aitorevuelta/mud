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

int main(int argc, char *argv[])
{
    GAMECONTEXT gameContext;
    
    gameContext.config = readConfig();

    srand((unsigned int)time(NULL));

    gameContext.gameInfo.numPlayers = 2; // Establecer un valor por defecto
    gameContext.gameInfo.currentMapID = 1; // Empezar en el primer mapa
    gameContext.gameInfo.numMaps = 3; // Establecer el total de mapas disponibles

    gameContext.config.current_res = 1;
    gameContext.config.total_res = 7;
    gameContext.config.selectedVolume = 0;

    gameContext.gameInfo.camera.zoom = 1.0f;
    gameContext.gameInfo.camera.pos[0] = config.window_size.width/2;
    gameContext.gameInfo.camera.pos[1] = config.window_size.height/2;

    bool is_running = init_sdl(&gameContext);
    LoadAssets(&gameContext);
    
    do {
        is_running = process_events(&gameContext);
        gameContext.gameState = update(&gameContext);
        render(&gameContext);
    }while(is_running);


    saveConfig(gameContext.config);
    cleanUp_sdl(gameContext.sdl);

    return 0;
}