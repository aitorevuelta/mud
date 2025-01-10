#include <global.h>

#include <assets_utils.h>

#include <game_render.h>

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO* gameInfo)
{
    renderMap(renderer, loadedImages);
    renderUI(renderer);
}

void renderMap(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages)
{
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);
}

void renderUI(SDL_Renderer *renderer)
{
    

}