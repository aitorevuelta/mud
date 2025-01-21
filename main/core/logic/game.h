#ifndef GAME_H
#define GAME_H

#define TERRITORY_COUNT 6
#define MAX_PLAYERS 4




GAMEINFO loadGameInfo();

// Logica del juego
void update_game(GAMEINFO *gameInfo);
void handleTurn(GAMEINFO *gameInfo);
void handlePhase(GAMEINFO* gameInfo);


void deployTroopsPhase(GAMEINFO* gameInfo);
void attackPhase(GAMEINFO* gameInfo);
void reinforcePhase(GAMEINFO* gameInfo);


void game_init(SDL_Renderer *renderer, GAMEINFO *gameInfo, RESOLUTION resolution);


//bool checkGameOver(GAMEINFO* gameInfo);


#endif // GAME_H3