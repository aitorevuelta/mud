#include <global.h>

#include <assets_utils.h>

#include <game_render.h>

int renderGame(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo, CONFIG config, int rend_game)
{
    renderMap(renderer, loadedImages, loadedFonts, gameInfo);
    renderUI(renderer, loadedImages, loadedFonts, gameInfo);

    return rend_game;
}

void renderMap(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo)
{
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);
}

void renderUI(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo)
{
    gameInfo.numPlayers = 0; // comentado para que no pete xk no esta inicializada la estructura
    if (gameInfo.numPlayers > 0) {
        for (int i = 0; i < gameInfo.numPlayers; i++)
            {
                renderPlayerUI(renderer, loadedImages, loadedFonts, gameInfo.players[i]);
            }
    }
   
}

void renderPlayerUI(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, PLAYER playerinfo) {
    
}