#ifndef MENU_H
#define MENU_H

#include <global.h>
#include <controls.h>

void handleExitStates(GAMESTATE currentState, GAMESTATE *newState);
void handleMenuEvents(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls);


#endif // MENU_H
