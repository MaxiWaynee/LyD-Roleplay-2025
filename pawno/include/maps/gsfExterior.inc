#include <YSI\y_hooks>

// Global interior define
#define MAPS_GSFEXTERIOR_INTERIOR      0
#define MAPS_GSFINTERIOR_INTERIOR      3

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// GSF points
#define GSF_INTERIOR_ENTER_COORDS        2495.3547, -1690.6273, 14.7656
#define GSF_INTERIOR_EXIT_COORDS         2495.9873, -1692.3297, 1014.7422
#define GSF_INTERIOR_ENTER_FACING        180.0
#define GSF_INTERIOR_EXIT_FACING         0.0

// Map variables

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {

}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
}
