#include <global.h>
#include <controls.h>
#include <lobby.h>
#include <assets_utils.h>
#include <render.h>
#include <lobby_render.h>

void handleGameStateButtons(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls) {
    if (controls->click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {
                    
                    *gameState = buttons[i].action;
                    controls->click = 0; // Resetear el estado del clic
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}

void handlePlayerButtons(BUTTON_JUEGO *buttons_juego, int buttonCount, GAMEINFO *gameInfo,CONTROLS *controls,SDL_Renderer *renderer, IMAGES *loadedImages) {
    if (controls->click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons_juego[i].visible) {
                SDL_Rect rect = buttons_juego[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {
                    
                    if (i == 0 && gameInfo->numPlayers < 4) {  // Añadir jugador
                        (gameInfo->numPlayers)++;
                    } else if (i == 1 && gameInfo->numPlayers > 2) {  // Eliminar jugador
                        (gameInfo->numPlayers)--;
                    } else if (i == 2 && gameInfo->mapInfo.numMaps > 1) {  // Botón de flecha izquierda
                        gameInfo->mapInfo.numMaps--;
                    } else if (i == 3 && gameInfo->mapInfo.numMaps < gameInfo->mapInfo.totalMaps) {  // Botón de flecha derecha
                        gameInfo->mapInfo.numMaps++;
                    }
                    controls->click = 0; // Resetear el estado del clic
                    

                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}