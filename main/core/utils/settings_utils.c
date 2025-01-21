#include <global.h>

#include <settings_utils.h>


CONFIG readConfig() {
    CONFIG settings = {0};
    FILE *fp;
    int fullscreen;
    fp = fopen(CONFIG_FILE, "r");
    fscanf(fp, "%d %d %d %d %d %d %d\n",
               &settings.window_size.width,
               &settings.window_size.height,
               &fullscreen,
               &settings.max_FPS,
               &settings.volume,
               &settings.current_res,
               &settings.total_res);

    settings.fullscreen = fullscreen;

    fclose(fp);
    return settings;
}

void saveConfig(CONFIG config) {
    FILE *fp;
    fp = fopen(CONFIG_FILE, "w");

    fprintf(fp, "%d %d %d %d %d %d %d\n", 
            config.window_size.width, 
            config.window_size.height, 
            (config.fullscreen),
            config.max_FPS, 
            config.volume,
            config.current_res,
            config.total_res);
    fclose(fp);
}

