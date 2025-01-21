#ifndef MAP_H
#define MAP_H


void initializeMap(MAPINFO* mapInfo, PLAYER* players, int numPlayers, int totalTerritories);

void allocateTerritories(MAPINFO* mapInfo, PLAYER* players, int numPlayers, int totalTerritories);
void initializeTerritories(MAPINFO* mapInfo, int totalTerritories);

void loadMapMask(SDL_Renderer *renderer, ASSETS loadedAssets, CAMERA camera, int currentMapID);

void shuffleTerritories(TERRITORYINFO* territories, int numTerritories);

void checkMapTerritoryClick(MAPINFO* mapInfo, int mouseX, int mouseY);

void freeTerritories(MAPINFO* mapInfo);

void renderTerritories(SDL_Renderer *renderer, MAPINFO *mapInfo, PLAYER *players);
void changeTerritoryOwner(TERRITORYINFO *territory, PLAYER *newOwner);
void handleTerritoryAttack(TERRITORYINFO *territory, PLAYER *attacker, PLAYER *defender);

#endif