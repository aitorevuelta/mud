#include <global.h>
#include <controls.h>
#include <menu.h>

void handleMenuEvents(BUTTON *buttons, int buttonCount, GAMESTATE *gameState, CONTROLS *controls) {
    // Verificar si hubo un clic
    if (controls->click==1) {
        // Recorrer todos los botones visibles
        for (int i = 0; i < buttonCount; i++) {
            if (buttons[i].visible) {
                // Verificar si el clic ocurrió dentro del área del botón
                SDL_Rect rect = buttons[i].rect;
                if (controls->coords[0] >= rect.x &&
                    controls->coords[0] <= rect.x + rect.w &&
                    controls->coords[1] >= rect.y &&
                    controls->coords[1] <= rect.y + rect.h) {
                    
                    // Cambiar el estado del juego según la acción del botón
                    *gameState = buttons[i].action;
                    controls->click = 0; // Resetear el estado del clic
                    return; // Salir una vez se procesa el clic en un botón
                }
            }
        }
    }
}