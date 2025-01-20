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
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    float mapWidth = 200.0f * gameInfo.camera.zoom; // Escala del mapa con respecto al zoom
    float mapX = ((float)gameInfo.camera.pos[0] / windowWidth * 100.0f); // Posicion x ajustada del mapa con la camara
    float mapY = ((float)gameInfo.camera.pos[1] / windowHeight * 100.0f); // Posicion y ajustada del mapa con la camara

    renderTextureRelative(renderer, loadedAssets.images[0].texture, mapWidth, mapX, mapY); // Renderizar mapa
}

void renderUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo)
{
    renderSideUI(renderer, loadedAssets, gameInfo.numPlayers, gameInfo.players); // UI lateral
    renderBottomUI(renderer, loadedAssets, gameInfo); // UI inferior
    renderTimeBar(renderer, gameInfo, 50); // Barra de tiempo
}

void renderSideUI(SDL_Renderer *renderer, ASSETS loadedAssets, int numPlayers, PLAYER players[])
{
    int espacio = 5;
    int playerHeight = 10;
    int totalHeight = (numPlayers * playerHeight) + ((numPlayers - 1) * espacio);
    int startY = 50 + (totalHeight / 2);

    for (int i = 0; i < numPlayers; i++) {
        int currentY = startY - (i * (10 + 5));

        if (i == 0) { //Puesto de prueba
            renderTextureRelative(renderer, loadedAssets.images[4].texture, 3, 88, currentY); // Indicador turno
        }
        renderTextureRelative(renderer, loadedAssets.images[3].texture, 6, 92, currentY-4); // Indicador de cartas jugador
        renderTextRelative(renderer, loadedAssets.fonts[0].font, "0", (SDL_Color){255, 255, 255, 255}, 
                          (SDL_Color){55, 55, 55, 12}, 3, 1, 90.15, currentY-5); // Texto fase
        renderShapeRelative(renderer, 4, playerHeight, 97, currentY, players[i].playerColor, 4, (SDL_Color){75, 59, 117, 255}); // Fondo jugador
        renderTextureRelative(renderer, loadedAssets.images[6].texture, 7, 95, currentY); // Jugador
        renderTextureRelative(renderer, loadedAssets.images[2].texture, 7, 95, currentY); // Marco jugador
    }
}

void renderBottomUI(SDL_Renderer *renderer, ASSETS loadedAssets, GAMEINFO gameInfo)
{
    int center = 50;
    int height = 88;

    SDL_Color PlayerColor = gameInfo.players[0].playerColor;
    PlayerColor.a = 200;

    renderShapeRelative(renderer, 20, 10, center - 10, height, (SDL_Color){115, 132, 255, 255}, 7, (SDL_Color){75, 59, 117, 255}); // Cuadrado central
    renderTextureRelative(renderer, loadedAssets.images[3].texture, 6, center - 15.5, height-5); // Indicador de cartas jugador
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "0", (SDL_Color){255, 255, 255, 255}, 
                          (SDL_Color){55, 55, 55, 12}, 3, 1, center-17.4, height-6); // Texto numero cartas
    renderTextureRelative(renderer, loadedAssets.images[2].texture, 8, center - 12, height); // Circulo izquierda
    renderTextureRelative(renderer, loadedAssets.images[6].texture, 8, center - 12, height); // Jugador
    renderTextureRelative(renderer, loadedAssets.images[2].texture, 8, center + 12, height); // Circulo derecha
    renderTextureRelative(renderer, loadedAssets.images[6].texture, 8, center + 12, height); // Dentro circulo derecha

    renderTextRelative(renderer, loadedAssets.fonts[0].font, "DESPLIEGE", (SDL_Color){255, 255, 255, 255}, 
                      (SDL_Color){55, 55, 55, 12}, 3, 10, center, height - 5); // Texto fase

    int squareWidth = 4, gap = 1;
    int totalWidth = (squareWidth * 3) + (gap * 2);
    int startX = center - (totalWidth / 2);

    for (int i = 0; i < 3; i++) {
        renderShapeRelative(renderer, squareWidth, 2, startX + (i * (squareWidth + gap)), height - 1, 
                            gameInfo.players[0].playerColor, 3, (SDL_Color){75, 59, 117, 255}); // Cuadrados fase
    }
}

void renderTimeBar(SDL_Renderer *renderer, GAMEINFO gameInfo, int elapsed)
{
    renderShapeRelative(renderer, 100, 4, 0, 0, (SDL_Color){0, 0, 0, 100}, 0, (SDL_Color){0, 0, 0, 255}); // Background barra
    renderShapeRelative(renderer, elapsed, 4, 0, 0, gameInfo.players[0].playerColor, 0, (SDL_Color){0, 0, 0, 255}); // Barra de tiempo
}