#include <global.h>

#include <assets_utils.h>

#include <settings_render.h>

void renderSettings(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages){

    SDL_RenderCopy(renderer, loadedImages[0].texture, NULL, NULL);
    

}