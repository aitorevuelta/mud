#include <global.h>
#include <assets_utils.h>
#include <menu.h>
#include <settings_render.h>

int renderSettings(int rend_sett, SDL_Renderer *renderer, BUTTON **buttons, IMAGES *loadedImages) {
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
       initializeButtons2(*buttons, loadedImages);
       rend_sett =  1;
    }

    // Renderiza los botones
    SDL_RenderCopy(renderer, loadedImages[3].texture, NULL, NULL);
    renderButtons2(renderer, *buttons, buttonCount);
   
   return rend_sett;
}

void initializeButtons2(BUTTON *buttons, IMAGES *loadedImages) {

    buttons[0] = (BUTTON){ .rect = { 200, 200, 300, 100 }, .texture = loadedImages[0].texture, .action = ACTION_PLAY, .visible = 0 };
    buttons[1] = (BUTTON){ .rect = { 200, 320, 300, 100 }, .texture = loadedImages[1].texture, .action = ACTION_HOWTOPLAY, .visible = 0 };
    buttons[2] = (BUTTON){ .rect = { 200, 440, 300, 100 }, .texture = loadedImages[2].texture, .action = ACTION_CREDITS, .visible = 0 };
    buttons[3] = (BUTTON){ .rect = { 200, 560, 300, 100 }, .texture = loadedImages[3].texture, .action = ACTION_SETTINGS, .visible = 0 };
    buttons[4] = (BUTTON){ .rect = { 20, 20, 100, 50 }, .texture = loadedImages[4].texture, .action = ACTION_EXIT, .visible = 1 };
}
void renderButtons2(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount) {
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