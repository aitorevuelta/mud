#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h> 

#include <render.h>
#include <lobby.h>

#include <lobby_render.h>

int lobby_render(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, GAMEINFO *gameInfo, int rend_lbby) {
    const int buttonCount = 6;

    if (rend_lbby == 0) {
        rend_lbby = setupLobbyButtons(buttons, buttonCount, loadedAssets);
        if (rend_lbby == -1) return -1;
    }

    // Renderiza el fondo
    renderTextureRelative(renderer, loadedAssets->images[0].texture, 100, 50, 50);

    // Renderiza los botones
    renderButtons(renderer, *buttons, buttonCount);
    
    // Renderiza los jugadores
    renderLobbyPlayers(renderer, loadedAssets->images, gameInfo->numPlayers);

    // Renderiza el mapa actual
    renderLobbySelectedMap(renderer, loadedAssets->images, gameInfo->currentMapID);

    return rend_lbby;
}




void renderLobbyPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount) {
    float i = 0;
    for (i = 0; playerCount > i; i++) {
    if(i<2){
        renderTextureRelative(renderer, loadedImages[8].texture, 20,(20+(i*25)),30);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }else if(i==2){
        renderTextureRelative(renderer, loadedImages[8].texture, 20,20,55);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }else{
        renderTextureRelative(renderer, loadedImages[8].texture, 20,45,55);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }
    }
}

void renderLobbySelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap) {
    renderTextureRelative(renderer, loadedImages[selectedMap].texture, 35, 80, 50); //MAPA
}