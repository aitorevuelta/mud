#include <global.h>

#include <controls.h>

#include <camera.h>

    static int prevMouseX = 0;
    static int prevMouseY = 0;
    static bool firstClick = true;
    
void updateCamera(CAMERA* camera, CONTROLS* controls, int screenWidth, int screenHeight) {

  //  if (controls->scroll != 0) {
  //      camera->zoom += controls->scroll * 0.1f;
        // Clamp zoom between 0 and 1
   //     camera->zoom = (camera->zoom < 0.0f) ? 0.0f : (camera->zoom > 1.0f) ? 1.0f : camera->zoom;
 //   }

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
        camera->pos[0] -= deltaX;
        camera->pos[1] -= deltaY;

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