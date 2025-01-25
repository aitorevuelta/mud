#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <controls.h>
#include <render.h>
#include <menu.h>

#include <lobby.h>

void handleLobbyButtons(BUTTON buttons[], int buttonCount, GAMEINFO *gameInfo, GAMESTATE *gameState, CONTROLS controls) { // botoiak kudeatu
    int i = 0;
    static Uint32 lastClickTime = 0;
    Uint32 currentTime = SDL_GetTicks();

    if (controls.click == 1 && isClickAllowed(&lastClickTime, 200)) {
        controls.click = 0;
        for (i = 0; buttonCount > i; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (isClickInsideButton(controls.coords, rect)) {
                    switch (i) {
                        case ADD_PLAYER:
                            adjustPlayerCount(gameInfo, 1);
                            break;
                        case REMOVE_PLAYER:
                            adjustPlayerCount(gameInfo, -1);
                            break;
                        case PREV_MAP:
                            adjustMapID(gameInfo, -1);
                            break;
                        case NEXT_MAP:
                            adjustMapID(gameInfo, 1);
                            break;
                        default:
                            break;
                    }

                    if (gameState != NULL && buttons[i].action == ACTION_GAME  && gameInfo->currentMapID==1) {
                        GAMESTATE currentState = *gameState;
                        *gameState = buttons[i].action;
                        handleExitStates(currentState, gameState);  
                    }else if (gameState != NULL && buttons[i].action == ACTION_EXIT) {
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

// jokalarien kopurua aldatzeko funtzioa
void adjustPlayerCount(GAMEINFO* gameInfo, int change) { //
    if (change > 0 && gameInfo->numPlayers < MAX_PLAYERS) {
        gameInfo->numPlayers++;
    } else if (change < 0 && gameInfo->numPlayers > MIN_PLAYERS) {
        gameInfo->numPlayers--;
    }
}

// maparen IDa aldatzeko funtzioa
void adjustMapID(GAMEINFO* gameInfo, int direction) {
    if (direction > 0) {
        gameInfo->currentMapID = (gameInfo->currentMapID % NUM_MAPS) + 1;
    } else if (direction < 0) {
        gameInfo->currentMapID = (gameInfo->currentMapID - 2 + NUM_MAPS) % NUM_MAPS + 1;
    }
}