#include <YSI\y_hooks>

// Global interior define
#define MAPS_GASPUMPS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Map variables
new object_gasPumps[14];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    object_gasPumps[0] = CreateDynamicObject(1686, 999.0615, -937.6771, 41.3414, 0.0000, 0.0000, 279.5312, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[1] = CreateDynamicObject(1686, 1001.7076, -937.3239, 41.3414, 0.0000, 0.0000, 277.8123, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[2] = CreateDynamicObject(1686, 1006.4114, -936.6081, 41.3414, 0.0000, 0.0000, 278.6717, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[3] = CreateDynamicObject(1686, 1008.8474, -936.2951, 41.3414, 0.0000, 0.0000, 276.0161, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[4] = CreateDynamicObject(1676, -2026.5290, 156.4273, 29.6199, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[5] = CreateDynamicObject(1478, 403.1084, -1166.8913, 78.2713, 0.0000, 0, 332.2102, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[6] = CreateDynamicObject(1215, 401.9956, -1166.8287, 78.2287, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[7] = CreateDynamicObject(1215, 396.2192, -1162.9082, 78.3815, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[8] = CreateDynamicObject(1215, 402.8871, -1151.4522, 76.7650, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[9] = CreateDynamicObject(1215, 400.1108, -1156.8591, 77.5547, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[10] = CreateDynamicObject(1215, 419.8918, -1162.5523, 76.2519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[11] = CreateDynamicObject(1215, 412.6167, -1158.2167, 76.2519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[12] = CreateDynamicObject(1432, 430.7764, -1135.64598, 72.7169, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gasPumps[13] = CreateDynamicObject(1432, 426.8181, -1133.3518, 72.7169, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_GASPUMPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}