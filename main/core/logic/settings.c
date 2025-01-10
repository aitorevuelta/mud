#include <global.h>

#include <menu.h>

#include <settings.h>

MENU create_settings_menu()
{
    MENU menu;
    menu.item_count = 3;

    menu.items = (MENU_ITEM*)malloc(menu.item_count * sizeof(MENU_ITEM));

    

    return menu;
}   