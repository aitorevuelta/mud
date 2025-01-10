#include <global.h>
<<<<<<< HEAD
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
=======

#include <menu.h>

MENU create_main_menu() {
    MENU menu;
    menu.item_count = 4;
    menu.selected_index = 0;

    menu.items = malloc(sizeof(MENU_ITEM) * menu.item_count);
    menu.items[0] = (MENU_ITEM){ "Jugar", {100, 100, 200, 50}};
    menu.items[1] = (MENU_ITEM){ "Cargar Partida", {100, 200, 200, 50}};
    menu.items[2] = (MENU_ITEM){ "Opciones", {100, 300, 200, 50}};
    menu.items[3] = (MENU_ITEM){ "Salir", {100, 400, 200, 50}};

    return menu;
>>>>>>> 28e5ae7950511b77dd0dc76b4c914bd7c53bfd6a
}