#ifndef GAME_H
#define GAME_H


#define TERRITORY_COUNT 23
#define DEFAULT_TROOPS_COUNT 25
#define MAX_PLAYERS 4


GAMEINFO loadGameInfo();


void update_game(GAMEINFO *gameInfo);
void handleTurn(GAMEINFO *gameInfo);
void handlePhase(GAMEINFO* gameInfo);


void deployTroopsPhase(GAMEINFO* gameInfo);
void attackPhase(GAMEINFO* gameInfo);
void reinforcePhase(GAMEINFO* gameInfo);


TERRITORYINFO* findEnemyTerritory(int attackerID, MAPINFO* mapInfo, PLAYER* currentPlayer);
void performBattle(TERRITORYINFO* attacker, TERRITORYINFO* defender, PLAYER* currentPlayer);



void moveTroops(TERRITORYINFO* source, TERRITORYINFO* target);
TERRITORYINFO* selectRandomTarget(MAPINFO* mapInfo, PLAYER* currentPlayer);

void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo, RESOLUTION resolution);


bool checkGameOver(GAMEINFO* gameInfo);


#endif // GAME_H3