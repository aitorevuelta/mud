#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <controls.h>
#include <utils.h>
#include <texturemanager.h>
#include <render.h>
#include <update.h>
#include <network.h>
#include <settings.h>

int main(int argc, char *argv[])
{
    SDL sdl;
    CONTROLS controls;
    CONFIG config = readConfig();
    GAMESTATE gameState = LOADSCREEN;
    LOADEDIMAGES* loadedImages = NULL;
    LOADEDFONTS* loadedFonts = NULL;

    bool is_running = init_sdl(&sdl, config);
    LoadImages(&loadedImages, gameState, sdl.renderer);
    do {

        is_running = process_events(&controls, sdl.window, &config);
        render(sdl.renderer, loadedImages, &gameState, config);
        gameState = update(gameState);
    }
    while(is_running);

    saveConfig(config);

    return 0;
}
