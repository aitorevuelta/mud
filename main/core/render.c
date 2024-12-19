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

        SDL_RenderCopy(renderer, loadedTextures[0].texture, NULL, NULL);

        SDL_RenderPresent(renderer);
}
