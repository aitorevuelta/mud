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
            renderLoadscreen(renderer, loadedAssets);
            break;
        case MAIN_MENU:
            rend_menu = renderMenu(renderer, buttons, loadedAssets, rend_menu);
            rend_general = 0;
            break;
        case LOBBY:
            rend_general = renderLobby(renderer, buttons, loadedAssets, &gameInfo, rend_general);
            rend_menu = 0;
            break;
        case GAME:
            rend_general = renderGame(renderer, loadedAssets, gameInfo, config, rend_general);
            rend_menu = 0;
            break;
        case SETTINGS:
            rend_general = renderSettings(renderer, buttons, loadedAssets, &gameInfo, rend_general);
            rend_menu = 0;
            break;
        case CREDITS:
            rend_general = renderCredits(renderer, buttons, loadedAssets, rend_general);
            rend_menu = 0;
            break;
        case HOWTOPLAY:
            rend_general = renderHowtoplay(renderer, buttons, loadedAssets, rend_general);
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


void renderShapeRelative(SDL_Renderer *renderer, int widthPercent, int heightPercent, int xPercent, int yPercent, COLOUR shapeColor) {
    int windowWidth, windowHeight;
    SDL_GetRendererOutputSize(renderer, &windowWidth, &windowHeight);

    // Establecer el color del pincel
    SDL_SetRenderDrawColor(renderer, shapeColor.r, shapeColor.g, shapeColor.b, shapeColor.a);

    // Calcular las dimensiones relativas a la ventana
    int shapeWidth = (int)(windowWidth * (widthPercent / 100.0f));
    int shapeHeight = (int)(windowHeight * (heightPercent / 100.0f));

    // Calcular la posición basada en los porcentajes especificados
    int posX = (int)(windowWidth * (xPercent / 100.0f));
    int posY = (int)(windowHeight * (yPercent / 100.0f));

    // Ajustar la posición para el alto en relación al centro vertical
    posY -= shapeHeight / 2;

    // Crear el rectángulo con las dimensiones y posición calculadas
    SDL_Rect rect = {posX, posY, shapeWidth, shapeHeight};

    // Dibujar el rectángulo con el color especificado
    SDL_RenderFillRect(renderer, &rect);

    // Restablecer el color del pincel al predeterminado (opcional)
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Negro por defecto
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