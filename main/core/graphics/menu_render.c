#include <global.h>

#include <assets_utils.h>
#include <buttons_utils.h>

#include <render.h>

#include <menu_render.h>

// Variable global para mantener el ángulo de rotación
float rotationAngle = 0.0f; // Inicia en 0 grados

void menu_render(SDL_Renderer* renderer, BUTTON buttons[], ASSETS loadedAssets) {
    renderMenuBackground(renderer, loadedAssets); // menua
    renderButtons(renderer, buttons, 5); // botoiak
}

void renderMenuBackground(SDL_Renderer* renderer, ASSETS loadedAssets) {
    renderTextureRelative(renderer, loadedAssets.images[5].texture, 150.0, 50.0, 50.0);  // menu fondoa
    renderRotatingTexture(renderer, loadedAssets.images[7].texture, 150.0, 50.0, 50.0, 0.5, 0.1); //fondo girando, (tamaño, x, y, velocidad, opacidad)
    renderTextureRelative(renderer, loadedAssets.images[6].texture, 40.0, 50.0, 35.0);   // menu logoa

}

void renderRotatingTexture(SDL_Renderer* renderer, SDL_Texture* texture, float sizePercent, float xPercent, float yPercent, float rotationSpeed, float opacity) {
    int screenWidth, screenHeight;
    SDL_GetRendererOutputSize(renderer, &screenWidth, &screenHeight);

    // Calcular el tamaño base de la textura
    float baseWidth = (sizePercent * screenWidth) / 100.0;
    float baseHeight = (sizePercent * screenHeight) / 100.0;

    // Incrementar el tamaño del rectángulo para acomodar la rotación
    float expandedWidth = baseWidth * 1.5; // Aumentar un 50% como margen
    float expandedHeight = baseHeight * 1.5;

    // Calcular la posición centrada basada en el tamaño expandido
    float x = (xPercent * screenWidth) / 100.0f - expandedWidth / 2.0;
    float y = (yPercent * screenHeight) / 100.0f - expandedHeight / 2.0;

    SDL_Rect destRect = {
        (int)x, (int)y, (int)expandedWidth, (int)expandedHeight
    };

    SDL_Point center = { (int)(expandedWidth / 2.0f), (int)(expandedHeight / 2.0) };

    // Configurar la opacidad (convertir de rango 0.0f-1.0f a 0-255)
    Uint8 alpha = (Uint8)(opacity * 255);
    SDL_SetTextureAlphaMod(texture, alpha);

    // Renderizar la textura con rotación
    SDL_RenderCopyEx(renderer, texture, NULL, &destRect, rotationAngle, &center, SDL_FLIP_NONE);

    // Actualizar el ángulo de rotación
    rotationAngle += rotationSpeed;
    if (rotationAngle >= 360.0) {
        rotationAngle -= 360.0;
    }
}
