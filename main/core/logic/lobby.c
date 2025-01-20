#include <global.h>

#include <controls.h>
#include <assets_utils.h>
#include <render.h>
#include <menu.h>

#include <lobby.h>



void handlePlayerButtons(BUTTON buttons[], int buttonCount, GAMEINFO gameInfo, CONTROLS controls) {
    int i = 0;
    if (controls.click == 1) {
        for (i = 0; buttonCount > i; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;

                // Verificar si el clic está dentro del área del botón
                if (controls.coords[0] >= rect.x &&
                    controls.coords[0] <= rect.x + rect.w &&
                    controls.coords[1] >= rect.y &&
                    controls.coords[1] <= rect.y + rect.h) {
                    
                    // Procesar la acción asociada al botón
                    switch (i) {
                        case 0: // Botón para agregar jugadores
                            if (gameInfo.numPlayers < MAX_PLAYERS) {
                                gameInfo.numPlayers++;
                                printf("Número de jugadores incrementado a %d\n", gameInfo.numPlayers);
                            } else {
                                printf("Límite máximo de jugadores alcanzado.\n");
                            }
                            break;

                        case 1: // Botón para eliminar jugadores
                            if (gameInfo.numPlayers > MIN_PLAYERS) {
                                gameInfo.numPlayers--;
                                printf("Número de jugadores reducido a %d\n", gameInfo.numPlayers);
                            } else {
                                printf("Límite mínimo de jugadores alcanzado.\n");
                            }
                            break;

                        case 2: // Botón de flecha izquierda (cambiar mapa hacia atrás)
                            gameInfo.currentMapID = (gameInfo.currentMapID == 0)
                                ? gameInfo.numMaps - 1
                                : gameInfo.currentMapID - 1;
                            printf("Mapa cambiado a índice %d\n", gameInfo.currentMapID);
                            break;

                        case 3: // Botón de flecha derecha (cambiar mapa hacia adelante)
                            gameInfo.currentMapID = (gameInfo.currentMapID + 1) % gameInfo.numMaps;
                            printf("Mapa cambiado a índice %d\n", gameInfo.currentMapID);
                            break;

                        default:
                            printf("Acción no definida para el botón %d\n", i);
                            break;
                    }

                    // Reiniciar el clic para evitar múltiples activaciones
                    controls.click = 0;
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}


void handleGameStateButtons(BUTTON buttons[], int buttonCount, GAMESTATE *gameState, CONTROLS controls) {
    if (controls.click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls.coords[0] >= rect.x &&
                    controls.coords[0] <= rect.x + rect.w &&
                    controls.coords[1] >= rect.y &&
                    controls.coords[1] <= rect.y + rect.h) {

                    GAMESTATE currentState = *gameState;
                    // Verifica si la acción es válida antes de ejecutarla
                    if (buttons[i].action != ACTION_NONE) { // Cambié NULL por ACTION_NONE
                        *gameState = buttons[i].action;
                    }
                    handleExitStates(currentState, gameState);
                    controls.click = 0; // Resetear el estado del clic
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}




