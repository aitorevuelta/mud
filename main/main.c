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
    if (!is_running) {
        cleanUp_sdl(&sdl);
        return -1;
    }

    if (!LoadAssets(&loadedImages, &loadedFonts, gameState, sdl.renderer)) {
        fprintf(stderr, "Error al cargar recursos.\n");
        cleanUp_sdl(&sdl);
        return -1;
    }

    do {
        is_running = process_events(&controls, sdl.window, &config);
        gameState = update(gameState, gameInfo);
        render(sdl.renderer, loadedImages, loadedFonts, &gameState, gameInfo, config);
        checkGameStateChange(&loadedImages, &loadedFonts, &gameState, sdl.renderer);
    } while(is_running);

    saveConfig(config);
    cleanUp_sdl(&sdl);

    return 0;
}