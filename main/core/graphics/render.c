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


void render(SDL_Renderer* renderer, ASSETS* loadedAssets, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON** buttons, CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);

    static int rend_general = 0, rend_menu = 0;

    switch (gameState) {
        case LOADSCREEN:
            renderLoadscreen(renderer, loadedAssets->images);
            break;
        case MAIN_MENU:
            rend_menu = renderMenu(rend_menu, renderer, buttons, loadedAssets->images);
            rend_general = 0;
            break;
        case LOBBY:
            rend_general = renderLobby(rend_general, renderer, buttons, loadedAssets->images, &gameInfo);
            rend_menu = 0;
            break;
        case GAME:
            rend_general = renderGame(renderer, loadedAssets->images, loadedAssets->fonts, gameInfo, config, rend_general);
            rend_menu = 0;
            break;
        case SETTINGS:
            rend_general = renderSettings(rend_general, renderer, buttons, loadedAssets->images);
            rend_menu = 0;
            break;
        case CREDITS:
            rend_general = renderCredits(rend_general, renderer, buttons, loadedAssets->images);
            rend_menu = 0;
            break;
        case HOWTOPLAY:
            rend_general = renderHowtoplay(rend_general, renderer, buttons, loadedAssets->images);
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
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight); // Obtener dimensiones de la ventana
    SDL_GetMouseState(&mouseX, &mouseY); // Obtener posición del cursor

    for (int i = 0; i < buttonCount; i++) {
        if (buttons[i].visible) {
            if (buttons[i].texture == NULL) {
                fprintf(stderr, "Error: La textura del botón %d es NULL\n", i);
                continue; // Saltar este botón si la textura es NULL
            }

            // Obtener dimensiones originales de la textura
            int textureWidth, textureHeight;
            SDL_QueryTexture(buttons[i].texture, NULL, NULL, &textureWidth, &textureHeight);

            // Calcular el tamaño del botón manteniendo la relación de aspecto
            float textureRatio = (float)textureWidth / textureHeight;
            float scaleFactor = 1.0f;

            // Detectar si el mouse está sobre el botón
            if (isMouseOverButton(&buttons[i].rect, mouseX, mouseY)) {
                scaleFactor = HOVER_SCALE; // Aplicar el escalado al botón en hover
            }

            // Calcular dimensiones ajustadas con escala
            buttons[i].rect.w = (int)(windowWidth * (buttons[i].widthPercent / 100.0f) * scaleFactor);
            buttons[i].rect.h = (int)(buttons[i].rect.w / textureRatio);
            buttons[i].rect.x = (int)(windowWidth * (buttons[i].xPercent / 100.0f)) - (buttons[i].rect.w / 2);
            buttons[i].rect.y = (int)(windowHeight * (buttons[i].yPercent / 100.0f)) - (buttons[i].rect.h / 2);

            // Renderizar el botón
            if (SDL_RenderCopy(renderer, buttons[i].texture, NULL, &buttons[i].rect) != 0) {
                fprintf(stderr, "Error en SDL_RenderCopy para el botón %d: %s\n", i, SDL_GetError());
            }
        }
    }
}

