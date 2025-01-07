#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_net.h>
#include <global.h>
#include <init.h>
#include <utils.h>
#include <settings.h>

// CONFIG

CONFIG readConfig() {
    CONFIG settings = {0};
    FILE *fp;
    int fullscreen;
    fp = fopen(CONFIG_FILE, "r");
    fscanf(fp, "%d %d %d %d %d\n",
               &settings.window_width,
               &settings.window_height,
               &fullscreen,
               &settings.max_FPS,
               &settings.volume);

    settings.fullscreen = fullscreen;

    fclose(fp);
    return settings;
}

void saveConfig(CONFIG config) {
    FILE *fp;
    fp = fopen(CONFIG_FILE, "w");

    fprintf(fp, "%d %d %d %d %d\n", 
            config.window_width, 
            config.window_height, 
            (config.fullscreen),
            config.max_FPS, 
            config.volume);

    fclose(fp);
}