#include <global.h>

#include <assets_utils.h>
#include <gamestate_utils.h>
#include <buttons_utils.h> 

#include <menu.h>

#include <render.h>

#include <settings_render.h>


int settings_render(SDL_Renderer *renderer, BUTTON **buttons, ASSETS *loadedAssets, CONFIG *config, int rend_sett) {
    const int buttonCount = 5;

    if (rend_sett == 0) {
        rend_sett = setupSettingsButtons(buttons, buttonCount, loadedAssets);
        if (rend_sett == -1) return -1;
    }

    renderTextureRelative(renderer, loadedAssets->images[0].texture, 150, 50, 50);
    renderTextureRelative(renderer, loadedAssets->images[16].texture, 35, 50, 10);

    renderSelectedResolution(renderer, loadedAssets->images, config->current_res); 
    renderSelectedVolume(renderer, loadedAssets->images, config->selectedVolume);
    
    renderButtons(renderer, *buttons, buttonCount);
   
   return rend_sett;
}




void renderSelectedResolution(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedResolution) {
    renderTextureRelative(renderer, loadedImages[14].texture, 50, 23, 35);
    renderTextureRelative(renderer, loadedImages[17].texture, 15, 8.5, 35);
    renderTextureRelative(renderer, loadedImages[selectedResolution].texture, 16.5, 35, 35); //Resolucion
}

void renderSelectedVolume(SDL_Renderer *renderer, IMAGES *loadedImages, int selectedVolume) {
    renderTextureRelative(renderer, loadedImages[14].texture, 50, 18, 50);
    renderTextureRelative(renderer, loadedImages[18].texture, 4, 6, 50);
    renderTextureRelative(renderer, loadedImages[19].texture, 16.5, 27.5, 50);

    // Verificar si hay barras que renderizar
    if (selectedVolume > 0) {
        for (int i = 0; i < selectedVolume; i++) {
            renderTextureRelative(renderer, loadedImages[15].texture, 1.6, (22.5 + (i * 2.5)), 50);
        }
    }
}