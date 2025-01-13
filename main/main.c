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
    IMAGES* loadedImages = NULL;  
    FONTS* loadedFonts = NULL;
    BUTTON* buttons = NULL;
    BUTTON_JUEGO* buttons_juego = NULL;
    GAMEINFO gameInfo;
    gameInfo.numPlayers = 2;

    bool is_running = init_sdl(&sdl, config);
    LoadAssets(&loadedImages, &loadedFonts, gameState, sdl.renderer);

    do {
        is_running = process_events(&controls, sdl.window, &config);
        gameState = update(gameState, &gameInfo, buttons,buttons_juego, &controls, config.max_FPS,sdl.renderer, loadedImages);
        checkGameStateChange(&loadedImages, &loadedFonts, &gameState, sdl.renderer);
        render(sdl.renderer, loadedImages, loadedFonts, gameState, gameInfo, &buttons, &buttons_juego,config);
    } while(is_running);


    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}