#include <stdio.h>
#include <stdbool.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <utils.h>

CONFIG readConfig() {
    CONFIG settings = {0};
    FILE *fp;

    fp = fopen(CONFIG_FILE, "r");

    if (fp == NULL) {
        printf("Error: No se pudo abrir el archivo de configuración '%s'\n", CONFIG_FILE);
        settings.window_width = 800; 
        settings.window_height = 600;
        settings.fullscreen = 0;
        settings.max_FPS = 60;
        settings.volume = 50;
        return settings;
    }

    fscanf(fp, "%d %d %d %d %d\n",
               &settings.window_width,
               &settings.window_height,
               &settings.fullscreen,
               &settings.max_FPS,
               &settings.volume);

    fclose(fp);
    return settings;
}
