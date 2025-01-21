#include <global.h>


#include <assets_utils.h>
#include <buttons_utils.h>
#include <controls.h>
#include <render.h>
#include <menu.h>

#include <lobby.h>

void handleLobbyButtons(BUTTON buttons[], int buttonCount, GAMEINFO *gameInfo, GAMESTATE *gameState, CONTROLS controls) {
    int i = 0;
    static Uint32 lastClickTime = 0;
    Uint32 currentTime = SDL_GetTicks();

    if (controls.click == 1 && (currentTime - lastClickTime > 200)) { // 200 ms debounce time
        lastClickTime = currentTime;
        controls.click = 0;
        for (i = 0; buttonCount > i; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (isClickInsideButton(control.coords, rect)) {
                    switch (i) {
                        case ADD_PLAYER:
                            
                            break;
                        case REMOVE_PLAYER:
                            if (gameInfo->numPlayers > MIN_PLAYERS) {
                                gameInfo->numPlayers--;
                            } else printf("Jokalari kopurua %d\n", gameInfo->numPlayers);
                            break;
                        case PREV_MAP: 
                            if (gameInfo->currentMapID > 1) {
                                gameInfo->currentMapID--;
                            } else if(gameInfo->currentMapID == 1){
                                gameInfo->currentMapID=NUM_MAPS;
                            }
                            break;
                        case NEXT_MAP:
                            if (gameInfo->currentMapID < NUM_MAPS) {
                                gameInfo->currentMapID++;
                            } else if(gameInfo->currentMapID == NUM_MAPS){
                                gameInfo->currentMapID=1;
                            }
                            break;
                        default:
                            break;
                    }

                    if (gameState != NULL && buttons[i].action != ACTION_NONE && gameInfo->currentMapID==1) {
                        GAMESTATE currentState = *gameState;
                        *gameState = buttons[i].action;
                        handleExitStates(currentState, gameState);  
                    }


                    controls.click = 0;
                    return;
                }
            }
        }
    }
}

void adjustMapID(GAMEINFO* gameInfo, int direction) {
    if (direction > 0) {
        gameInfo->currentMapID = (gameInfo->currentMapID % NUM_MAPS) + 1;
    } else if (direction < 0) {
        gameInfo->currentMapID = (gameInfo->currentMapID - 2 + NUM_MAPS) % NUM_MAPS + 1;
    }
    printf("Mapa actual: %d\n", gameInfo->currentMapID);
}