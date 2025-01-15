#ifndef GAME_H
#define GAME_H

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 4


void game(GAMEINFO *gameInfo);
void updateGame(GAMEINFO *gameInfo);
void game_over(GAMEINFO *gameInfo);

// Jokoa hasieratu

void allocateTerritories(GAMEINFO *gameInfo); // malloc territorioak
void allocatePlayers(GAMEINFO *gameInfo); // malloc jokalariak
void initializeTerritories(GAMEINFO *gameInfo); // territorioak hasieratu
void initializePlayer(PLAYER *player, int id); // jokalari bat hasieratu
void initializePlayers(GAMEINFO *gameInfo); // jokalariak hasieratu



void initialize_game(GAMEINFO *gameInfo);

void handleTurn(GAMEINFO *gameInfo);

void cleanup_game(GAMEINFO *gameInfo);



// Memoria Hustu
void freeTerritories(GAMEINFO *gameInfo);
void freePlayers(GAMEINFO *gameInfo);
void cleanup_game(GAMEINFO *gameInfo);

#endif // GAME_H