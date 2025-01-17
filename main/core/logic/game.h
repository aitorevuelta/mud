#ifndef GAME_H
#define GAME_H

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 4

void game(GAMEINFO *gameInfo);
void handleTurn(GAMEINFO *gameInfo);
//void endTurn();

// Jokoa hasieratu

void allocateTerritories(GAMEINFO *gameInfo); // malloc territorioak
void allocatePlayers(GAMEINFO *gameInfo); // malloc jokalariak
void initializeTerritories(GAMEINFO *gameInfo); // territorioak hasieratu
PLAYER initializePlayer(PLAYER *player, int id); // jokalari bat hasieratu
void initializePlayers(GAMEINFO *gameInfo); // jokalariak hasieratu
void initialize_game(GAMEINFO *gameInfo); // hasieratu jolasa

/*
int getTerritoryOwner();
bool isAdjacent();

int calculateReinforcements();
void placeReinforcements();

bool canAttack();
int rollDice();
void resolveComabt();
void conquerTerritory();

bool canFortify();
void moveTroops();

bool checkVictoryCondition();
*/


// Memoria Hustu
void cleanup_game(GAMEINFO *gameInfo);
void freeTerritories(GAMEINFO *gameInfo); 
void freePlayers(GAMEINFO *gameInfo);


#endif // GAME_H