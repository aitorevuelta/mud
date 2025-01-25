#ifndef GAME_H
#define GAME_H





GAMEINFO loadGameInfo();

void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo, RESOLUTION resolution); // jokoaren datuak hasieratzen ditu

void update_game(GAMEINFO *gameInfo); // jokoa eguneratzen du
void handleTurn(GAMEINFO *gameInfo);    // jokalarien txanda kudeatzen du
void handlePhase(GAMEINFO* gameInfo); // jokalarien faseak kudeatzen ditu




TERRITORYINFO* findEnemyTerritory(int attackerID, MAPINFO* mapInfo, PLAYER* currentPlayer);
void performBattle(TERRITORYINFO* attacker, TERRITORYINFO* defender, PLAYER* currentPlayer);



void moveTroops(TERRITORYINFO* source, TERRITORYINFO* target);
TERRITORYINFO* selectRandomTarget(MAPINFO* mapInfo, PLAYER* currentPlayer);






// hainbat funtzio eginda daude, baina jokoaren logikan inplementatzea falta da

void deployTroopsPhase(GAMEINFO* gameInfo); // 1. FASEA: jokalariak tropak kokatzen ditu
void attackPhase(GAMEINFO* gameInfo); // 2. FASEA: jokalariak erasotzen ditu
void reinforcePhase(GAMEINFO* gameInfo); // 3. FASEA: jokalariak tropak mugitzen ditu

bool checkGameOver(GAMEINFO* gameInfo); // jokoa amaitu den ala ez egiaztatzen du

#endif // GAME_H