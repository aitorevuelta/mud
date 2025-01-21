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
    info.totalTerritories=23;
    

    return info;
}


void update_game(GAMEINFO *gameInfo) {
    //checkMapTerritoryClick
    
    handleTurn(gameInfo);
}

static Uint32 lastUpdateTime = 0;

void handleTurn(GAMEINFO *gameInfo) {
    if (!gameInfo) return;
    
    Uint32 currentTime = SDL_GetTicks();
    float deltaTime = (currentTime - lastUpdateTime) / 1000.0f;
    
    // Update elapsed time
    gameInfo->elapsedTime += deltaTime;
    
    // Reset timer and change turn at 60 seconds
    if (gameInfo->elapsedTime >= 60.0f) {
        gameInfo->elapsedTime = 0.0f;
        
        // Increment turn
        gameInfo->turn = (gameInfo->turn + 1) % gameInfo->numPlayers;
        
        // If we've completed a full round of players
        if (gameInfo->turn == 0) {
            gameInfo->round++;
        }
    }
    //handlePhase(gameInfo);
    lastUpdateTime = currentTime;
}

void handlePhase(GAMEINFO* gameInfo) {
    if (!gameInfo) return;

    switch (gameInfo->phase) {
        case DEPLOY:
            deployTroopsPhase(gameInfo);
            gameInfo->phase = ATTACK; // Cambiar a la siguiente fase
            break;

        case ATTACK:
            attackPhase(gameInfo);
            gameInfo->phase = REINFORCE; // Cambiar a la siguiente fase
            break;

        case REINFORCE:
            reinforcePhase(gameInfo);
            // Cambiar al siguiente jugador
            gameInfo->currentPlayerID = (gameInfo->currentPlayerID + 1) % gameInfo->numPlayers;
            if (gameInfo->currentPlayerID == 0) {
                gameInfo->round++; // Nueva ronda
            }
            gameInfo->phase = DEPLOY; // Volver a la fase inicial
            break;

        default:
            break;
    }
}

void deployTroopsPhase(GAMEINFO* gameInfo) {
    PLAYER* currentPlayer = &gameInfo->players[gameInfo->currentPlayerID];
    MAPINFO* mapInfo = &gameInfo->maps[gameInfo->currentMapID];

    int troopsToDeploy = currentPlayer->troops;
    printf("Player %d is deploying %d troops.\n", currentPlayer->id, troopsToDeploy);

    while (troopsToDeploy > 0) {
        int randomIndex = rand() % currentPlayer->numTerritories;
        int territoryID = currentPlayer->territories[randomIndex];
        TERRITORYINFO* territory = &mapInfo->territories[territoryID];

        territory->troops++;
        troopsToDeploy--;
    }

    currentPlayer->troops = 0; // Tropas desplegadas
    printf("Player %d finished deploying troops.\n", currentPlayer->id);
}
void attackPhase(GAMEINFO* gameInfo) {
    PLAYER* currentPlayer = &gameInfo->players[gameInfo->currentPlayerID];
    MAPINFO* mapInfo = &gameInfo->maps[gameInfo->currentMapID];

    printf("Player %d is in the attack phase.\n", currentPlayer->id);

    for (int i = 0; i < currentPlayer->numTerritories; i++) {
        int territoryID = currentPlayer->territories[i];
        TERRITORYINFO* attacker = &mapInfo->territories[territoryID];

        if (attacker->troops > 1) {
            // Buscar territorio enemigo adyacente (asumiendo conexión)
            int randomTargetID = rand() % mapInfo->numTerritories; // Aquí deberías implementar la lógica de adyacencia
            TERRITORYINFO* defender = &mapInfo->territories[randomTargetID];

            if (defender->ownerID != currentPlayer->id) {
                // Simulación de ataque
                printf("Attacking from %s to %s.\n", attacker->name, defender->name);
                if (rand() % 2 == 0) { // Gana atacante
                    defender->troops--;
                    if (defender->troops <= 0) {
                        defender->ownerID = currentPlayer->id;
                        defender->troops = 1;
                        attacker->troops--;
                    }
                } else { // Gana defensor
                    attacker->troops--;
                }
                return;
            }
        }
    }
}
void reinforcePhase(GAMEINFO* gameInfo) {
    PLAYER* currentPlayer = &gameInfo->players[gameInfo->currentPlayerID];
    MAPINFO* mapInfo = &gameInfo->maps[gameInfo->currentMapID];

    printf("Player %d is in the reinforcement phase.\n", currentPlayer->id);

    for (int i = 0; i < currentPlayer->numTerritories; i++) {
        int sourceID = currentPlayer->territories[i];
        TERRITORYINFO* source = &mapInfo->territories[sourceID];

        if (source->troops > 1) {
            int randomTargetID = rand() % currentPlayer->numTerritories;
            TERRITORYINFO* target = &mapInfo->territories[currentPlayer->territories[randomTargetID]];

            int troopsToMove = rand() % (source->troops - 1) + 1;
            source->troops -= troopsToMove;
            target->troops += troopsToMove;

            printf("Moved %d troops from %s to %s.\n", troopsToMove, source->name, target->name);
            return;
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
}








/*bool checkGameOver(GAMEINFO* gameInfo) {
     int survivingPlayers = 0;
    int lastPlayer = -1;

    for (int i = 0; i < gameInfo->numPlayers; i++) {
        bool hasTerritories = false;
        for (int j = 0; j < gameInfo->mapInfo.numTerritories; j++) {
            if (gameInfo->mapInfo.territories[j].owner == i) {
                hasTerritories = true;
                break;
            }
        }

        if (hasTerritories) {
            survivingPlayers++;
            lastPlayer = i;
        }
    }

    if (survivingPlayers == 1) {
        printf("Game Over! Player %d wins!\n", lastPlayer);
        return true;
    }

    return false;
    }
*/