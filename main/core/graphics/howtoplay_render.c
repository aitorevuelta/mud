#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <howtoplay_render.h>
#include <render.h>

int renderHowtoplay(SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages, int rend_h2p) {
    // Variable estática para controlar la inicialización
    int buttonCount = 1;

    // Solo inicializa los botones una vez
    if (rend_h2p == 0) {
        *buttons = (BUTTON *)malloc(buttonCount * sizeof(BUTTON));
        if (*buttons == NULL) {
            fprintf(stderr, "Error al asignar memoria para los botones\n");
            return -1;
        }

        // Inicializa los botones
       initializeButtonsH2P(*buttons, loadedImages);
       rend_h2p =  1;
    }

    // Renderiza los botones
    renderTextureRelative(renderer, loadedImages[0].texture, 100, 50, 50);
    renderButtons(renderer, *buttons, buttonCount);
   
   return rend_h2p;
}

void initializeButtonsH2P(BUTTON *buttons, IMAGES *loadedImages) {
        buttons[0] = (BUTTON){ 
        .texture = loadedImages[1].texture, 
        .action = ACTION_EXIT, 
        .visible = 1, 
        .widthPercent = 4.0, 
        .xPercent = 3.0, 
        .yPercent = 5.0 
    };
}
