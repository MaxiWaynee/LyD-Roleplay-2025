#include <YSI\y_hooks>

// Global interior define
#define MAPS_LCNEXTERIOR_INTERIOR      0
#define MAPS_LCNINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// La Cosa Nostra interior points
#define LCN_INTERIOR_GANGSHOP_POINT            -784.4557, 496.9431, 1371.7422
// Map variables
new object_lcnInterior[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

}

hook OnGameModeInit() {
    // Objects
    object_lcnInterior[0] = CreateDynamicObject(19360, -791.964233, 495.070618, 1371.931519, 0.000000, 0.000000, 90.00000, VW_LCNINTERIOR, MAPS_LCNINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}