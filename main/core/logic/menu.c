#include <global.h>

#include <controls.h>

#include <menu.h>



void handleExitStates(GAMESTATE currentState, GAMESTATE *newState) {
    if (*newState == EXIT) {
        switch (currentState) {
            case MAIN_MENU:
                *newState = EXIT_TOTAL;
                break;
            case HOWTOPLAY:
            case SETTINGS:
            case CREDITS:
            case LOBBY:
                *newState = MAIN_MENU;
            case GAME:
            *newState = EXIT_TOTAL;
                break;
            default:
                *newState = MAIN_MENU;
        }   
    }
}


void handleMenuEvents(BUTTON buttons[], int buttonCount, GAMESTATE *gameState, CONTROLS controls) {
    int i = 0;
    if (controls.click == 1) {
        // Process visible buttons
        for (i = 0; buttonCount > i; i++) {
            if (buttons[i].visible) {
                SDL_Rect rect = buttons[i].rect;
                if (controls.coords[0] >= rect.x &&
                    controls.coords[0] <= rect.x + rect.w &&
                    controls.coords[1] >= rect.y &&
                    controls.coords[1] <= rect.y + rect.h) {
                    
                    GAMESTATE currentState = *gameState;
                    *gameState = buttons[i].action;
                    handleExitStates(currentState, gameState);
                    
                    controls.click = 0;
                    return;
                }
            }
        }
    }
}

