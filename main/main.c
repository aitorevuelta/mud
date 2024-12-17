#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <controls.h>

int main(int argc, char *argv[])
{
    SDL sdl;
    CONFIG config = {1440, 720, 100, 144};
    CONTROLS controls = {0};

    bool is_running = init_sdl(&sdl, config);
    
    do {

        is_running = process_events(&controls, sdl.window);
    }
    while (is_running);

    return 0;
}
