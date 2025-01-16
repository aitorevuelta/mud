#ifndef RENDER_H
#define RENDER_H


void render(SDL_Renderer *renderer, ASSETS *loadedAssets, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON **buttons, CONFIG config);
void renderTextureRelative(SDL_Renderer *renderer, SDL_Texture *texture, float widthPercent, float xPercent, float yPercent);
void renderShapeRelative(SDL_Renderer *renderer, int widthPercent, int heightPercent, int xPercent, int yPercent, COLOUR shapeColor);
bool isMouseOverButton(const SDL_Rect *rect, int mouseX, int mouseY);
void renderButtons(SDL_Renderer *renderer, BUTTON *buttons, int buttonCount);

#endif