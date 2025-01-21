#ifndef MAP_H
#define MAP_H


void initializeMap(GAMEINFO* gameInfo);

void allocateTerritories(GAMEINFO* gameInfo);
void initializeTerritories(GAMEINFO* gameInfo);

void loadMapMask(SDL_Renderer *renderer, ASSETS loadedAssets, CAMERA camera, int currentMapID);

void freeTerritories(MAPINFO* mapInfo);

#endif