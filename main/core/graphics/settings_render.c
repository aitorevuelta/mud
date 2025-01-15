#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <settings_render.h>
#include <render.h>

int renderSettings(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, int rend_sett) {
      // Variable estática para controlar la inicialización
    int buttonCount = 1;

    // Solo inicializa los botones una vez
    if (rend_sett == 0) {
        *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        // Inicializa los botones
       initializeButtonsSettings(*buttons, loadedImages);
       rend_sett =  1;
    }

    // Renderiza los botones
    renderTextureRelative(renderer, loadedImages[0].texture, 100, 50, 50);
    renderButtons(renderer, *buttons, buttonCount);
   
   return rend_sett;
}

void initializeButtonsSettings(BUTTON *buttons, IMAGES *loadedImages) {
        buttons[0] = (BUTTON){ //BOTON JUGAR
        .texture = loadedImages[1].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}