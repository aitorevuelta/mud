#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <render.h>

#include <credits_render.h>

void credits_render(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets) {
    renderTextureRelative(renderer, loadedAssets.images[0].texture, 150, 50, 50);
    renderTextureRelative(renderer, loadedAssets.images[2].texture, 35, 50, 10);
    renderTextureRelative(renderer, loadedAssets.images[3].texture, 25, 25, 58);
    renderButtons(renderer, buttons, 1);
}

