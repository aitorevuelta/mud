#ifndef MAP_H
#define MAP_H


void initializeMap(MAPINFO* mapInfo, PLAYER* players, int numPlayers);

void allocateTerritories(MAPINFO* mapInfo, PLAYER* players, int numPlayers);
void initializeTerritories(MAPINFO* mapInfo);

void loadMapMask(SDL_Renderer *renderer, ASSETS loadedAssets, CAMERA camera, int currentMapID);

void shuffleTerritories(TERRITORYINFO* territories, int numTerritories);

void checkMapTerritoryClick(MAPINFO* mapInfo, int mouseX, int mouseY);

void freeTerritories(MAPINFO* mapInfo);

#endif