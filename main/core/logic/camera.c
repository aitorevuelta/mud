#include <global.h>          // Global funtzioak eta egitura orokorrak
#include <controls.h>        // Kontrolen kudeaketa
#include <camera.h>           // Kamera egituren kudeaketa

static bool firstClick = true;   // Lehenengo klikaren egoera gordetzen duen bandera
static int prevMouseX = 0;       // Aurreko saguen kokapenaren X koordenada
static int prevMouseY = 0;       // Aurreko saguen kokapenaren Y koordenada

// Kamera eguneratze nagusia
void updateCamera(CAMERA* camera, CONTROLS controls, int screenWidth, int screenHeight) {
    updateCameraZoom(camera, controls);         // Zoom-a eguneratzen
    updateCameraPosition(camera, controls, screenWidth, screenHeight);  // Kamera posizioa eguneratzen
}

// Kamera zoom-a eguneratzeko logika
void updateCameraZoom(CAMERA* camera, CONTROLS controls) {
    if (controls.scroll != 0) {
        // Zoom-a doikuntza leunki egitea
        float zoomDelta = controls.scroll * 0.06f;   // Scrollaren arabera doikuntza
        float newZoom = camera->zoom + zoomDelta;    // Zoom berria

        // Zooma mugarik gabekoan mugatzen
        camera->zoom = (newZoom < 0.75f) ? 0.75f : (newZoom > 2.5f) ? 2.5f : newZoom;
    }
}

// Kamera posizioa eguneratzeko logika
void updateCameraPosition(CAMERA* camera, CONTROLS controls, int screenWidth, int screenHeight) {
    if (controls.click) {
        if (firstClick) {
            // Lehenengo klikaren kokapenak gordetzen dira
            prevMouseX = controls.coords[0];
            prevMouseY = controls.coords[1];
            firstClick = false;   // Lehenengo klikaren bandera desaktibatuta
        }

        // Saguaren mugimenduaren aldagaiak kalkulatzen dira
        int deltaX = controls.coords[0] - prevMouseX;
        int deltaY = controls.coords[1] - prevMouseY;

        // Kamera posizioa eguneratzen
        camera->pos[0] += deltaX;
        camera->pos[1] += deltaY;

        // Kamera posizioa pantailaren barnean mugatzen
        if (camera->pos[0] < 0) camera->pos[0] = 0;          // Ez gainditu ezkerreko muga
        if (camera->pos[0] > screenWidth) camera->pos[0] = screenWidth;  // Ez gainditu eskuineko muga
        if (camera->pos[1] < 0) camera->pos[1] = 0;          // Ez gainditu goiko muga
        if (camera->pos[1] > screenHeight) camera->pos[1] = screenHeight;  // Ez gainditu beheko muga

        // Saguaren aurreko kokapena eguneratzen da
        prevMouseX = controls.coords[0];
        prevMouseY = controls.coords[1];
    } else {
        // Klika utzi bada, lehenengo klikaren bandera berriro martxan jarri
        firstClick = true;
    }
}
