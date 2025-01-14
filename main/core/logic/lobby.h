#ifndef LOBBY_H
#define LOBBY_H

#include <global.h>
#include <controls.h>
#include <lobby.h>
#include <assets_utils.h>
#include <render.h>

void handleGameStateButtons(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls);
void handlePlayerButtons(BUTTON_JUEGO *buttons_juego, int buttonCount, GAMEINFO *gameInfo,CONTROLS *controls,SDL_Renderer *renderer, IMAGES *loadedImages);

#endif // SETTINGS_H