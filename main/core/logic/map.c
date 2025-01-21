#include <global.h>

#include <game.h>

#include <map.h>


void loadMapMask(SDL_Renderer *renderer, ASSETS loadedAssets, CAMERA camera, int currentMapID) {
    if (!renderer) return;
    
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    float mapWidth = 200.0f * camera.zoom;
    float mapX = ((float)camera.pos[0] / windowWidth * 100.0f);
    float mapY = ((float)camera.pos[1] / windowHeight * 100.0f);

    renderTextureRelative(renderer, 
                         loadedAssets.images[1].texture, 
                         mapWidth, 
                         mapX, 
                         mapY);
}

void checkMapTerritoryClick ();

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