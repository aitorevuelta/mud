#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h> 

#include <render.h>

#include <lobby_render.h>

void lobby_render(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets, GAMEINFO gameInfo) {

    renderTextureRelative(renderer, loadedAssets.images[0].texture, 150, 50, 50); // Renderizar background

    renderButtons(renderer, buttons, 6); // Renderizar botones

    renderLobbyPlayers(renderer, loadedAssets.images, gameInfo.numPlayers); // Renderizar numero de jugadores

    renderLobbySelectedMap(renderer, loadedAssets.images, gameInfo.currentMapID); // Renderizar preview mapa seleccionado

}

void renderLobbyPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount) {
    int positions[][2] = {{20, 20}, {20, 45}, {45, 20}, {45, 45}}; // Posiciones de los jugadores
    int maxPositions = sizeof(positions) / sizeof(positions[0]); // Jugadores maximos cogiendo el array de posiciones
    int i = 0, x = 0, y = 0;

    for (i = 0; i < playerCount; i++) {
        if (i < maxPositions) {
            x = positions[i][0];
            y = positions[i][1];
        } else {
            x = positions[maxPositions - 1][0];
            y = positions[maxPositions - 1][1];
        }
        renderTextureRelative(renderer, loadedImages[8].texture, 20, x, y); // Renderizar jugador con respecto a i
    }
}

void renderLobbySelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap) {
    renderTextureRelative(renderer, loadedImages[selectedMap].texture, 30,80, 40);
    renderTextureRelative(renderer, loadedImages[11].texture, 40,80,45);
}