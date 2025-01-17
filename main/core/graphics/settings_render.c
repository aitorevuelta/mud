#include <global.h>

#include <assets_utils.h>
#include <menu.h>
#include <settings_render.h>

#include <render.h>

int renderSettings(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, CONFIG *config, int rend_sett) {
    // Variable estática para controlar la inicialización
    int buttonCount = 5;

    // Solo inicializa los botones una vez
    if (rend_sett == 0) {
        *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        // Inicializa los botones
       initializeButtonsSettings(*buttons, loadedAssets->images);
       rend_sett =  1;
    }

    // Renderiza los botones
    renderTextureRelative(renderer, loadedAssets->images[8].texture, 100, 50, 50);
    renderButtons(renderer, *buttons, buttonCount);
    renderSelectedResolution(renderer, loadedAssets->images, config->current_res);
   
   return rend_sett;
}

void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages) {
        buttons[0] = (BUTTON){ // Itzuli
        .texture = loadedImages[9].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
    buttons[1] = (BUTTON){ // BOTON PASAR RESOLUCION IZQUIERDA
        .texture = loadedImages[7].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 45.0,
        .yPercent = 50.0
    };
    buttons[2] = (BUTTON){ // BOTON PASAR RESOLUCION DERECHA
        .texture = loadedImages[6].texture,
        .action = ACTION_NONE,
        .visible = 1,
        .widthPercent = 5.0,
        .xPercent = 55.0,
        .yPercent = 50.0
    };
        buttons[3] = (BUTTON){ //BOTON APLICAR
        .texture = loadedImages[10].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}

void renderSelectedResolution(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedResolution) {
    renderTextureRelative(renderer, loadedImages[selectedResolution].texture, 25, 80, 50); //RESOLUCIONES
}