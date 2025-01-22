#ifndef LOBBY_H
#define LOBBY_H

typedef enum {
    ADD_PLAYER = 0,
    REMOVE_PLAYER,
    PREV_MAP,
    NEXT_MAP,
} LOBBY_BUTTONS;



void handleLobbyButtons(BUTTON buttons[], int buttonCount, GAMEINFO *gameInfo, GAMESTATE *gameState, CONTROLS controls);
void adjustPlayerCount(int numPlayers, int change);
void adjustMapID(int currentMapID, int direction);

#endif // SETTINGS_H