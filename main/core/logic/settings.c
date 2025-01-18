
#include <global.h>

#include <controls.h>
#include <menu.h>
#include <settings_utils.h>

#include <settings.h>







void handleResolutionButtons(SDL_Window *window, BUTTON *buttons, int buttonCount, CONTROLS *controls, GAMESTATE *gameState, CONFIG *config) {
    if (window == NULL || buttons == NULL || controls == NULL || config == NULL) {
        fprintf(stderr, "Error: Parámetros nulos en handleResolutionButtons.\n");
        return;
    }

    if (controls->click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {

                    if (i == 1) { // Flecha izquierda
                        changeResolution(-1, config);
                    } else if (i == 2) { // Flecha derecha
                        changeResolution(1, config);
                    } else if (i == 3) { // Botón Aplicar
                        applyResolution(window, config);
                    }

                    if (buttons[i].action != ACTION_NONE) {
                        GAMESTATE currentState = *gameState;
                        *gameState = buttons[i].action;
                        handleExitStates(currentState, gameState);
                    }

                    controls->click = 0; // Resetear clic
                    return;
                }
            }
        }
    }
}

void changeResolution(int direction, CONFIG *config) {
    if (config == NULL || config->resolutions == NULL) {
        fprintf(stderr, "Error: Configuración o resoluciones no inicializadas.\n");
        return;
    }

    if (direction == -1) { // Mover a resolución anterior
        config->current_res = 
            (config->current_res == 0) 
            ? config->total_res - 1 
            : config->current_res - 1;
    } 
    else if (direction == 1) { // Mover a resolución siguiente
        config->current_res = 
            (config->current_res == config->total_res - 1) 
            ? 0 
            : config->current_res + 1;
    }

    // Actualizar la configuración de ventana con la nueva resolución
    config->window_size = config->resolutions[config->current_res];
}

void applyResolution(SDL_Window *window, CONFIG *config) {
    if (config == NULL || config->resolutions == NULL) {
        fprintf(stderr, "Error: Configuración no inicializada o resoluciones no disponibles.\n");
        return;
    }

    const RESOLUTION resolutions[] = {
        {800, 600}, {1024, 768}, {1280, 720}, {1366, 768}, {1600, 900}, {1920, 1080}
    };

    int index = config->current_res - 1; // Usar `current_res` directamente
    if (index >= 0 && index < 6) {
        config->window_size.width = resolutions[index].width;
        config->window_size.height = resolutions[index].height;
    } else {
        fprintf(stderr, "Error: Resolución inválida seleccionada.\n");
        return;
    }

    //saveConfig(config);  // Guardar la configuración actualizada
    SDL_SetWindowSize(window, config->window_size.width, config->window_size.height);
    SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}