#include <YSI\y_hooks>

// Global interior define
#define MAPS_WANTEDHACKERBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Wantedhacker base points
#define WANTEDHACKERBASE_POINT   -1510.6661, 1975.3440, 48.4219

// Map variables
new object_wantedHackerBase[9];
new pickup_wantedHackerBase[1];
new text3D_wantedHackerBase[1];
new actor_wantedHackerBase[1];
new vehicle_wantedHackerBase[3];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_wantedHackerBase[0] = CreateDynamicPickup(1254, 1, WANTEDHACKERBASE_POINT, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR); // Wanted codes point

    // 3DTextLabels
    text3D_wantedHackerBase[0] = _:CreateDynamic3DTextLabel("Wanted-Hacker Codes\n" COLOR_HEX_WHITE "Tippe /Wcodes", COLOR_BLUE, WANTEDHACKERBASE_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_WANTEDHACKERBASE_INTERIOR); // Job clothes point
    
    // Actors
    actor_wantedHackerBase[0] = CreateDynamicActor(112, -1511.4948, 1978.6263, 48.4171, 345.9610, .worldid = VW_MAIN, .interiorid = MAPS_WANTEDHACKERBASE_INTERIOR); // sitting guy
    ApplyDynamicActorAnimation(actor_wantedHackerBase[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);
    
    // Vehicles
    vehicle_wantedHackerBase[0] = AddStaticVehicleEx(459, -1493.4634, 1958.9503, 48.3757, 2.6407, 1, 1, 60*10); // wantedhacker
    vehicle_wantedHackerBase[1] = AddStaticVehicleEx(482, -1500.8882, 1973.8467, 48.4035, 179.9305, 1, 1, 60*10); // wantedhacker
    vehicle_wantedHackerBase[2] = AddStaticVehicleEx(459, -1505.4424, 1958.8423, 48.3728, 359.6167, 3, 3, 60*10); // wantedhacker

    // Objects
    object_wantedHackerBase[0] = CreateDynamicObject(3388, -1513.9000, 1971.5999, 47.4000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[1] = CreateDynamicObject(3388, -1513.9000, 1972.5999, 47.4000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[2] = CreateDynamicObject(3390, -1513.8000, 1974.8000, 47.4000, 0.0000, 0.0000, 179.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[3] = CreateDynamicObject(3388, -1514.0000, 1976.8000, 47.4000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[4] = CreateDynamicObject(3388, -1514.0000, 1977.8000, 47.4000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[5] = CreateDynamicObject(3388, -1514.0000, 1978.8000, 47.4000, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[6] = CreateDynamicObject(3393, -1511.4000, 1971.5999, 47.4000, 0.0000, 0.0000, 271.0000, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[7] = CreateDynamicObject(3393, -1511.5996, 1979.1992, 47.4000, 0.0000, 0.0000, 87.9949, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_wantedHackerBase[8] = CreateDynamicObject(2121, -1511.6303, 1977.9743, 47.8271, 0.0000, 0.0000, 165.1999, VW_MAIN, MAPS_WANTEDHACKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}