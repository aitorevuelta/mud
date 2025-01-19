#include <global.h>

#include <assets_utils.h>
#include <render.h>

#include <game_render.h>


void game_render(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo, CONFIG config)
{
    renderMap(renderer, loadedAssets, gameInfo);
    renderUI(renderer, loadedAssets, gameInfo);
}

void renderMap(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo)
{
    // Get current renderer dimensions
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    
    // Calculate map width based on zoom (zoom 0.5 = 200%, zoom 2.0 = 50%)
    float mapWidth = 100.0f * gameInfo.camera.zoom;
    // Calculate map position based on camera and zoom
    float mapX =((float)gameInfo.camera.pos[0] / windowWidth * 100.0f);
    float mapY =((float)gameInfo.camera.pos[1] / windowHeight * 100.0f);
    // mapa de mascara

    renderTextureRelative(renderer, 
                        loadedAssets.images[3].texture, 
                        mapWidth,
                        mapX,
                        mapY
    );

    renderTextureRelative(renderer, 
                        loadedAssets.images[2].texture, 
                        mapWidth,
                        mapX,
                        mapY
    );
}

void renderUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo)
{
   renderSideUI(renderer, loadedAssets, gameInfo.numPlayers, gameInfo.players);
   renderBottomUI(renderer, loadedAssets, gameInfo);
   renderTimeBar(renderer, gameInfo, 50);

}

void renderSideUI(SDL_Renderer *renderer, ASSETS loadedAssets, int numPlayers, PLAYER players[]) {
    int espacio = 5;
    int playerHeight = 10;
    
    if (numPlayers > 0) {
        int totalHeight = (numPlayers * playerHeight) + ((numPlayers - 1) * espacio);
        int startY = 50 + (totalHeight / 2);
        
        int i;
        for (i = 0; numPlayers > i; i++) {
            int currentY = startY - (i * (playerHeight + espacio));
            if (i == 2) {
                renderTextureRelative(renderer, loadedAssets.images[1].texture, 5, 89, currentY); // indicador de turno
            }
            

            renderShapeRelative(renderer, 4, playerHeight, 97, currentY, players[i].playerColor, 0, (SDL_Color){0,0,0,0}); // Fondo para cada jugador
            renderTextureRelative(renderer, loadedAssets.images[0].texture, 7, 95, currentY); // marco
        }
    }
}

void renderBottomUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo) {
    int center = 50;
    int height = 88;
    // Cuadrado central

    SDL_Color color = gameInfo.players[0].playerColor;
    color.a = 200;
    renderShapeRelative(renderer, 20, 10, center - 10, height, (SDL_Color){0,0,0,150} , 5, color);  // cuadrado de atras
    renderTextureRelative(renderer, loadedAssets.images[0].texture, 8, center - 12, height); // imagen player
    renderTextureRelative(renderer, loadedAssets.images[0].texture, 8, center + 12, height); // imagen dados o tropas dependiendo de la fase
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "DESPLIEGE", 
                   (SDL_Color){255, 255, 255, 255},  // Color del texto (blanco)
                   (SDL_Color){55, 55, 55, 12},        // Color del borde (negro)
                   3,                                // Grosor del borde (5 píxeles)
                   10,                               // Porcentaje del ancho del texto
                   center,                           // Posición X relativa (centro)
                   height - 5);                      // Posición Y relativa
    
    // cuadrados de fases
    int squareWidth = 4;
    int gap = 1;
    int totalWidth = (squareWidth * 3) + (gap * 2);
    int startX = center - (totalWidth / 2);
    for (int i = 0; i < 3; i++) {

        renderShapeRelative(renderer, squareWidth,2, 
            startX + (i * (squareWidth + gap)), 
            height -1 , 
           gameInfo.players[0].playerColor, 3, (SDL_Color){30, 30, 30, 200} ); 
    }
    
}

void renderTimeBar(SDL_Renderer *renderer, GAMEINFO gameInfo, int elapsed)
{
    renderShapeRelative(renderer, 100, 4, 0, 0, (SDL_Color) {0, 0, 0, 100}, 0, (SDL_Color){0, 0, 0, 255}); 
    renderShapeRelative(renderer, elapsed, 4, 0, 0, gameInfo.players[0].playerColor, 0, (SDL_Color){0, 0, 0, 255}); 
}
