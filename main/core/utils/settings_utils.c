#include <global.h>

#include <settings_utils.h>


CONFIG readConfig() {
    CONFIG settings = {0};
    FILE *fp;
    int fullscreen;
    fp = fopen(CONFIG_FILE, "r");
    fscanf(fp, "%d %d %d %d %d\n",
               &settings.window_size.width,
               &settings.window_size.height,
               &fullscreen,
               &settings.max_FPS,
               &settings.selectedVolume);

    settings.fullscreen = fullscreen;

    fclose(fp);
    return settings;
}

void saveConfig(CONFIG config) {
    FILE *fp;
    fp = fopen(CONFIG_FILE, "w");

    fprintf(fp, "%d %d %d %d %d\n", 
            config.window_size.width, 
            config.window_size.height, 
            (config.fullscreen),
            config.max_FPS, 
            config.selectedVolume);

    fclose(fp);
}
void applyResolution(int resolution) {
    // Lógica para aplicar la resolución del juego
    // Esto puede variar dependiendo de cómo manejes las resoluciones en tu juego
    // Aquí hay un ejemplo básico:
    int width, height;
    switch (resolution) {
        case 1:
            width = 800;
            height = 600;
            break;
        case 2:
            width = 1024;
            height = 768;
            break;
        case 3:
            width = 1280;
            height = 720;
            break;
        case 4:
            width = 1366;
            height = 768;
            break;
        case 5:
            width = 1600;
            height = 900;
            break;
        case 6:
            width = 1920;
            height = 1080;
            break;
        default:
            width = 800;
            height = 600;
            break;
    }

    SDL_SetWindowSize(SDL_GetWindowFromID(1), width, height);
    SDL_SetWindowPosition(SDL_GetWindowFromID(1), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);
}