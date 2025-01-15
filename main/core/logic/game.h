#ifndef GAME_H
#define GAME_H

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 4


void game(GAMEINFO *gameInfo);
void updateGame(GAMEINFO *gameInfo);

// Jokoa hasieratu
void allocateTerritories(GAMEINFO *gameInfo);
void allocatePlayers(GAMEINFO *gameInfo);

void initializePlayer(PLAYER *player, int id);
void initializePlayers(GAMEINFO *gameInfo);

void initializeTerritories(GAMEINFO *gameInfo);

void initialize_game(GAMEINFO *gameInfo);

void handleTurn(GAMEINFO *gameInfo);

void cleanup_game(GAMEINFO *gameInfo);



// Memoria Hustu
void freeTerritories(GAMEINFO *gameInfo);
void freePlayersAndCards(GAMEINFO *gameInfo);
void cleanup_game(GAMEINFO *gameInfo);

#endif // GAME_H