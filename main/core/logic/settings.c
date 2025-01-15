#include <global.h>

#include <menu.h>

#include <settings.h>
void handleResolutionButtons(BUTTON *buttons, int buttonCount, GAMEINFO *gameInfo, CONTROLS *controls) {
    if (controls->click == 1) {
        for (int i = 1; i <= buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {

                    // Verifica si la acción es válida antes de ejecutarla
                    if (buttons[i].action == ACTION_NONE) { // Cambié NULL por ACTION_NONE
                        }else if (i == 1) {  // Botón de flecha izquierda
                            if (gameInfo->config.resolution >1) {
                               (gameInfo->config.resolution)--;
                        } else if (i == 2) {  // Botón de flecha derecha
                            if (gameInfo->config.resolution<6) {
                                (gameInfo->config.resolution)++;
                        }else if (i == 3) { // APLICAR RESOLUCION;
                         gameInfo->config.resolution=gameInfo->config.resolution;
                        } 
                        }
                    }
                    controls->click = 0; // Resetear el estado del clic
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}

void handleGameStateButtonsSettings(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls) {
    if (controls->click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {

                    GAMESTATE currentState = *gameState;
                    // Verifica si la acción es válida antes de ejecutarla
                    if (buttons[i].action != ACTION_NONE) { // Cambié NULL por ACTION_NONE
                        *gameState = buttons[i].action;
                    }
                    handleExitStates(currentState, gameState);
                    controls->click = 0; // Resetear el estado del clic
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}