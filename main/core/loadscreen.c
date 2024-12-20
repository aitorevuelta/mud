#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <texturemanager.h>
#include <render.h>
#include <loadscreen.h>

bool renderLoadscreen(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, CONFIG config) {
    static float percentage = 0.0f;
    bool loaded = updateLoading(&percentage);
    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);
    renderLoadBar(renderer, loadedImages, config.window_width, config.window_height, percentage);
    return loaded;
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

bool updateLoading(float *percentage) {
    static Uint32 lastTime = 0;
    Uint32 currentTime = SDL_GetTicks();
    float randomIncrement = 0.0f;
    if (currentTime > lastTime + 100) { 
        randomIncrement = (rand() % 1 + 1) / 100.0f;
        *percentage += randomIncrement;
        if (*percentage > 1.0f) {
            *percentage = 1.0f;
        }
        lastTime = currentTime;
    }

    return *percentage >= 1.0f;
}
