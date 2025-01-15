#ifndef LOBBY_H
#define LOBBY_H


void handleGameStateButtons(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls);
void handlePlayerButtons(BUTTON *buttons, int buttonCount, GAMEINFO *gameInfo, CONTROLS *controls, SDL_Renderer *renderer, IMAGES *loadedImages);

#endif // SETTINGS_H