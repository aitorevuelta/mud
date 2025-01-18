#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <menu.h>
#include <render.h>

#include <credits_render.h>

int credits_render(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, int rend_cred) {
    const int buttonCount = 1;

    if (rend_cred == 0) {
        rend_cred = setupCreditsButtons(buttons, buttonCount, loadedAssets);
        if (rend_cred == -1) return -1;
    }

    // Renderiza los botones
    renderTextureRelative(renderer, loadedAssets->images[0].texture, 150, 50, 50);
    renderTextureRelative(renderer, loadedAssets->images[2].texture, 35, 50, 10);
    renderTextureRelative(renderer, loadedAssets->images[3].texture, 25, 25, 58);
    renderButtons(renderer, *buttons, buttonCount);
   
   return rend_cred;
}

