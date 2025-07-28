#include <YSI\y_hooks>

// Global interior define
#define MAPS_YAKUZAEXTERIOR_INTERIOR      0
#define MAPS_YAKUZAINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;
#define YAKUZA_INTERIOR_GANGSHOP_POINT            2245.9250, 1696.2772, 1008.3594

// Yakuza interior points
// Map variables
new object_yakuzaInterior[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

}

hook OnGameModeInit() {
    // Actors

	// Objects
    object_yakuzaInterior[0] = CreateDynamicObject(18981, 2237.211426, 1656.288208, 998.949890, 0.000000, 0.000000, -90.00000, VW_YAKUZAINTERIOR, MAPS_YAKUZAINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}