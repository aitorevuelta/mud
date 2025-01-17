#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <settings_render.h>
#include <render.h>

int renderSettings(int rend_sett, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, GAMEINFO *gameInfo) {
    // Variable estática para controlar la inicialización
    int buttonCount = 6;

    // Solo inicializa los botones una vez
    if (rend_sett == 0) {
        *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        //Inicializa los botones
       initializeButtonsSettings(*buttons, loadedImages);
       rend_sett =  1;
    }    

    renderTextureRelative(renderer, loadedImages[0].texture, 150, 50, 50);
    renderTextureRelative(renderer, loadedImages[16].texture, 35, 50, 10);

    renderSelectedResolution(renderer, loadedImages, gameInfo->config.resolution);
    renderSelectedVolume(renderer, loadedImages, gameInfo->config.selectedVolume);
    
    renderButtons(renderer, *buttons, buttonCount);

   return rend_sett;
}

void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages) {
    buttons[0] = (BUTTON){ // BOTON VOLVER
        .texture = loadedImages[10].texture, 
        .action = ACTION_EXIT,  // Acción para salir de la configuración
        .visible = 1,
        .widthPercent = 3.0,
        .xPercent = 6.0,
        .yPercent = 6.0
    };  
    buttons[1] = (BUTTON){ // BOTON PASAR RESOLUCION IZQUIERDA 
        .texture = loadedImages[8].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 25.0,
        .yPercent = 35.0
    };
    buttons[2] = (BUTTON){ // BOTON PASAR RESOLUCION DERECHA
        .texture = loadedImages[9].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 45.0,
        .yPercent = 35.0
    };
        buttons[3] = (BUTTON){ //BOTON APLICAR
        .texture = loadedImages[11].texture, 
        .action = ACTION_NONE, 
        .visible = 1, 
        .widthPercent = 15.0, 
        .xPercent = 50.0, 
        .yPercent = 80.0 
    };
        buttons[4] = (BUTTON){  //BOTON SUBIR VOLUMEN
        .texture = loadedImages[12].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 15.7,
        .yPercent = 50.0
        };
        buttons[5] = (BUTTON){  //BOTON BAJAR VOLUMEN
        .texture = loadedImages[13].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 3.5,
        .xPercent = 38.5,
        .yPercent = 50.0
        };

}

void renderSelectedResolution(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedResolution) {
    renderTextureRelative(renderer, loadedImages[14].texture, 50, 23, 35);
    renderTextureRelative(renderer, loadedImages[17].texture, 15, 8.5, 35);
    renderTextureRelative(renderer, loadedImages[selectedResolution].texture, 16.5, 35, 35); //Resolucion
}

void renderSelectedVolume(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedVolume) {
    renderTextureRelative(renderer, loadedImages[14].texture, 50, 18, 50);
    renderTextureRelative(renderer, loadedImages[18].texture, 4, 6, 50);
    renderTextureRelative(renderer, loadedImages[19].texture, 16.5, 27.5, 50);

    // Verificar si hay barras que renderizar
    if (selectedVolume > 0) {
        for (int i = 0; i < selectedVolume; i++) {
            renderTextureRelative(renderer, loadedImages[15].texture, 1.6, (22.5 + (i * 2.5)), 50);
        }
    }
}