#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <utils.h>
#include <game_logic.h>

#include <game_render.h>

void renderGame(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, GAMEINFO gameinfo, CONFIG config)
{
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);


}