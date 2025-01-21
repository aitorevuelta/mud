#ifndef MAP_H
#define MAP_H


void initializeMap(GAMEINFO* gameInfo);

void allocateTerritories(GAMEINFO* gameInfo);
void initializeTerritories(GAMEINFO* gameInfo);


void freeTerritories(MAPINFO* mapInfo);

#endif