#include <YSI\y_hooks>

// Global interior define
#define MAPS_TRIADSEXTERIOR_INTERIOR      0
#define MAPS_TRIADSINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;
#define TRIADS_INTERIOR_GANGSHOP_POINT            777.1221, -40.4455, 1000.5859

// Map variables
new object_triadsInterior[6];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

    return 1;
}

hook OnGameModeInit() {
	// Pickups

    // Actors

	// Objects
    object_triadsInterior[0] = CreateDynamicObject(19361, 968.365722,-53.542778,1001.894042, 0.00000, 0.00000, 0.00000, VW_TRIADSINTERIOR, MAPS_TRIADSINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}