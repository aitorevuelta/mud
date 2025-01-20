#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>

#include <render.h>

#include <menu_render.h>


void menu_render(SDL_Renderer* renderer, BUTTON buttons[], ASSETS loadedAssets) {
    renderMenuBackground(renderer, loadedAssets); // menua
    renderButtons(renderer, buttons, 5); // botoiak
}


void renderMenuBackground(SDL_Renderer* renderer, ASSETS loadedAssets) {
    renderTextureRelative(renderer, loadedAssets.images[5].texture, 100, 50, 50);  // menu fondoa
    renderTextureRelative(renderer, loadedAssets.images[6].texture, 60, 50, 20);   // menu logoa
}



