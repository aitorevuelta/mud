#include <global.h>
#include <assets_utils.h>
#include <loadscreen_render.h>
#include <menu_render.h>
#include <lobby_render.h>
#include <game_render.h>
#include <settings_render.h>
#include <credits_render.h>
#include <howtoplay_render.h>

#include <render.h>


void render(SDL_Renderer* renderer, ASSETS* assets, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON** buttons, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);

    static int rend_general = 0, rend_menu = 0;

    switch (gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, assets->images);
            break;
        case MAIN_MENU:
            rend_menu = renderMenu(rend_menu, renderer, buttons, assets->images);
            rend_general = 0;
            break;
        case LOBBY:
            //rend_general = renderLobby(rend_general, renderer, buttons, assets->images, &gameInfo);
            rend_menu = 0;
            break;
        case GAME:
            rend_general = renderGame(renderer, assets->images, assets->fonts, gameInfo, config, rend_general);
            rend_menu = 0;
            break;
        case SETTINGS:
            rend_general = renderSettings(rend_general, renderer, buttons, assets->images);
            rend_menu = 0;
            break;
        case CREDITS:
            rend_general = renderCredits(rend_general, renderer, buttons, assets->images);
            rend_menu = 0;
            break;
        case HOWTOPLAY:
            rend_general = renderHowtoplay(rend_general, renderer, buttons, assets->images);
            rend_menu = 0;
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

bool isMouseOverButton(const SDL_Rect *rect, int mouseX, int mouseY) {
    return mouseX >= rect->x && mouseX <= (rect->x + rect->w) &&
           mouseY >= rect->y && mouseY <= (rect->y + rect->h);
}

void renderButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount) {
    int windowWidth, windowHeight, mouseX, mouseY;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    SDL_GetMouseState(&mouseX, &mouseY);

    for (int i = 0; i < buttonCount; i++) {
        if (buttons[i].visible && buttons[i].texture) {
            int textureWidth, textureHeight;
            SDL_QueryTexture(buttons[i].texture, NULL, NULL, &textureWidth, &textureHeight);

            SDL_Rect adjustedRect = buttons[i].rect;
            float textureRatio = (float)textureWidth / textureHeight;
            float scaleFactor = isMouseOverButton(&buttons[i].rect, mouseX, mouseY) ? HOVER_SCALE : 1.0f;

            adjustedRect.w = (int)(windowWidth * (buttons[i].widthPercent / 100.0f) * scaleFactor);
            adjustedRect.h = (int)(adjustedRect.w / textureRatio);
            adjustedRect.x = (int)(windowWidth * (buttons[i].xPercent / 100.0f)) - (adjustedRect.w / 2);
            adjustedRect.y = (int)(windowHeight * (buttons[i].yPercent / 100.0f)) - (adjustedRect.h / 2);

            // Validar dimensiones antes de renderizar
            if (adjustedRect.w > 0 && adjustedRect.h > 0) {
                SDL_RenderCopy(renderer, buttons[i].texture, NULL, &adjustedRect);
            } else {
                fprintf(stderr, "Advertencia: Dimensiones inválidas para el botón %d\n", i);
            }
        } else if (!buttons[i].texture) {
            fprintf(stderr, "Error: La textura del botón %d es NULL\n", i);
        }
    }
}


