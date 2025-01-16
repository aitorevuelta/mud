#include <global.h>

#include <assets_utils.h>
#include <render.h>
#include <game_render.h>

int renderGame(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo, CONFIG config, int rend_game)
{
    renderMap(renderer, loadedImages, loadedFonts, gameInfo);
    renderUI(renderer, loadedImages, loadedFonts, gameInfo);
    return rend_game;
}

void renderMap(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo)
{
    // Get current renderer dimensions
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    // Calculate map position based on camera
    float mapX = (float)gameInfo.camera.pos[0] / windowWidth * 100;
    float mapY = (float)gameInfo.camera.pos[1] / windowHeight * 100;
    
    // Render map with camera offset
    renderTextureRelative(renderer, 
                         loadedImages[2].texture, 
                         125,  // width percentage
                         mapX, // x position adjusted by camera
                         mapY  // y position adjusted by camera
    );
}


void renderUI(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, GAMEINFO gameInfo)
{
   renderPlayerUI(renderer, loadedImages, loadedFonts, gameInfo.numPlayers, gameInfo.players);
   renderTimeBar(renderer, gameInfo, 50);
    //player ui

}

void renderPlayerUI(SDL_Renderer *renderer, IMAGES *loadedImages, FONTS *loadedFonts, int numPlayers, PLAYER* playerinfo) {
    int espacio = 5;
    int playerHeight = 10;
    
    if (numPlayers > 0) {
        int totalHeight = (numPlayers * playerHeight) + ((numPlayers - 1) * espacio);
        int startY = 50 + (totalHeight / 2);
        
        for (int i = 0; i < numPlayers; i++) {
            int currentY = startY - (i * (playerHeight + espacio));
            if (i == 2) {
                 renderTextureRelative(renderer, loadedImages[1].texture, 5, 89, currentY); // indicador de turno
            }
            // test
            COLOR testColor = {255, 0, 0, 255};  
            renderShapeRelative(renderer, 4, playerHeight, 97, currentY, testColor); // Fondo para cada jugador
            renderTextureRelative(renderer, loadedImages[0].texture, 7, 95, currentY); // marco
        }
    }
}

void renderTimeBar(SDL_Renderer *renderer, GAMEINFO gameInfo, int elapsed)
{
    COLOR testColor = {255, 0, 0, 255};
    renderShapeRelative(renderer, elapsed, 4, 0, 0, testColor); 
}