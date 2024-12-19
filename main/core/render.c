#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <loadscreen.h>
#include <utils.h>

void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE gameState, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);
    switch(gameState) {
            case LOADSCREEN:
                renderLoadscreen(renderer, loadedImages, config);
            break;
            case MAIN_MENU:

            break;
            case LOBBY:

            break;
            case GAME:

            break;
            case SETTINGS:

            break;
            case CREDITS:

            break;
        }
        SDL_RenderPresent(renderer);
        adjustFrameRate(frameStart, config.max_FPS);
}
