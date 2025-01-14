#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <credits_render.h>

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
       initializeButtons3(*buttons, loadedImages);
       rend_cred =  1;
    }

    // Renderiza los botones
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);
    renderButtons3(renderer, *buttons, buttonCount);
   
   return rend_cred;
}

void initializeButtons3(BUTTON *buttons, IMAGES *loadedImages) {

    buttons[0] = (BUTTON){ .rect = { 20, 20, 100, 50 }, .texture = loadedImages[1].texture, .action = ACTION_EXIT, .visible = 1 };
}
void renderButtons3(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount) {
    for (int i = 0; i < buttonCount; i++) {
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
}