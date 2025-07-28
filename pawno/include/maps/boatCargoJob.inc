#include <YSI\y_hooks>

// Global interior define
#define MAPS_BOATCARGOJOB_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Boat cargo job points
#define BOATCARGOJOB_JOBSKIN_POINT       2487.6289, -2250.2695, 3.0000
//#define BOATCARGOJOB_LOADGARGO_POINT     2615.2017, -2322.4878, 1.8984
//#define BOATCARGOJOB_UNLOADCARGO_POINT   2293.6399, 522.7067, 1.7944

// Map variables
new object_boatCargoJob[7];
new pickup_boatCargoJob[1];
new text3D_boatCargoJob[1];
new vehicle_boatCargoJob[5];

hook OnPlayerConnect(playerid) {
	// --
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
	// Pickups
    //pickup_boatCargoJob[0] = CreateDynamicPickup(1279, 1, BOATCARGOJOB_LOADGARGO_POINT, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR); // Load cargo point
    //pickup_boatCargoJob[1] = CreateDynamicPickup(1279, 1, BOATCARGOJOB_UNLOADCARGO_POINT, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR); // Unload cargo point
    pickup_boatCargoJob[0] = CreateDynamicPickup(1275, 1, BOATCARGOJOB_JOBSKIN_POINT, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR); // Job skin point

    // 3DTextLabels
    //text3D_boatCargoJob[0] = _:CreateDynamic3DTextLabel("Schiffsfahrer\n" COLOR_HEX_WHITE "Tippe /Frachtladen", COLOR_BLUE, BOATCARGOJOB_LOADGARGO_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BOATCARGOJOB_INTERIOR); // Load cargo point
    //text3D_boatCargoJob[1] = _:CreateDynamic3DTextLabel("Schiffsfahrer\n" COLOR_HEX_WHITE "Tippe /Frachtentladen", COLOR_BLUE, BOATCARGOJOB_UNLOADCARGO_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BOATCARGOJOB_INTERIOR); // Unload cargo point
    text3D_boatCargoJob[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Schiffsfahrer\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, BOATCARGOJOB_JOBSKIN_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BOATCARGOJOB_INTERIOR); // Job skin point

    // Vehicles
    vehicle_boatCargoJob[0] = AddStaticVehicleEx(472, 2541.6123, -2257.8533, -0.3546, 179.7160, 1, 1, 60*10); // schiff
    vehicle_boatCargoJob[1] = AddStaticVehicleEx(472, 2489.6853, -2268.3591, -0.3919, 267.9600, 1, 1, 60*10); // schiff
    vehicle_boatCargoJob[2] = AddStaticVehicleEx(472, 2509.3716, -2268.9241, -0.1255, 270.0640, 1, 1, 60*10); // schiff
    vehicle_boatCargoJob[3] = AddStaticVehicleEx(472, 2532.5693, -2268.9958, -0.2065, 271.9193, 1, 1, 60*10); // schiff
    vehicle_boatCargoJob[4] = AddStaticVehicleEx(472, 2481.3464, -2256.9226, -0.1752, 179.9813, 1, 1, 60*10); // schiff

	// Objects
    object_boatCargoJob[0] = CreateDynamicObject(3043, 2294.1000, 545.2999, 2.2000, 0, 0, 180, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_boatCargoJob[1] = CreateDynamicObject(2934, 2298.3000, 525.9000, 2.2000, 0, 0, 0, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_boatCargoJob[2] = CreateDynamicObject(2934, 2298.3000, 525.9000, 5.0999, 0, 0, 0, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_boatCargoJob[3] = CreateDynamicObject(2934, 2290.3999, 529.7999, 2.2000, 0, 0, 18, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_boatCargoJob[4] = CreateDynamicObject(2669, 2298.3999, 532.4000, 2.0999, 0, 0, 180, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_boatCargoJob[5] = CreateDynamicObject(3569, 2291.1999, 612.2999, 12.399, 0, 0, 0, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_boatCargoJob[6] = CreateDynamicObject(3566, 2283.3000, 612.5999, 12.399, 0, 0, 0, VW_MAIN, MAPS_BOATCARGOJOB_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
