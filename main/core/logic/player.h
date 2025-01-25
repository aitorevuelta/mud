#ifndef PLAYER_H
#define PLAYER_H

#define MAX_PLAYERS 4
#define MIN_PLAYERS 2

void allocatePlayers(GAMEINFO *gameInfo);
PLAYER initializePlayer(int id);
void initializePlayers(GAMEINFO *gameInfo);
void freePlayers(GAMEINFO* gameInfo);

#endif 