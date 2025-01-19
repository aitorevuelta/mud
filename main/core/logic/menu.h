#ifndef MENU_H
#define MENU_H


void handleExitStates(GAMESTATE currentState, GAMESTATE *newState);
void handleMenuEvents(BUTTON buttons[], int buttonCount, GAMESTATE *gameState, CONTROLS controls);




#endif // MENU_H
