#include <global.h>

#include <assets_utils.h>

#include <game_render.h>

int renderGame(int rend_game, SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMEINFO* gameinfo, CONFIG config)
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