#include <global.h>
#include <assets_utils.h>
#include <loadscreen_render.h>
#include <menu_render.h>
#include <lobby_render.h>
#include <game_render.h>
#include <settings_render.h>
#include <credits_render.h>
#include <render.h>

void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMESTATE gameState, GAMEINFO gameInfo, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);

    switch(gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedImages);
            break;
        case MAIN_MENU:
        
            break;
        case LOBBY:
            renderLobby(renderer, loadedImages);
            break;
        case GAME:
            renderGame(renderer, loadedImages, loadedFonts, gameInfo, config);
            break;
        case SETTINGS:
            renderSettings(renderer, loadedImages);
            break;
        case CREDITS:
            renderCredits(renderer, loadedImages);
            break;
    }

    SDL_RenderPresent(renderer);
}

void renderTextureRelative(SDL_Renderer *renderer, SDL_Texture *texture, float widthPercent, float xPercent, float yPercent) {
    
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    // Get original texture dimensions
    int textureWidth, textureHeight;
    SDL_QueryTexture(texture, NULL, NULL, &textureWidth, &textureHeight);
    float textureRatio = (float)textureWidth / textureHeight;

    SDL_Rect dstRect;
    // Calculate size maintaining aspect ratio
    dstRect.w = (int)(windowWidth * (widthPercent / 100.0f));
    dstRect.h = (int)(dstRect.w / textureRatio);

    // Center at specified position
    dstRect.x = (int)(windowWidth * (xPercent / 100.0f)) - (dstRect.w / 2);
    dstRect.y = (int)(windowHeight * (yPercent / 100.0f)) - (dstRect.h / 2);

    SDL_RenderCopy(renderer, texture, NULL, &dstRect);
}