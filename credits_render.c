#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <credits_render.h>
#include <render.h>

int renderCredits(int rend_cred, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages) {
      // Variable estática para controlar la inicialización
    int buttonCount = 1;

    // Solo inicializa los botones una vez
    if (rend_cred == 0) {
        *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        // Inicializa los botones
       initializeButtonsCredits(*buttons, loadedImages);
       rend_cred =  1;
    }

    // Renderiza los botones
    renderTextureRelative(renderer, loadedImages[0].texture, 100, 50, 50);
    renderButtons(renderer, *buttons, buttonCount);
   
   return rend_cred;
}

void initializeButtonsCredits(BUTTON *buttons, IMAGES *loadedImages) {

    buttons[0] = (BUTTON){
        .texture = loadedImages[1].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}
