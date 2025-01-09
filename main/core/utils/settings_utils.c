#include <global.h>
<<<<<<< HEAD


=======
#include <sdl_utils.h>
#include <txt_utils.h>
>>>>>>> a803859dfebc056ea53323b6d3e06961b824887a
#include <settings_utils.h>

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