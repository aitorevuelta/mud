#ifndef GAME_H
#define GAME_H

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 4



void game_init(GAMEINFO *gameInfo);
void allocatePlayers(GAMEINFO *gameInfo);
PLAYER initializePlayer(int id);
void initializePlayers(GAMEINFO *gameInfo);


void freePlayers(GAMEINFO *gameInfo);


#endif // GAME_H