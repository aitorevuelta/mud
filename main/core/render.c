#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <render.h>

void render(SDL_Renderer *renderer) {
    SDL_RenderPresent(renderer); 
}
