#include <global.h>

#include <assets_utils.h>
#include <render.h>
#include <game_render.h>

int renderGame(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo, CONFIG config, int rend_game)
{
    renderMap(renderer, loadedAssets, gameInfo);
    renderUI(renderer, loadedAssets, gameInfo);
    return rend_game;
}

void renderMap(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo)
{
    // Get current renderer dimensions
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    
    // Calculate map width based on zoom (zoom 0.5 = 200%, zoom 2.0 = 50%)
    float mapWidth = 100.0f * gameInfo.camera.zoom;
    // Calculate map position based on camera and zoom
    float mapX =((float)gameInfo.camera.pos[0] / windowWidth * 100.0f);
    float mapY =((float)gameInfo.camera.pos[1] / windowHeight * 100.0f);
    
    // Render map with camera offset
    renderTextureRelative(renderer, 
                         loadedAssets->images[2].texture, 
                         mapWidth,
                         mapX,
                         mapY
    );
}

void renderUI(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMEINFO gameInfo)
{
   renderPlayerUI(renderer, loadedAssets, gameInfo.numPlayers, gameInfo.players);
   renderTimeBar(renderer, gameInfo, 50);
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
                 renderTextureRelative(renderer, loadedAssets->images[1].texture, 5, 89, currentY); // indicador de turno
            }
            // test
            COLOUR testColor = {255, 0, 0, 255};  
            renderShapeRelative(renderer, 4, playerHeight, 97, currentY, testColor); // Fondo para cada jugador
            renderTextureRelative(renderer, loadedAssets->images[0].texture, 7, 95, currentY); // marco
        }
    }
}

void renderTimeBar(SDL_Renderer *renderer, GAMEINFO gameInfo, int elapsed)
{
    COLOUR testColor = {255, 0, 0, 255};
    renderShapeRelative(renderer, elapsed, 4, 0, 0, testColor); 
}