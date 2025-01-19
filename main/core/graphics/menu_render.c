#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>

#include <render.h>

#include <menu_render.h>


int menu_render(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAsset) {
    const int buttonCount = 5;

    if (rend_menu == 0) {
        rend_menu = setupMenuButtons(buttons,buttonCount, loadedAssets);
        if (rend_menu == -1) return -1;
    }

    // Renderizar fondo y logo del menú
    renderMenuBackground(renderer, loadedAssets);

    // Renderizar los botones
    renderButtons(renderer, buttons, buttonCount);  

    return rend_menu;
}


void renderMenuBackground(SDL_Renderer *renderer, ASSETS *loadedAssets) {
    renderTextureRelative(renderer, loadedAssets->images[5].texture, 100, 50, 50);  // Fondo del menú
    renderTextureRelative(renderer, loadedAssets->images[6].texture, 60, 50, 20);   // Logo del menú
}



