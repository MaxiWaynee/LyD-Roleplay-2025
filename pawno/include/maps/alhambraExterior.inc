#include <YSI\y_hooks>

// Global interior define
#define MAPS_ALHAMBRAEXTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

// Map variables
new object_alhambraExterior[15];
new actor_alhambraExterior[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Actors
    actor_alhambraExterior[0] = CreateDynamicActor(111, 1831.9216, -1683.7462, 13.5367, 90.3174, .worldid = VW_MAIN, .interiorid = MAPS_ALHAMBRAEXTERIOR_INTERIOR); // russian bouncer
    ApplyDynamicActorAnimation(actor_alhambraExterior[0], "COP_AMBIENT", "Coplook_loop", 4.1, 1, 0, 0, 0, 0);

    // Objects
    object_alhambraExterior[0] = CreateDynamicObject(2773, 1836.38379, -1680.96289, 12.87830, 0.66000, -0.30000, 90.47990, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[1] = CreateDynamicObject(2773, 1836.38721, -1684.00598, 12.87830, 0.66000, -0.30000, 90.47990, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[2] = CreateDynamicObject(2773, 1834.46643, -1684.02979, 12.93830, 2.10000, -0.90000, 90.47990, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[3] = CreateDynamicObject(2773, 1834.48242, -1680.98108, 12.93830, 2.10000, -0.90000, 90.47990, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[4] = CreateDynamicObject(2773, 1832.65234, -1680.55676, 13.01830, 2.10000, -0.90000, 62.82990, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[5] = CreateDynamicObject(2773, 1832.66833, -1684.48120, 13.01830, 2.04000, -0.96000, 118.46143, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[6] = CreateDynamicObject(18652, 1836.43091, -1679.08850, 15.30640, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[7] = CreateDynamicObject(18652, 1836.43091, -1681.07043, 15.30640, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[8] = CreateDynamicObject(18652, 1836.43091, -1683.02332, 15.30640, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[9] = CreateDynamicObject(18652, 1836.43091, -1684.79065, 15.30640, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[10] = CreateDynamicObject(18652, 1836.43091, -1685.75220, 15.30640, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[11] = CreateDynamicObject(19126, 1831.64429, -1680.10706, 13.07970, -1.02000, 1.98000, -31.20000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[12] = CreateDynamicObject(19126, 1831.65125, -1684.92554, 13.07970, -1.02000, 1.98000, -31.20000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[13] = CreateDynamicObject(1231, 1831.78076, -1689.52637, 15.16200, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_alhambraExterior[14] = CreateDynamicObject(1231, 1831.77502, -1675.31702, 15.16200, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_ALHAMBRAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}