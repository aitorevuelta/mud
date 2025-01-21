#ifndef GAME_H
#define GAME_H

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 4




GAMEINFO loadGameInfo();

// Logica del juego
void update_game(GAMEINFO *gameInfo);
void updateTime(GAMEINFO *gameInfo);

// Iniciar players
void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo);
void allocatePlayers(GAMEINFO *gameInfo);
PLAYER initializePlayer(int id);
void initializePlayers(GAMEINFO *gameInfo);

void allocateTerritories(GAMEINFO* gameInfo);

void initializeTerritories(MAPINFO* mapInfo);



bool checkGameOver(GAMEINFO* gameInfo);

void freeTerritories(GAMEINFO* gameInfo);
void freePlayers(GAMEINFO* gameInfo);


#endif // GAME_H3