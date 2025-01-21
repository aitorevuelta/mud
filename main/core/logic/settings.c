#include <global.h>

#include <controls.h>
#include <assets_utils.h>
#include <settings_utils.h>
#include <render.h>
#include <menu.h>

#include <settings.h>

void handleSettingsButtons(BUTTON buttons[], int buttonCount, CONTROLS controls, CONFIG* config, GAMESTATE* gameState) {
    static Uint32 lastClickTime = 0;
    Uint32 currentTime = SDL_GetTicks();

    if (controls.click == 1 && (currentTime - lastClickTime > 200)) { // 200 ms debounce time
        lastClickTime = currentTime;
        controls.click = 0;
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;

                // Verificar si el clic está dentro del área del botón
                if (controls.coords[0] >= rect.x &&
                    controls.coords[0] <= rect.x + rect.w &&
                    controls.coords[1] >= rect.y &&
                    controls.coords[1] <= rect.y + rect.h) {

                        // Lógica de configuración
                        if (buttons[i].action == ACTION_NONE) {
                        if (i == 1) { // Botón de flecha izquierda
                            if (config->current_res > 1) {
                                (config->current_res)--;
                            }
                        } else if (i == 2) { // Botón de flecha derecha
                            if (config->current_res < 6) {
                                (config->current_res)++;
                            }
                        } else if (i == 3) { // Aplicar resolución
                            config->current_res = config->current_res; // Placeholder para lógica de aplicación
                            config->volume=config->selectedVolume*20;
                            Mix_VolumeMusic(config->volume);
                            saveConfig(*config);
                            applyResolution(config->current_res);
                        }
                        else if (i == 4) { // Botón de subiir volumen
                            if (config->selectedVolume <5) {
                                (config->selectedVolume)++;
                            }
                        } else if (i == 5) { // Botón de bajar volumen
                            if (config->selectedVolume >0) {
                                (config->selectedVolume)--;
                            }
                        } 
                        }

                    if (gameState != NULL) {
                        // Lógica de cambio de estado del juego
                        GAMESTATE currentState = *gameState;
                        if (buttons[i].action != ACTION_NONE) { // Cambié NULL por ACTION_NONE
                            *gameState = buttons[i].action;
                        }
                        handleExitStates(currentState, gameState);
                    }

                    // Reiniciar el clic para evitar múltiples activaciones
                    controls.click = 0;
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}