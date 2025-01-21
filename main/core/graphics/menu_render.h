#ifndef MENU_RENDER_H
#define MENU_RENDER_H


void menu_render(SDL_Renderer* renderer, BUTTON buttons[], ASSETS loadedAssets);
void renderMenuBackground(SDL_Renderer *renderer, ASSETS loadedAssets);
void renderRotatingTexture(SDL_Renderer* renderer, SDL_Texture* texture, float sizePercent, float xPercent, float yPercent, float rotationSpeed, float opacity);

#endif 
