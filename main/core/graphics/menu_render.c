#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <utils.h>


#include <menu_render.h>


void renderMenu(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, GAMESTATE *gameState, CONFIG config) {
    BUTTON buttons[5];
    int buttonCount = 5;
    initializeButtons(buttons, loadedImages);
    renderButtons(renderer, buttons, buttonCount);
}

void initializeButtons(BUTTON *buttons, LOADEDIMAGES *loadedImages) {
    buttons[0] = (BUTTON){ .rect = { 200, 200, 300, 100 }, .texture = loadedImages[0].texture, .action = ACTION_PLAY, .visible = 1 };
    buttons[1] = (BUTTON){ .rect = { 200, 320, 300, 100 }, .texture = loadedImages[1].texture, .action = ACTION_HOWTOPLAY, .visible = 1 };
    buttons[2] = (BUTTON){ .rect = { 200, 440, 300, 100 }, .texture = loadedImages[2].texture, .action = ACTION_CREDITS, .visible = 1 };
    buttons[3] = (BUTTON){ .rect = { 200, 560, 300, 100 }, .texture = loadedImages[3].texture, .action = ACTION_SETTINGS, .visible = 1 };
    buttons[4] = (BUTTON){ .rect = { 20, 20, 100, 50 }, .texture = loadedImages[4].texture, .action = ACTION_EXIT, .visible = 1 };
}

void renderButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount) {
    for (int i = 0; buttonCount > i; i++) {
        if (buttons[i].visible) {
            //SDL_RenderCopy(renderer, buttons[i].texture, NULL, &buttons[i].rect);
        }
    }
}

