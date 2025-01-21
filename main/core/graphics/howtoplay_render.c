#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>
#include <render.h>

#include <howtoplay_render.h>


void howtoplay_render(SDL_Renderer *renderer, BUTTON buttons[], ASSETS loadedAssets) {

    renderTextureRelative(renderer, loadedAssets.images[0].texture, 150, 50, 50);
    renderTextureRelative(renderer, loadedAssets.images[6].texture, 55, 50, 15);

    renderTextRelative(renderer, loadedAssets.fonts[0].font, "HELBURUA : Mapa osoa konkistatu", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 25, 20, 20);

    renderTextRelative(renderer, loadedAssets.fonts[0].font, "3 Fase desberdin:", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 15, 15, 25);
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "- 1. Desplegatu : Txandaren hasieran, tropa kopuru bat emango da, tropak zure lurraldetan desplegatu ahal dozu.", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 60, 45, 30);
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "- 2. Atakatu : Tropa guztiak desplegatu ostean, atakatzea posiblea da lurraldeak lortzeko. Atakatzerako momentuan, ", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 62, 46, 34);
    renderTextRelative(renderer, loadedAssets.fonts[0].font, " bakarrik alboko lurraldeei atakatu ahal da. Guda horren irabazlea aukeratzeko, tropen kopurua kontuan eukitzen da.", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 62, 52.4f, 37);
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "- 3. Indartu: Behin atakatuta, lurraldeak indartzea posiblea da, zure lurraldetako tropak, beste lurralde batera mugituz.", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 62, 46, 40);

    renderTextRelative(renderer, loadedAssets.fonts[0].font, "KARTAK : Behin atakatuta, lurralde bat lortzen badozu karta bat emango da txandaren bukaeran, 3 karta berdinak", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 83, 49, 45);
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "eukinda, tropak emoten dira hurrengo txandan desplegatzeko.", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 50, 39, 48);
    
    renderTextRelative(renderer, loadedAssets.fonts[0].font, "Ez da beharrezkoa ezta atakatzea ezta indartzea, bakarrik tropen desplegaketa.", (SDL_Color){255, 255, 255, 255}, 
                    (SDL_Color){55, 55, 55, 12}, 3, 70, 43, 55);

    renderTextureRelative(renderer, loadedAssets.images[2].texture, 17.5, 15, 75);
    renderTextureRelative(renderer, loadedAssets.images[3].texture, 17.5, 35, 75);
    renderTextureRelative(renderer, loadedAssets.images[4].texture, 17.5, 55, 75);
    renderTextureRelative(renderer, loadedAssets.images[5].texture, 30, 80, 75);       

    renderButtons(renderer, buttons, 1);
}

