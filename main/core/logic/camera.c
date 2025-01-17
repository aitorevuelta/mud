#include <global.h>

#include <controls.h>

#include <camera.h>

static int prevMouseX = 0;
static int prevMouseY = 0;
static bool firstClick = true;
    
void updateCamera(CAMERA* camera, CONTROLS* controls, int screenWidth, int screenHeight) {

    if (controls->scroll != 0) {
        // Smaller increment for smoother zoom (0.1 to 1.0 range)
        float zoomDelta = controls->scroll * 0.02f;
        // Update and clamp zoom between 0.1 and 1.0
        camera->zoom += zoomDelta;
        if (camera->zoom < 0.5f) {
            camera->zoom = 0.5f;
        }
        if (camera->zoom > 2.0f) {
            camera->zoom = 2.0f;
        }
    }

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