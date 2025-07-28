#include <YSI\y_hooks>

// Global interior define
#define MAPS_PAINTBALLGYMLS_INTERIOR      6

// Local drawdistance & streamdistance setting
// static Float:STREAMDISTANCE = 350.0;
// static Float:DRAWDISTANCE   = 350.0;

// Paintball gym in LS Interior points
#define PAINTBALLGYMLS_INTERIOR_SPAWN_POINT1          768.1949, -23.0032, 1000.5859
#define PAINTBALLGYMLS_INTERIOR_SPAWN_POINT_FACING1   180.0

#define PAINTBALLGYMLS_INTERIOR_SPAWN_POINT2          768.1949, -46.5489, 1000.5859
#define PAINTBALLGYMLS_INTERIOR_SPAWN_POINT_FACING2   0.0

// Map variables

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 2627, 759.6328, -48.1250, 999.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 2629, 766.3047, -48.3047, 999.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 2755, 768.1406, -28.8047, 1001.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 2755, 762.2188, -28.8047, 1001.3125, 0.25);
    RemoveBuildingForPlayer(playerid, 2630, 769.2422, -47.8984, 999.6797, 0.25);
    RemoveBuildingForPlayer(playerid, 2755, 774.1641, -28.8047, 1001.3125, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
}