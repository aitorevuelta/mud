#include <global.h>

#include <controls.h>

#include <camera.h>

static bool firstClick = true;  // Controla el estado del primer clic
static int prevMouseX = 0;     // Posición previa del mouse (X)
static int prevMouseY = 0;     // Posición previa del mouse (Y)
    
void updateCamera(CAMERA* camera, CONTROLS* controls, int screenWidth, int screenHeight) {
    updateCameraZoom(camera, controls);
    updateCameraPosition(camera, controls, screenWidth, screenHeight);
}

void updateCameraZoom(CAMERA* camera, CONTROLS* controls) {
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
            // Inicializa la posición previa del mouse en el primer clic
            prevMouseX = controls->coords[0];
            prevMouseY = controls->coords[1];
            firstClick = false;
        }

        // Calcular deltas de movimiento
        int deltaX = controls->coords[0] - prevMouseX;
        int deltaY = controls->coords[1] - prevMouseY;

        // Actualizar la posición de la cámara
        camera->pos[0] += deltaX;
        camera->pos[1] += deltaY;

        // Limitar la posición de la cámara dentro de los bordes de la pantalla
        camera->pos[0] = (camera->pos[0] < 0) ? 0 : (camera->pos[0] > screenWidth) ? screenWidth : camera->pos[0];
        camera->pos[1] = (camera->pos[1] < 0) ? 0 : (camera->pos[1] > screenHeight) ? screenHeight : camera->pos[1];

        // Actualizar la posición previa del mouse
        prevMouseX = controls->coords[0];
        prevMouseY = controls->coords[1];
    } else {
        // Reiniciar en caso de que se deje de hacer clic
        firstClick = true;
    }
}