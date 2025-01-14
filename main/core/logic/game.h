#ifndef GAME_H
#define GAME_H



// Jokoa hasieratu
void allocateTerritories(GAMEINFO *gameInfo);
void allocatePlayers(GAMEINFO *gameInfo);
void initializeBasicData(GAMEINFO *gameInfo);
void initialize_game(GAMEINFO *gameInfo);

void handleTurn(GAMEINFO *gameInfo);


// Memoria Hustu
void freeTerritories(GAMEINFO *gameInfo);
void freePlayers(GAMEINFO *gameInfo);
void cleanup_game(GAMEINFO *gameInfo);

#endif // GAME_H