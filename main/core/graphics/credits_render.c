#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <credits_render.h>
#include <render.h>

int renderCredits(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, int rend_cred) {
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
       initializeButtonsCredits(*buttons, loadedAssets->images);
       rend_cred =  1;
    }

    // Renderiza los botones
    renderTextureRelative(renderer, loadedAssets->images[0].texture, 150, 50, 50);
    renderTextureRelative(renderer, loadedAssets->images[2].texture, 35, 50, 10);
    renderTextureRelative(renderer, loadedAssets->images[3].texture, 25, 25, 58);
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

