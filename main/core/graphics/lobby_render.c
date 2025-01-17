#include <global.h>

#include <assets_utils.h>

#include <lobby_render.h>
#include <render.h>

int renderLobby(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, GAMEINFO *gameInfo, int rend_lbby) {
    int buttonCount = 6;

    // Solo inicializa los botones una vez
    if (rend_lbby == 0) {
        *buttons = (BUTTON *)malloc((buttonCount) * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }
        // Inicializa los botones
        initializeButtonsLobby(*buttons, loadedImages);
        rend_lbby = 1;
    }

    // Renderiza el fondo
    renderTextureRelative(renderer, loadedImages[0].texture, 100, 50, 50);

    // Renderiza los botones
    renderButtons(renderer, *buttons, buttonCount);
    
    // Renderiza los jugadores
    renderPlayers(renderer, loadedImages, gameInfo->numPlayers);

    // Renderiza el mapa actual
    renderSelectedMap(renderer, loadedImages, gameInfo->numMaps);

    return rend_lbby;
}

void initializeButtonsLobby(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ // BOTON AÑADIR
        .texture = loadedImages[4].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 15.0,
        .yPercent = 80.0
    };
    buttons[1] = (BUTTON){ // BOTON ELIMINAR
        .texture = loadedImages[5].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 4.0,
        .xPercent = 20.0,
        .yPercent = 80.0
    };
    buttons[2] = (BUTTON){ // BOTON PASAR MAPA IZQUIERDA
        .texture = loadedImages[10].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 75.0,
        .yPercent = 90.0
    };
    buttons[3] = (BUTTON){ // BOTON PASAR MAPA DERECHA
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 85.0,
        .yPercent = 90.0
    };
    buttons[4] = (BUTTON){ // BOTON JUGAR
        .texture = loadedImages[7].texture,
        .action = ACTION_GAME,
        .visible = 1,
        .widthPercent = 15.0,
        .xPercent = 50.0,
        .yPercent = 90.0
    };
    buttons[5] = (BUTTON){ // BOTON BACK
        .texture = loadedImages[6].texture,
        .action = ACTION_EXIT,
        .visible = 1,
        .widthPercent = 3.7,
        .xPercent = 3.0,
        .yPercent = 6.0

    };
}
void renderPlayers(SDL_Renderer *renderer, IMAGES *loadedImages, int playerCount) {
    for (float i = 0; i < playerCount; i++) {
    if(i<2){
        renderTextureRelative(renderer, loadedImages[8].texture, 20,(20+(i*25)),30);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }else if(i==2){
        renderTextureRelative(renderer, loadedImages[8].texture, 20,20,55);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }else{
        renderTextureRelative(renderer, loadedImages[8].texture, 20,45,55);  // Suponiendo que la textura del jugador está en loadedImages[6]
    }
    }
}

void renderSelectedMap(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedMap) {
    renderTextureRelative(renderer, loadedImages[selectedMap].texture, 35, 80, 50); //MAPA
}