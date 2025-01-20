#ifndef SETTINGS_UTILS_H
#define SETTINGS_UTILS_H  

#define CONFIG_FILE "../data/config.txt"

CONFIG readConfig();
void saveConfig(CONFIG config);
void applyResolution(int resolution);

#endif // SETTINGS_UTILS_H