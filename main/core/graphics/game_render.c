#include <global.h>

#include <assets_utils.h>
#include <render.h>
#include <game_render.h>

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo, CONFIG config)
{
    renderMap(renderer, loadedImages, loadedFonts, gameInfo);
    renderUI(renderer, loadedImages, loadedFonts, gameInfo);
}

void renderMap(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo)
{
    renderTextureRelative(renderer, loadedImages[0].texture, 80, 50, 50);
}

void renderUI(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMEINFO gameInfo)
{
    gameInfo.numPlayers = 0; // comentado para que no pete xk no esta inicializada la estructura
    if (gameInfo.numPlayers > 0) {
        for (int i = 0; i < gameInfo.numPlayers; i++)
            {
                renderPlayerUI(renderer, loadedImages, loadedFonts, gameInfo.players[i]);
            }
    }
   
}

void renderPlayerUI(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, PLAYER playerinfo) {
    
}