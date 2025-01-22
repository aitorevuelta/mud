#include <global.h>
#include <game.h>
#include <render.h>
#include <map.h>

// Función para renderizar los territorios con el color del dueño
void renderTerritories(SDL_Renderer *renderer, MAPINFO *mapInfo, PLAYER *players) {
    for (int i = 0; i < mapInfo->numTerritories; i++) {
        TERRITORYINFO *territory = &mapInfo->territories[i];
        PLAYER *owner = &players[territory->ownerID];

        // Establecer el color del territorio basado en el color del dueño
        SDL_SetRenderDrawColor(renderer, owner->playerColor.r, owner->playerColor.g, owner->playerColor.b, 255);

        // Dibujar el territorio como un círculo
        for (int w = 0; w < territory->radius * 2; w++) {
            for (int h = 0; h < territory->radius * 2; h++) {
                int dx = territory->radius - w; // horizontal offset
                int dy = territory->radius - h; // vertical offset
                if ((dx * dx + dy * dy) <= (territory->radius * territory->radius)) {
                    SDL_RenderDrawPoint(renderer, territory->center[0] + dx, territory->center[1] + dy);
                }
            }
        }
    }
}

// Función para manejar el cambio de dueño de un territorio
void changeTerritoryOwner(TERRITORYINFO *territory, PLAYER *newOwner) {
    territory->ownerID = newOwner->id;
    // Aquí puedes agregar lógica adicional si es necesario
}

// Función para manejar el ataque y cambio de dueño de un territorio
void handleTerritoryAttack(TERRITORYINFO *territory, PLAYER *attacker, PLAYER *defender) {
    if (territory->troops <= 0) {
        changeTerritoryOwner(territory, attacker);
        printf("Territory %s conquered by Player %d!\n", territory->name, attacker->id);
    }
}

void loadMapMask(SDL_Renderer *renderer, ASSETS loadedAssets, CAMERA camera, int currentMapID, RESOLUTION resolution) {
    if (!renderer) return;

    float mapWidth = 200.0f * camera.zoom;
    float mapX = ((float)camera.pos[0] / resolution.height * 100.0f);
    float mapY = ((float)camera.pos[1] / resolution.width * 100.0f);

    renderTextureRelative(renderer, 
                        loadedAssets.images[1].texture, 
                        mapWidth, 
                        mapX, 
                        mapY);
}

void checkMapTerritoryClick(MAPINFO* mapInfo, int mouseX, int mouseY) {
int i = 0;
    for (i = 0; i < mapInfo->numTerritories; i++) {
        TERRITORYINFO* territory = &mapInfo->territories[i];
        int dx = mouseX - territory->center[0];
        int dy = mouseY - territory->center[1];

        // Verificar si el clic está dentro del círculo
        if ((dx * dx + dy * dy) <= (territory->radius * territory->radius)) {
            printf("Territory %s selected!\n", territory->name);
            territory->isSelected = true; // Marcar como seleccionado
            return;
        }
    }
    printf("No territory selected.\n");
}

void shuffleTerritories(TERRITORYINFO* territories, int numTerritories) {
    int i = 0;
    if (!territories || numTerritories <= 1) return;

    srand((unsigned int)time(NULL)); // Inicializar semilla aleatoria

    for ( i = numTerritories - 1; i > 0; i--) {
        int j = rand() % (i + 1); // Índice aleatorio
        TERRITORYINFO temp = territories[i];
        territories[i] = territories[j];
        territories[j] = temp;
    }
}

void allocateTerritories(MAPINFO* mapInfo, PLAYER* players, int numPlayers, int totalTerritories) {
    if (!mapInfo || !players || numPlayers == 0) return;

    int numTerritories = totalTerritories;
    if (numTerritories == 0) return;

    // Barajar territorios
    shuffleTerritories(mapInfo->territories, numTerritories);

    // Asignar territorios de forma equitativa
    int territoriesPerPlayer = numTerritories / numPlayers;
    for (int i = 0; i < numPlayers; i++) {
        players[i].numTerritories = 0;

        for (int j = 0; j < territoriesPerPlayer; j++) {
            int index = i * territoriesPerPlayer + j;
            TERRITORYINFO* territory = &mapInfo->territories[index];
            territory->ownerID = i;
            territory->troops = 0;

            players[i].territories[players[i].numTerritories++] = index;
        }
    }

    // Asignar territorios sobrantes
    for (int i = 0; i < numTerritories % numPlayers; i++) {
        int index = numPlayers * territoriesPerPlayer + i;
        TERRITORYINFO* territory = &mapInfo->territories[index];
        territory->ownerID = i;
        territory->troops = 0;

        players[i].territories[players[i].numTerritories++] = index;
    }

    // Distribuir tropas
    for (int i = 0; i < numPlayers; i++) {
        int remainingTroops = 25;
        while (remainingTroops > 0) {
            int randomIndex = rand() % players[i].numTerritories;
            int territoryID = players[i].territories[randomIndex];
            TERRITORYINFO* territory = &mapInfo->territories[territoryID];

            territory->troops++;
            remainingTroops--;
        }
    }
}

void initializeTerritories(MAPINFO* mapInfo, int totalTerritories) {
    int i = 0;
    mapInfo->numTerritories = totalTerritories;
    for (i = 0; mapInfo->numTerritories > i; i++) {
        TERRITORYINFO* territory = &mapInfo->territories[i];
        territory->ownerID = -1;        
        territory->troops = 0;         
        territory->center[0] = rand() % 800; 
        territory->center[1] = rand() % 600; 
        territory->radius = 30;    
        territory->isSelected = false; 
    }
}

void initializeMap(MAPINFO* mapInfo, PLAYER* players, int numPlayers, int totalTerritories) {
    if (!mapInfo || !players) return;
    allocateTerritories(mapInfo, players, numPlayers, totalTerritories);
    initializeTerritories(mapInfo, totalTerritories);
}


void freeTerritories(MAPINFO* mapInfo) {
    if(mapInfo->territories) {
        free(mapInfo->territories);
        mapInfo->territories = NULL;
    }
}

void initializeAdjencyMatrix(MAPINFO* mapInfo) {
    int i = 0;
    mapInfo->adjMatrix = malloc(mapInfo->numTerritories * sizeof(int*));
    if(!mapInfo->adjMatrix)return;

    for(i = 0; mapInfo->numTerritories > i; i++) {
        mapInfo->adjMatrix[i] = calloc(mapInfo->numTerritories, sizeof(int));
    }
    // Territorioen konexioa
    mapInfo->adjMatrix[0][1] = 1;
}

bool isAdjacent(int territory1, int territory2, MAPINFO* mapInfo) {
    if(!mapInfo || !mapInfo->adjMatrix) return false;
    return mapInfo->adjMatrix[territory1][territory2] == 1;
}

void freeAdjencyMatrix(MAPINFO* mapInfo) {
    int i = 0;
    if(!mapInfo || !mapInfo->adjMatrix) return;
    for(i = 0; mapInfo->numTerritories > i; i++) {
        free(mapInfo->adjMatrix[i]);
    }
    free(mapInfo->adjMatrix);
}