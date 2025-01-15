#include <global.h>

#include <controls.h>
#include <assets_utils.h>
#include <render.h>
#include <menu.h>

#include <lobby.h>

void handlePlayerButtons(BUTTON *buttons, int buttonCount, GAMEINFO *gameInfo, CONTROLS *controls) {
    if (controls->click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {

                    // Verifica si la acción es válida antes de ejecutarla
                    if (buttons[i].action == ACTION_NONE) { // Cambié NULL por ACTION_NONE
                        if (i == 0 && gameInfo->numPlayers < 4) {  // Jokalariak gehitu
                            (gameInfo->numPlayers)++;
                        } else if (i == 1 && gameInfo->numPlayers > 2) {  // Jokalariak kendu
                            (gameInfo->numPlayers)--; 
                        } else if (i == 2) {  // Botón de flecha izquierda
                            if (gameInfo->mapInfo.numMaps == 1) {
                                gameInfo->mapInfo.numMaps = gameInfo->mapInfo.totalMaps;
                            } else {
                                gameInfo->mapInfo.numMaps--;
                            }
                        } else if (i == 3) {  // Botón de flecha derecha
                            if (gameInfo->mapInfo.numMaps == gameInfo->mapInfo.totalMaps) {
                                gameInfo->mapInfo.numMaps = 1;
                            } else {
                                gameInfo->mapInfo.numMaps++;
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

void handleGameStateButtons(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls) {
    if (controls->click == 1) {
        for (int i = 4; i < buttonCount; i++) {
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