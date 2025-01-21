#include <global.h>
#include <controls.h>
#include <assets_utils.h>
#include <render.h>
#include <menu.h>
#include <lobby.h>

void handleLobbyButtons(BUTTON buttons[], int buttonCount, GAMEINFO *gameInfo, GAMESTATE *gameState, CONTROLS controls) {
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
                    
                    // Procesar la acción asociada al botón
                    switch (i) {
                        case 0: // Botón para agregar jugadores
                            if (gameInfo->numPlayers < MAX_PLAYERS) {
                                gameInfo->numPlayers++;
                                printf("Jokalari kopurua %d\n", gameInfo->numPlayers);
                            } else printf("Jokalari kopurua %d\n", gameInfo->numPlayers);
                            break;
                        case 1: // Botón para eliminar jugadores
                            if (gameInfo->numPlayers > MIN_PLAYERS) {
                                gameInfo->numPlayers--;
                                 printf("Jokalari kopurua %d\n", gameInfo->numPlayers);
                            } else printf("Jokalari kopurua %d\n", gameInfo->numPlayers);
                            break;
                        case 2: // Botón de flecha izquierda (cambiar mapa hacia atrás)
                            gameInfo->currentMapID = (gameInfo->currentMapID == 0)
                                ? gameInfo->numMaps - 1
                                : gameInfo->currentMapID - 1;
                            break;
                        case 3: // Botón de flecha derecha (cambiar mapa hacia adelante)
                            gameInfo->currentMapID = (gameInfo->currentMapID + 1) % gameInfo->numMaps;
                            break;
                        default:
                            break;
                    }
                    // Verifica si la acción es válida antes de ejecutarla
                    if (gameState != NULL && buttons[i].action != ACTION_NONE) {
                        GAMESTATE currentState = *gameState;
                        *gameState = buttons[i].action;
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

void loadGameInfo(GAMEINFO* gameInfo) {
    gameInfo->numPlayers = 2;
    gameInfo->currentMapID = 1;
    gameInfo->numMaps = NUM_MAPS;
    gameInfo->camera.pos[0] = windowWidth / 2;
    gameInfo->camera.pos[1] = windowHeight / 2;
    gameInfo->camera.zoom = 1.0f;
    gameInfo->turn = 0;
    gameInfo->elapsedTime = 0;
    gameInfo->round = 1;
}