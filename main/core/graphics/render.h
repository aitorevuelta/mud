#ifndef RENDER_H
#define RENDER_H


void render(SDL_Renderer *renderer, LOADEDIMAGES *loadedImages, LOADEDFONTS *loadedFonts, GAMESTATE gameState, GAMEINFO gameInfo, CONFIG config);

void renderTextureRelative(SDL_Renderer *renderer, SDL_Texture *texture, float widthPercent, float xPercent, float yPercent);

#endif