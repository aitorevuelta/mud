#include <global.h>

#include <assets_utils.h>
#include <render.h>
#include <game_render.h>

int renderGame(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo, CONFIG config, int rend_game) {
    renderMap(renderer, loadedAssets, gameInfo);
    renderUI(renderer, loadedAssets, gameInfo);
    return rend_game;
}

void renderMap(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo) {
    renderTextureRelative(renderer, loadedAssets->images[2].texture, 100, 50, 50);
}

void renderUI(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo) {
    renderPlayerUI(renderer, loadedAssets, gameInfo.numPlayers, gameInfo.players);

    //player ui

}

void renderPlayerUI(SDL_Renderer *renderer, ASSETS *loadedAssets, int numPlayers, PLAYER* playerinfo) {
    int espacio = 5;
    int playerHeight = 10;
    
    if (numPlayers > 0) {
        int totalHeight = (numPlayers * playerHeight) + ((numPlayers - 1) * espacio);
        int startY = 50 + (totalHeight / 2);
        
        for (int i = 0; i < numPlayers; i++) {
            int currentY = startY - (i * (playerHeight + espacio));
            if (i == 2) {
                renderTextureRelative(renderer, loadedAssets->images[1].texture, 5, 89, currentY);
            }
            renderTextureRelative(renderer, loadedAssets->images[0].texture, 7, 95, currentY);
        }
    }
}