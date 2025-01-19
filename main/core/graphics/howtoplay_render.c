#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <render.h>

#include <howtoplay_render.h>


void howtoplay_render(SDL_Renderer *renderer, BUTTON buttons, ASSETS *loadedAssets) {
    // Renderiza los botones
    renderTextureRelative(renderer, loadedAssets->images[0].texture, 100, 50, 50);

    renderTextureRelative(renderer, loadedAssets->images[2].texture, 23, 20, 25);
    renderTextureRelative(renderer, loadedAssets->images[3].texture, 18, 40, 25);
    renderTextureRelative(renderer, loadedAssets->images[4].texture, 20, 60, 25);

    renderTextureRelative(renderer, loadedAssets->images[5].texture, 26, 18, 50);
    renderTextureRelative(renderer, loadedAssets->images[6].texture, 24, 38, 50);

    renderTextureRelative(renderer, loadedAssets->images[9].texture, 40, 80, 65);

    renderTextureRelative(renderer, loadedAssets->images[7].texture, 23, 20, 85);
    renderTextureRelative(renderer, loadedAssets->images[8].texture, 22, 40, 85);


    renderButtons(renderer, buttons, buttonCount);
}

