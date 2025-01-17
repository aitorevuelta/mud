#include <global.h>
#include <assets_utils.h>
#include <settings_utils.h>
#include <menu.h>
#include <render.h>
#include <settings.h>


void handleSettingsButtons(BUTTON *buttons, int buttonCount, GAMEINFO *gameInfo, CONTROLS *controls,GAMESTATE *gameState, SDL_Window *window) {
    
    if (controls->click == 1) {
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {

                    // Botón de flecha izquierda
                    if (i == 1) {
                        if (gameInfo->config.resolution == 1) {
                            gameInfo->config.resolution = gameInfo->config.totalRes;
                        } else {
                            gameInfo->config.resolution--;
                        }
                    } 
                    // Botón de flecha derecha
                    else if (i == 2) {
                        if (gameInfo->config.resolution == gameInfo->config.totalRes) {
                            gameInfo->config.resolution = 1;
                        } else {
                            gameInfo->config.resolution++;
                        }
                    }
                    else if( i == 3){ //BOTON DE APLICAR, DENTRO REVISA LA RESOLUCION, EL VOLUMEN Y APLICA LOS CAMBIOS
                        switch (gameInfo->config.resolution) {
                            case 1:
                                gameInfo->config.window_width = 800;
                                gameInfo->config.window_height = 600;
                                SDL_SetWindowFullscreen(window, 0);                                
                                break;
                            case 2:
                                gameInfo->config.window_width = 1024;
                                gameInfo->config.window_height = 768;
                                SDL_SetWindowFullscreen(window, 0);   
                                break;
                            case 3:
                                gameInfo->config.window_width = 1280;
                                gameInfo->config.window_height = 720;
                                SDL_SetWindowFullscreen(window, 0);   
                                break;
                            case 4:
                                gameInfo->config.window_width = 1366;
                                gameInfo->config.window_height = 768;
                                SDL_SetWindowFullscreen(window, 0);
                                break;
                            case 5:
                                gameInfo->config.window_width = 1600;
                                gameInfo->config.window_height = 900;
                                SDL_SetWindowFullscreen(window, 0);
                                break;
                            case 6:
                                gameInfo->config.window_width = 1920;
                                gameInfo->config.window_height = 1080;
                                SDL_SetWindowFullscreen(window, 0);
                                break;
                            case 7:
                                gameInfo->config.window_width = 1366;
                                gameInfo->config.window_height = 768;
                                SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);
                        }
                        
                        switch (gameInfo->config.selectedVolume){
                        case 0:
                            gameInfo->config.volume = 0;
                            break;
                        case 1:
                            gameInfo->config.volume = 20;
                            break;
                        case 2:
                            gameInfo->config.volume = 40;
                            break;
                        case 3:
                            gameInfo->config.volume = 60;
                            break;
                        case 4:
                            gameInfo->config.volume = 80;
                            break;
                        case 5:
                            gameInfo->config.volume = 100;
                            break;
                        }
                        gameInfo->config.max_FPS = 60;

                        saveConfig(gameInfo->config);
                        SDL_SetWindowSize(window, gameInfo->config.window_width, gameInfo->config.window_height);
                        SDL_SetWindowPosition(window, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
                    }
                    else if (i == 4 && gameInfo->config.selectedVolume < 5) { // Subir volumen
                        (gameInfo->config.selectedVolume)++;
                    } else if (i == 5 && gameInfo->config.selectedVolume > 0) { // Bajar volumen
                        (gameInfo->config.selectedVolume)--;
                    }

                    // Cambiar el estado del juego solo si el botón tiene una acción válida
                    if (buttons[i].action != ACTION_NONE) {
                        GAMESTATE currentState = *gameState;
                        *gameState = buttons[i].action;

                        // Manejar estados de salida, si es necesario
                        handleExitStates(currentState, gameState);
                    }

                    controls->click = 0; // Resetear el clic
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}
