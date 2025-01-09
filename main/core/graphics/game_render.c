#include <global.h>

#include <assets_utils.h>

#include <game_render.h>

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Fondo negro
    SDL_RenderClear(renderer);
    renderMap(renderer);
    renderUI(renderer);
}

void renderMap(SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Blanco
    SDL_Rect territory = {100, 100, 200, 200};
    SDL_RenderFillRect(renderer, &territory);
}

void renderUI(SDL_Renderer *renderer)
{
    

}