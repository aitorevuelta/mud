#ifndef MENU_H
#define MENU_H

typedef struct MENU_ITEM_S {
    const char* text;       // Texto del elemento del menú.
    SDL_Rect rect;          // Área del elemento en la pantalla.
    void (*action)();       // Función que se ejecuta al seleccionar este elemento.
} MENU_ITEM;

typedef struct MENU_S {
    MENU_ITEM* items;        // Array de elementos del menú.
    int item_count;         // Cantidad de elementos en el menú.
    int selected_index;     // Índice del elemento actualmente seleccionado.
} MENU;

MENU create_main_menu();

#endif // MENU_H