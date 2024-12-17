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
    CONFIG config = {800, 600, 100, 60};
    CONTROLS controls = {0};

    bool is_running = init_sdl(&sdl, config);
    
    do {
        process_events(&controls);
    }
    while (is_running);

    return 0;
}
