#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <global.h>
#include <init.h>
#include <SDL_net.h>


int main(int argc, char *argv[])
{
    SDL sdl;
    CONFIG config = {800, 600, 100, 60};

    bool is_running = init_sdl(&sdl, config);
    
    do {
        
    }
    while (is_running);

    return 0;
}
