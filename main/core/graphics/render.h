#ifndef RENDER_H
#define RENDER_H


void render(SDL_Renderer* renderer, ASSETS loadedAssets, GAMESTATE gameState, GAMEINFO gameInfo, BUTTON buttons[], CONFIG config);
void renderTextureRelative(SDL_Renderer *renderer, SDL_Texture *texture, float widthPercent, float xPercent, float yPercent);
void renderTextRelative(SDL_Renderer *renderer, TTF_Font *font, const char *text, SDL_Color textColor, SDL_Color borderColor, int borderWidth, float widthPercent, float xPercent, float yPercent);
void renderShapeRelative(SDL_Renderer *renderer, float widthPercent, float heightPercent, 
                        float xPercent, float yPercent, SDL_Color shapeColor, 
                        float borderWidth, SDL_Color borderColor);
bool isMouseOverButton(const SDL_Rect *rect, int mouseX, int mouseY);
void renderButtons(SDL_Renderer *renderer, BUTTON buttons[], int buttonCount);

#endif