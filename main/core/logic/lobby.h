#ifndef LOBBY_H
#define LOBBY_H

#include <global.h>
#include <controls.h>


void handleGameStateButtons(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls);
void handlePlayerButtons(BUTTON *buttons, int buttonCount, GAMEINFO *gameInfo, CONTROLS *controls);


#endif // SETTINGS_H