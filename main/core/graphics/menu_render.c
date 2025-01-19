#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>

#include <render.h>

#include <menu_render.h>


void menu_render(SDL_Renderer *renderer, BUTTON *buttons, ASSETS *loadedAssets) {
    // Renderizar fondo y logo del menú
    renderMenuBackground(renderer, loadedAssets);

    // Renderizar los botones
    renderButtons(renderer, buttons, buttonCount);  

}


void renderMenuBackground(SDL_Renderer *renderer, ASSETS *loadedAssets) {
    renderTextureRelative(renderer, loadedAssets->images[5].texture, 100, 50, 50);  // Fondo del menú
    renderTextureRelative(renderer, loadedAssets->images[6].texture, 60, 50, 20);   // Logo del menú
}



