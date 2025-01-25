#ifndef PLAYER_H
#define PLAYER_H


void allocatePlayers(GAMEINFO *gameInfo);
PLAYER initializePlayer(int id);
void initializePlayers(GAMEINFO *gameInfo);
void freePlayers(GAMEINFO* gameInfo);

#endif 