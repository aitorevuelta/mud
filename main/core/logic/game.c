#include <global.h>

#include <assets_utils.h>


#include <map.h>
#include <player.h>

#include <game.h>



GAMEINFO loadGameInfo() {
    GAMEINFO info = {0};
    
    info.currentMapID = 1;
    info.numMaps = NUM_MAPS;
    info.numPlayers = 2;
    info.totalTerritories= TERRITORY_COUNT;
    

    return info;
}


void update_game(GAMEINFO *gameInfo) {

    handleTurn(gameInfo);
}

static Uint32 lastUpdateTime = 0;

void handleTurn(GAMEINFO *gameInfo) {
    if (!gameInfo) return;
    
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastUpdateTime) / 1000.0f;
    
    gameInfo->elapsedTime += deltaTime;

    if (gameInfo->elapsedTime >= 60.0f) {
        gameInfo->elapsedTime = 0.0f;
        
        gameInfo->turn = (gameInfo->turn + 1) % gameInfo->numPlayers;
        
        if (gameInfo->turn == 0) {
            gameInfo->round++;
        }
    }
    handlePhase(gameInfo);
    lastUpdateTime = currentTime;
}

void handlePhase(GAMEINFO* gameInfo) {
    if (!gameInfo) return;

    switch (gameInfo->phase) {
        case DEPLOY:
            deployTroopsPhase(gameInfo);
            gameInfo->phase = ATTACK; 
            break;
        case ATTACK:
            attackPhase(gameInfo);
            gameInfo->phase = REINFORCE;
            break;
        case REINFORCE:
            reinforcePhase(gameInfo);
            gameInfo->currentPlayerID = (gameInfo->currentPlayerID + 1) % gameInfo->numPlayers;
            if(gameInfo->currentPlayerID == 0) {
                gameInfo->round++; 
            }
            gameInfo->phase = DEPLOY; 
            break;
        default:
            break;
    }
}

void deployTroopsPhase(GAMEINFO* gameInfo) {
    PLAYER* currentPlayer = &gameInfo->players[gameInfo->currentPlayerID];
    MAPINFO* mapInfo = &gameInfo->maps[gameInfo->currentMapID];
    int troopsToDeploy = currentPlayer->troops;

    while (troopsToDeploy > 0) {
        TERRITORYINFO* territory = selectRandomTarget(mapInfo, currentPlayer);
        territory->troops++;
        troopsToDeploy--;
    }
    currentPlayer->troops = 0; 
}

void attackPhase(GAMEINFO* gameInfo) {
    int i = 0, j = 0;
    PLAYER* currentPlayer = &gameInfo->players[gameInfo->currentPlayerID];
    MAPINFO* mapInfo = &gameInfo->maps[gameInfo->currentMapID];

    // jokalariaren territorio guztiak aztertu
    for (i = 0; currentPlayer->numTerritories > i; i++) {
        int territoryID = currentPlayer->territories[i];
        TERRITORYINFO* attacker = &mapInfo->territories[territoryID];
        // tropa kopurua 1 baino handiagoa bada atakatu
        if (attacker->troops > 1) {
            // etsaien territorioak aztertu 
            TERRITORYINFO* defender = findEnemyTerritory(territoryID, mapInfo, currentPlayer);
            if (defender) performBattle(attacker, defender, currentPlayer);
        }
    }
}

TERRITORYINFO* findEnemyTerritory(int attackerID, MAPINFO* mapInfo, PLAYER* currentPlayer) {
    int i = 0;
    TERRITORYINFO* attacker = &mapInfo->territories[attackerID];

    for (i = 0; mapInfo->numTerritories > i; i++) {
        TERRITORYINFO* defender = &mapInfo->territories[i];
        if (isAdjacent(attackerID, i, mapInfo) && defender->ownerID != currentPlayer->id) return defender;
    }
    return NULL; 
}

void performBattle(TERRITORYINFO* attacker, TERRITORYINFO* defender, PLAYER* currentPlayer) {
    if(!attacker || !defender || !currentPlayer) return;
    if (attacker->troops <= 1) return;
    if (defender->troops <= 0) return;

    attacker->troops--;     // erasotzaileak tropa galdu
    if (rand() % 2 == 0) {
        defender->troops--;
        if (defender->troops <= 0) {
            defender->ownerID = currentPlayer->id;      // territorioaren jabea aldatu
            defender->troops = 1;       // territorioa okupatu
            attacker->troops--;     // erasotzaileak tropa galdu
        }
    } else attacker->troops--;      // erasotzaileak galdu
}

TERRITORYINFO* selectRandomTarget(MAPINFO* mapInfo, PLAYER* currentPlayer) {
    if(currentPlayer->numTerritories == 0) return NULL;
    int randomTargetID = rand() % currentPlayer->numTerritories;
    int targetTerritoryID = currentPlayer->territories[randomTargetID];
    return &mapInfo->territories[targetTerritoryID];
}

void moveTroops(TERRITORYINFO* source, TERRITORYINFO* target) {
    int troopsToMove = rand() % (source->troops - 1) + 1;
    source->troops -= troopsToMove;
    target->troops += troopsToMove;
}

void reinforcePhase(GAMEINFO* gameInfo) {
    int i = 0;
    PLAYER* currentPlayer = &gameInfo->players[gameInfo->currentPlayerID];
    MAPINFO* mapInfo = &gameInfo->maps[gameInfo->currentMapID];

    for (i = 0;currentPlayer->numTerritories > i; i++) {
        int sourceID = currentPlayer->territories[i];
        TERRITORYINFO* source = &mapInfo->territories[sourceID];
        if (source->troops > 1) {
            TERRITORYINFO* target = selectRandomTarget(mapInfo, currentPlayer);
            moveTroops(source, target);
            return; // txanda amaitu
        }
    }
}


// Inicializar

void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo, RESOLUTION resolution) {
    SDL_GetRendererOutputSize(renderer, &resolution.width, &resolution.height);
    gameInfo->camera.pos[0] = resolution.width / 2;
    gameInfo->camera.pos[1] = resolution.height / 2;
    gameInfo->camera.zoom = 1.0f;

    
    allocatePlayers(gameInfo);
    initializePlayers(gameInfo);
    allocateTerritories()
    initializeTerritories(gameInfo->map);
}



bool checkGameOver(GAMEINFO* gameInfo) {
    int survivingPlayers = 0, lastPlayer = -1;
    int i = 0, j = 0;

    for (i = 0; gameInfo->numPlayers > i; i++) {
        bool hasTerritories = false;
        for (j = 0; gameInfo->totalTerritories > j; j++) {
            if (gameInfo->maps[gameInfo->currentMapID].territories[j].ownerID == i) {
                hasTerritories = true;
                break;
            }
        }
        if (hasTerritories) {
            survivingPlayers++;
            lastPlayer = i;
        }
    }

    if (survivingPlayers == 1) return true;

    return false;
}



