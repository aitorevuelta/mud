#include <global.h>

#include <assets_utils.h>

#include <gamestate_manager.h>

static GAMESTATE lastGameState = 0; 

void checkGameStateChange(LOADEDIMAGES** loadedImages, LOADEDFONTS** loadedFonts, GAMESTATE* gameState, SDL_Renderer* renderer) {
// Asegúrate de usar el estado válido inicial

    if (*gameState != lastGameState) {
        // Liberar recursos anteriores antes de cargar nuevos


        // Cargar los nuevos recursos
        LoadImages(loadedImages, *gameState, renderer);
        LoadFonts(loadedFonts, *gameState, renderer);

        lastGameState = *gameState; // Actualizar el último estado
    }
}
