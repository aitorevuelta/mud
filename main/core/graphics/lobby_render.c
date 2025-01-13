#include <global.h>

#include <assets_utils.h>

#include <lobby_render.h>


int renderLobby(int rend_lbby, SDL_Renderer *renderer, BUTTON **buttons,BUTTON_JUEGO **buttons_juego, IMAGES *loadedImages,GAMEINFO *gameInfo){  // Variable estática para controlar la inicialización
    int buttonCount = 4;
    

    // Solo inicializa los botones una vez
    if (rend_lbby == 0) {
        *buttons = (BUTTON *)malloc((buttonCount-2) * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }
         *buttons_juego = (BUTTON_JUEGO *)malloc((buttonCount-2) * sizeof(BUTTON_JUEGO));
        if (*buttons_juego == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        // Inicializa los botones
       initializeButtons5(*buttons_juego, loadedImages);
       initializeButtons6(*buttons,loadedImages);
       rend_lbby =  1;
    }

    // Renderiza el fondo
    SDL_RenderCopy(renderer, loadedImages[4].texture, NULL, NULL);
    // Renderiza una imagen
    SDL_Rect destRect = {1100, 100, 200, 100};
    SDL_RenderCopy(renderer, loadedImages[5].texture, NULL, &destRect);
    // Renderiza los botones
    renderButtons5(renderer, *buttons,*buttons_juego, buttonCount);
    renderPlayers(renderer, loadedImages, gameInfo->numPlayers);
   
   return rend_lbby;
}

void initializeButtons5(BUTTON_JUEGO *buttons_juego,IMAGES *loadedImages) {
    buttons_juego[0] = (BUTTON_JUEGO){ .rect = { 300, 200, 200, 200 }, .texture = loadedImages[0].texture, .visible = 1 };
    buttons_juego[1] = (BUTTON_JUEGO){ .rect = { 300, 500, 200, 200 }, .texture = loadedImages[1].texture, .visible = 1 };
}
void initializeButtons6(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ .rect = { 700, 350, 200, 200 }, .texture = loadedImages[3].texture, .action = ACTION_GAME, .visible = 1 };
    buttons[1] = (BUTTON){ .rect = { 20, 20, 100, 50 }, .texture = loadedImages[2].texture, .action = ACTION_EXIT, .visible = 1 };
}
void renderButtons5(SDL_Renderer *renderer, BUTTON *buttons,BUTTON_JUEGO *buttons_juego, int buttonCount) {
    for (int i = 0; i < buttonCount-2; i++) {
        if (buttons[i].visible) {
            if (buttons[i].texture == NULL) {
                fprintf(stderr, "Error: La textura del botón %d es NULL\n", i);
                continue;  // Saltar este botón si la textura es NULL
            }
            if (SDL_RenderCopy(renderer, buttons[i].texture, NULL, &buttons[i].rect) != 0) {
                fprintf(stderr, "Error en SDL_RenderCopy para el botón %d: %s\n", i, SDL_GetError());
            }
        }
    }
     for (int i = 0; i < buttonCount-2; i++) {
        if (buttons_juego[i].visible) {
            if (buttons_juego[i].texture == NULL) {
                fprintf(stderr, "Error: La textura del botón %d es NULL\n", i);
                continue;  // Saltar este botón si la textura es NULL
            }
            if (SDL_RenderCopy(renderer, buttons_juego[i].texture, NULL, &buttons_juego[i].rect) != 0) {
                fprintf(stderr, "Error en SDL_RenderCopy para el botón %d: %s\n", i, SDL_GetError());
            }
        }
    }
}
void renderPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount) {
    for (int i = 0; i < playerCount; i++) {
        SDL_Rect playerRect = {1100, (200+(i*100)), 200, 100};  // Ajusta las coordenadas y el tamaño según sea necesario
        SDL_RenderCopy(renderer, loadedImages[i+6].texture, NULL, &playerRect);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }
}