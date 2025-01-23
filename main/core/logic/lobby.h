#ifndef LOBBY_H
#define LOBBY_H

typedef enum {
    ADD_PLAYER = 0,
    REMOVE_PLAYER,
    PREV_MAP,
    NEXT_MAP,
} LOBBY_BUTTONS; // lobby botoien enum-a


void handleLobbyButtons(BUTTON buttons[], int buttonCount, GAMEINFO *gameInfo, GAMESTATE *gameState, CONTROLS controls);
void adjustPlayerCount(GAMEINFO* gameInfo, int change);
void adjustMapID(GAMEINFO* gameInfo, int direction);

#endif // SETTINGS_H