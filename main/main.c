#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <controls.h>
#include <utils.h>
#include <render.h>
#include <texturemanager.h>
#include <network.h>

int main(int argc, char *argv[])
{
    SDL sdl;
    CONTROLS controls;
    CONFIG config = readConfig();
    GAMESTATE gameState = LOADSCREEN;
    LOADEDTEXTURES loadedTextures[MAX_TEXTURES];
    
    bool is_running = init_sdl(&sdl, config);

    do {

        is_running = process_events(&controls, sdl.window);
    }
    while(is_running);

    return 0;
}
