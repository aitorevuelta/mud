#include <global.h>

#include <game.h>

#include <map.h>


void allocateTerritories(GAMEINFO* gameInfo) {

}


void initializeTerritories(MAPINFO* mapInfo) {
    int i = 0;
    for(i = 0; mapInfo->numTerritories > i; i++) {

    }
}

void initializeMap(GAMEINFO* gameInfo){

}

void freeTerritories(MAPINFO* mapInfo) {
    if(mapInfo->territories) {
        free(mapInfo->territories);
        mapInfo->territories = NULL;
    }
}   