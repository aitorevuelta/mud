#include <global.h>

#include <controls.h>

#include <camera.h>

void updateCamera(CAMERA* camera, CONTROLS* controls) {
    // Movimiento de la cámara mientras arrastras
    if (controls->click) { // Solo mover la cámara si el mouse está presionado
        camera->pos[0] -= controls->coords[0]; // Movimiento horizontal (invertido)
        camera->pos[1] -= controls->coords[1]; // Movimiento vertical (invertido)
    }
    
    // Ajuste del zoom
    if (controls->scroll != 0) {
        camera->zoom += controls->scroll * 0.1f; // Cambiar el zoom
        if (camera->zoom < 0.1f) camera->zoom = 0.1f; // Límite inferior del zoom
    }
}