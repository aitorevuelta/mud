#include <global.h>

#include <controls.h>

#include <camera.h>

static int prevMouseX = 0;
static int prevMouseY = 0;
static bool firstClick = true;
    
void updateCamera(CAMERA* camera, CONTROLS* controls, int screenWidth, int screenHeight) {

    if (controls->scroll != 0) {
        // Ajustar el zoom suavemente
        float zoomDelta = controls->scroll * 0.04f;
        float newZoom = camera->zoom + zoomDelta;

        // Limitar el zoom dentro del rango permitido
        camera->zoom = (newZoom < 0.5f) ? 0.5f : (newZoom > 2.0f) ? 2.0f : newZoom;
    }
}

void updateCameraPosition(CAMERA* camera, CONTROLS* controls, int screenWidth, int screenHeight) {
    if (controls->click) {
        if (firstClick) {
            prevMouseX = controls->coords[0];
            prevMouseY = controls->coords[1];
            firstClick = false;
        }

        // Calculate and print deltas
        int deltaX = controls->coords[0] - prevMouseX;
        int deltaY = controls->coords[1] - prevMouseY;

        // Update camera position
        camera->pos[0] += deltaX;
        camera->pos[1] += deltaY;

        // Clamp camera position
        camera->pos[0] = (camera->pos[0] < 0) ? 0 : (camera->pos[0] > screenWidth) ? screenWidth : camera->pos[0];
        camera->pos[1] = (camera->pos[1] < 0) ? 0 : (camera->pos[1] > screenHeight) ? screenHeight : camera->pos[1];

        // Update previous position
        prevMouseX = controls->coords[0];
        prevMouseY = controls->coords[1];
    } else {
        firstClick = true;
    }
}