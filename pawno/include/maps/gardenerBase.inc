#include <YSI\y_hooks>

// Global interior define
#define MAPS_GARDENERBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

// Gardener base points
#define GARDENERBASE_JOBSKIN_POINT    1565.7582, 23.2893, 24.1641

// Map variables
new object_gardenerBase[8];
new pickup_gardenerBase[1];
new text3D_gardenerBase[1];
new actor_gardenerBase[1];
new vehicle_gardenerBase[7];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Pickups
    pickup_gardenerBase[0] = CreateDynamicPickup(1275, 1, GARDENERBASE_JOBSKIN_POINT, VW_MAIN, MAPS_GARDENERBASE_INTERIOR); // Job clothes point

    // 3DTextLabels
    text3D_gardenerBase[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Gärtner\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, GARDENERBASE_JOBSKIN_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_GARDENERBASE_INTERIOR); // Job clothes point
    
    // Actors
    actor_gardenerBase[0] = CreateDynamicActor(161, 1566.9152, 21.6907, 24.1641, 96.7073, .worldid = VW_MAIN, .interiorid = MAPS_GARDENERBASE_INTERIOR); // smoking hillbilly
    ApplyDynamicActorAnimation(actor_gardenerBase[0], "SMOKING", "M_smk_in", 0.5, 1, 0, 0, 0, 0);

    // Vehicles
    vehicle_gardenerBase[0] = AddStaticVehicleEx(572, 1564.8389, 43.1613, 24.2453, 136.5115, 129, 129, 60*10); // lawn mower
    vehicle_gardenerBase[1] = AddStaticVehicleEx(572, 1584.8051, 45.1839, 24.6418, 112.7617, 129, 129, 60*10); // lawn mower
    vehicle_gardenerBase[2] = AddStaticVehicleEx(572, 1583.4629, 49.1419, 24.9340, 112.6888, 129, 129, 60*10); // lawn mower
    vehicle_gardenerBase[3] = AddStaticVehicleEx(572, 1570.1069, 31.8921, 23.8003,  93.6875, 129, 129, 60*10); // lawn mower
    vehicle_gardenerBase[4] = AddStaticVehicleEx(572, 1566.6692, 31.6986, 23.7482,  93.6835, 129, 129, 60*10); // lawn mower
    vehicle_gardenerBase[5] = AddStaticVehicleEx(572, 1547.3218, 23.9317, 23.7289, 282.9243, 129, 129, 60*10); // lawn mower
    vehicle_gardenerBase[6] = AddStaticVehicleEx(572, 1563.2639, 48.7524, 24.7672, 137.0455, 129, 129, 60*10); // lawn mower

    // Objects
    object_gardenerBase[0] = CreateDynamicObject(2060, 1549.86194, 13.38711, 23.32588, 0.00000, 0.00000, 42.24000, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[1] = CreateDynamicObject(2060, 1548.98865, 12.56712, 23.32588, 0.00000, 0.00000, 42.24000, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[2] = CreateDynamicObject(2060, 1549.94299, 12.64712, 23.32588, 0.00000, 0.00000, 42.24000, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[3] = CreateDynamicObject(2060, 1549.66113, 12.80368, 23.55104, 0.00000, 0.00000, 23.99997, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[4] = CreateDynamicObject(916, 1548.07727, 12.19396, 23.23752, 0.00000, 0.00000, 10.01999, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[5] = CreateDynamicObject(916, 1548.07727, 12.19396, 23.39811, 0.00000, 0.00000, 10.01999, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[6] = CreateDynamicObject(916, 1547.30701, 12.06796, 23.23752, 0.00000, 0.00000, 10.01999, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_gardenerBase[7] = CreateDynamicObject(2713, 1548.55701, 12.88363, 23.25443, 0.00000, 0.00000, 25.14000, VW_MAIN, MAPS_GARDENERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}