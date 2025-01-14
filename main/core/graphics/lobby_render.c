#include <global.h>

#include <assets_utils.h>

#include <lobby_render.h>



void renderPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        SDL_Rect playerRect = {200, (250+(i*100)), 200, 100};  // Ajusta las coordenadas y el tamaño según sea necesario
        SDL_RenderCopy(renderer, loadedImages[i+9].texture, NULL, &playerRect);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }
}

void renderSelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap) {
    SDL_Rect mapRect = { 900, 150, 350, 350 };  // Ajusta las coordenadas y el tamaño según sea necesario
    SDL_RenderCopy(renderer, loadedImages[selectedMap].texture, NULL, &mapRect);  // Suponiendo que las texturas de los mapas están en loadedImages
}