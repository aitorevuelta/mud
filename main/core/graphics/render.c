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




void render(SDL_Renderer* renderer, ASSETS loadedAssets, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON buttons[], CONFIG config) {
    Uint32 frameStart = SDL_GetTicks();
    SDL_RenderClear(renderer);

    switch (gameState) {
        case LOADSCREEN:
            loadscreen_render(renderer, loadedAssets);
            break;
        case MAIN_MENU:
            menu_render(renderer, buttons, loadedAssets);
            break;
        case LOBBY:
            lobby_render(renderer, buttons, loadedAssets, gameInfo);
            break;
        case GAME:
            game_render(renderer, loadedAssets, buttons, gameInfo, config.window_size);
            break;
        case SETTINGS:
            settings_render(renderer, buttons, loadedAssets, config);
            break;
        case CREDITS:
            credits_render(renderer, buttons, loadedAssets);
            break;
        case HOWTOPLAY:
            howtoplay_render(renderer, buttons, loadedAssets);
            break;
        case EXIT_TOTAL:
            Mix_HaltMusic();
            exit(0);
            break;
    }
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
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


void renderShapeRelative(SDL_Renderer *renderer, float widthPercent, float heightPercent, 
                        float xPercent, float yPercent, SDL_Color shapeColor, 
                        float borderWidth, SDL_Color borderColor) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    // Calculate dimensions with float precision
    float shapeWidth = windowWidth * (widthPercent / 100.0f);
    float shapeHeight = windowHeight * (heightPercent / 100.0f);
    float posX = windowWidth * (xPercent / 100.0f);
    float posY = windowHeight * (yPercent / 100.0f) - shapeHeight / 2.0f;

    // Draw border if width > 0
    if (borderWidth > 0) {
        SDL_SetRenderDrawColor(renderer, borderColor.r, borderColor.g, borderColor.b, borderColor.a);
        for(int i = 0; i < borderWidth; i++) {
            SDL_Rect borderRect = {
                (int)(posX - i),
                (int)(posY - i),
                (int)(shapeWidth + (i * 2)),
                (int)(shapeHeight + (i * 2))
            };
            SDL_RenderDrawRect(renderer, &borderRect);
        }
    }

    // Draw inner fill if not transparent
    SDL_Rect fillRect = {
        (int)posX,
        (int)posY,
        (int)shapeWidth,
        (int)shapeHeight
    };

    if (shapeColor.a > 0) {
        SDL_SetRenderDrawColor(renderer, shapeColor.r, shapeColor.g, shapeColor.b, shapeColor.a);
        SDL_RenderFillRect(renderer, &fillRect);
    }
}

void renderTextRelative(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Color textColor, SDL_Color borderColor, int borderWidth, float widthPercent, float xPercent, float yPercent) {
    if (!text || !font) return;

    // Obtener dimensiones de la ventana
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    // Crear superficie y textura del texto principal
    SDL_Surface *textSurface = TTF_RenderText_Blended(font, text, textColor);
    if (!textSurface) return;

    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    if (!textTexture) return;

    // Crear superficie y textura para el borde
    SDL_Surface *borderSurface = TTF_RenderText_Blended(font, text, borderColor);
    if (!borderSurface) {
        SDL_DestroyTexture(textTexture);
        return;
    }

    SDL_Texture *borderTexture = SDL_CreateTextureFromSurface(renderer, borderSurface);
    SDL_FreeSurface(borderSurface);
    if (!borderTexture) {
        SDL_DestroyTexture(textTexture);
        return;
    }

    // Obtener dimensiones de la textura
    int textureWidth, textureHeight;
    SDL_QueryTexture(textTexture, NULL, NULL, &textureWidth, &textureHeight);
    float textureRatio = (float)textureWidth / textureHeight;

    // Calcular rectángulo de destino con posicionamiento relativo
    SDL_Rect dstRect;
    dstRect.w = (int)(windowWidth * (widthPercent / 100.0f));
    dstRect.h = (int)(dstRect.w / textureRatio);
    dstRect.x = (int)(windowWidth * (xPercent / 100.0f)) - (dstRect.w / 2);
    dstRect.y = (int)(windowHeight * (yPercent / 100.0f)) - (dstRect.h / 2);

    // Renderizar el borde en las posiciones alrededor del texto principal
    for (int dx = -borderWidth; dx <= borderWidth; dx++) {
        for (int dy = -borderWidth; dy <= borderWidth; dy++) {
            if (dx != 0 || dy != 0) { // Saltar la posición central
                SDL_Rect borderRect = dstRect;
                borderRect.x += dx;
                borderRect.y += dy;
                SDL_RenderCopy(renderer, borderTexture, NULL, &borderRect);
            }
        }
    }

    SDL_DestroyTexture(borderTexture);

    // Renderizar el texto principal
    SDL_RenderCopy(renderer, textTexture, NULL, &dstRect);
    SDL_DestroyTexture(textTexture);
}

bool isMouseOverButton(const SDL_Rect *rect, int mouseX, int mouseY) {
    return mouseX >= rect->x && mouseX <= (rect->x + rect->w) &&
           mouseY >= rect->y && mouseY <= (rect->y + rect->h);
}

void renderButtons(SDL_Renderer *renderer, BUTTON buttons[], int buttonCount) {
    int windowWidth, windowHeight, mouseX, mouseY;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);
    SDL_GetMouseState(&mouseX, &mouseY);

    for (int i = 0; i < buttonCount; i++) {
        if (buttons[i].visible && buttons[i].texture != NULL) {
            float scaleFactor = 1.0f;
            
            // Check mouse hover
            if (isMouseOverButton(&buttons[i].rect, mouseX, mouseY)) {
                scaleFactor = HOVER_SCALE;
            }

            // Get texture dimensions
            int textureWidth, textureHeight;
            SDL_QueryTexture(buttons[i].texture, NULL, NULL, &textureWidth, &textureHeight);
            float textureRatio = (float)textureWidth / textureHeight;

            // Render button with hover effect
            renderTextureRelative(renderer, 
                                buttons[i].texture, 
                                buttons[i].widthPercent * scaleFactor,
                                buttons[i].xPercent,
                                buttons[i].yPercent);
                                
            // Update rect for collision detection
            buttons[i].rect.w = (int)(windowWidth * (buttons[i].widthPercent / 100.0f) * scaleFactor);
            buttons[i].rect.h = (int)(buttons[i].rect.w / textureRatio);
            buttons[i].rect.x = (int)(windowWidth * (buttons[i].xPercent / 100.0f)) - (buttons[i].rect.w / 2);
            buttons[i].rect.y = (int)(windowHeight * (buttons[i].yPercent / 100.0f)) - (buttons[i].rect.h / 2);
        }
    }
}