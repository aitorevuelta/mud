#ifndef CAMERA_H
#define CAMERA_H


void updateCamera(CAMERA* camera, CONTROLS controls, int screenWidth, int screenHeight);
void updateCameraZoom(CAMERA* camera, CONTROLS controls);
void updateCameraPosition(CAMERA* camera, CONTROLS controls, int screenWidth, int screenHeight);

#endif