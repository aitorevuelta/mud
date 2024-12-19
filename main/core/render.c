#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>

void render(SDL_Renderer *renderer, LOADEDTEXTURES *loadedTextures, GAMESTATE gameState) {
    SDL_RenderClear(renderer);
    switch(gameState) {
            case LOADSCREEN:
                SDL_RenderCopy(renderer, loadedTextures[0].texture, NULL, NULL);
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
}
