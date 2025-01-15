#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <howtoplay_render.h>
#include <render.h>

int renderHowtoplay(int rend_h2p, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages) {
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

    renderTextureRelative(renderer, loadedImages[2].texture, 23, 20, 25);
    renderTextureRelative(renderer, loadedImages[3].texture, 18, 40, 25);
    renderTextureRelative(renderer, loadedImages[4].texture, 20, 60, 25);

    renderTextureRelative(renderer, loadedImages[5].texture, 26, 18, 50);
    renderTextureRelative(renderer, loadedImages[6].texture, 24, 38, 50);

    renderTextureRelative(renderer, loadedImages[9].texture, 40, 80, 65);

    renderTextureRelative(renderer, loadedImages[7].texture, 23, 20, 85);
    renderTextureRelative(renderer, loadedImages[8].texture, 22, 40, 85);


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
