#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h> 

#include <render.h>

#include <lobby_render.h>

void lobby_render(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets, GAMEINFO gameInfo) { // lobbya erakutsi
    if(!buttons || !loadedAssets.images || !loadedAssets.fonts) return;

    renderTextureRelative(renderer, loadedAssets.images[0].texture, 150, 50, 50); 

    renderButtons(renderer, buttons, 6); 

    renderLobbyPlayers(renderer, loadedAssets, gameInfo.numPlayers);

    renderLobbySelectedMap(renderer, loadedAssets.images, gameInfo.currentMapID);
}

void renderLobbyPlayers(SDL_Renderer *renderer, ASSETS loadedAssets, int playerCount) { // jokalariak erakutsi
    if(playerCount < 0) return;
    int positions[][2] = {{20, 20}, {20, 45}, {45, 20}, {45, 45}}; // jokalarien posizioak
    int maxPositions = sizeof(positions) / sizeof(positions[0]); 
    int i = 0, x = 0, y = 0;

    for (i = 0; playerCount > i ; i++) {
        getPlayerPosition(i, positions, maxPositions, &x, &y);
        renderTextureRelative(renderer, loadedAssets.images[8].texture, 20, (float)x, (float)y); 
        renderTextRelative(renderer, loadedAssets.fonts[0].font, "Player", (SDL_Color){255, 255, 255, 255}, (SDL_Color){55, 55, 55, 12}, 3, 10, x, y);
    }
}

void renderLobbySelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap) { // hautatutako mapa erakutsi
    renderTextureRelative(renderer, loadedImages[selectedMap].texture, 30,80, 40);
    renderTextureRelative(renderer, loadedImages[11].texture, 40,80,45);
}

void getPlayerPosition(int index, int positions[][2], int maxPositions, int *x, int *y) { // jokalarien posizioa lortu
    if (index < maxPositions) {
        *x = positions[index][0];
        *y = positions[index][1];
    } else {
        *x = positions[maxPositions - 1][0];
        *y = positions[maxPositions - 1][1];
    }
}