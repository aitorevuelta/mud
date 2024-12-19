#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <loadscreen.h>

void renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, CONFIG config) {
    renderLoadBar(renderer, loadedImages, config.window_width, config.window_height, 0.5);
}

void renderLoadBar(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, int windowWidth, int windowHeight, float percentage) {
    if (percentage < 0) percentage = 0;
    if (percentage > 1) percentage = 1;

    int barHeight = 15;
    int barWidth = (int)(windowWidth * percentage);

    SDL_Rect barRect = { 0, windowHeight - barHeight, barWidth, barHeight };
    SDL_SetRenderDrawColor(renderer, 245, 86, 54, 255);
    SDL_RenderFillRect(renderer, &barRect);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
}
