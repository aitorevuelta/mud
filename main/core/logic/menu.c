#include <global.h>

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
}