#include <YSI\y_hooks>

// Global interior define
#define MAPS_BIKERENTAL_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Bike rental in LS points
#define BIKERENTAL_NOOBSPAWN_COORDS       791.4501, -1341.0048, 13.5469
#define BIKERENTAL_DRIVINGSCHOOL_COORDS   1242.3182, -1857.9050, 13.5469
#define BIKERENTAL_CITYHALL_COORDS        1493.4347, -1741.1992, 13.5469

// Map variables
new object_bikeRental[16];
new pickup_bikeRental[3];
new text3D_bikeRental[3];
new actor_bikeRental[3];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    pickup_bikeRental[0] = CreateDynamicPickup(1274, 1, BIKERENTAL_NOOBSPAWN_COORDS, VW_MAIN, MAPS_BIKERENTAL_INTERIOR); // Bike rental noob spawn
    pickup_bikeRental[1] = CreateDynamicPickup(1274, 1, BIKERENTAL_DRIVINGSCHOOL_COORDS, VW_MAIN, MAPS_BIKERENTAL_INTERIOR); // Bike rental driving school

    // 3DTextLabels
    text3D_bikeRental[0] = _:CreateDynamic3DTextLabel("Zweiradverleih\n{FFFFFF}Fahrzeuge hier mieten\n{33EE55}/Mieten", 0x33EE55FF, BIKERENTAL_NOOBSPAWN_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BIKERENTAL_INTERIOR);
    text3D_bikeRental[1] = _:CreateDynamic3DTextLabel("Zweiradverleih\n{FFFFFF}Fahrzeuge hier mieten\n{33EE55}/Mieten", 0x33EE55FF, BIKERENTAL_DRIVINGSCHOOL_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BIKERENTAL_INTERIOR);

    // Actors
    actor_bikeRental[1] = CreateDynamicActor(52, 1242.4252, -1860.8560, 13.5469, 359.4532, .worldid = VW_MAIN, .interiorid = MAPS_BIKERENTAL_INTERIOR); // Other bike guy
    ApplyDynamicActorAnimation(actor_bikeRental[1], "MUSCULAR", "MuscleIdle", 4.0, 1, 0, 0, 0, 0);
    actor_bikeRental[2] = CreateDynamicActor(51, 788.2233, -1341.1628, 13.5469, 267.0804, .worldid = VW_MAIN, .interiorid = MAPS_BIKERENTAL_INTERIOR); // Black bike guy
    ApplyDynamicActorAnimation(actor_bikeRental[2], "MUSCULAR", "MuscleIdle", 4.0, 1, 0, 0, 0, 0);

	// Objects
    /*object_bikeRental[0] = CreateDynamicObject(3861, 1496.144165, -1717.231933, 14.176877, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[1] = CreateDynamicObject(1514, 1495.362182, -1717.618286, 14.026882, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[2] = CreateDynamicObject(1514, 1496.942260, -1717.618286, 14.026882, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[3] = CreateDynamicObject(19564, 1496.375610, -1717.710693, 13.826882, -86.800003, 0.000000, 0.000000, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[4] = CreateDynamicObject(19564, 1495.965209, -1717.710693, 13.826882, -86.800003, 0.000000, 0.000000, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    */
    object_bikeRental[5] = CreateDynamicObject(3861, 1242.276245, -1860.037597, 13.662813, 0.000000, -0.000002, -178.900024, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[6] = CreateDynamicObject(1514, 1241.612670, -1859.639648, 13.545246, 0.000000, -0.000002, -178.900024, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[7] = CreateDynamicObject(1514, 1243.053222, -1859.612060, 13.545246, 0.000000, -0.000002, -178.900024, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[8] = CreateDynamicObject(19564, 1242.437255, -1859.340576, 13.342588, -89.599922, -0.000358, -178.900390, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[9] = CreateDynamicObject(19564, 1242.126953, -1859.346557, 13.342588, -89.599922, -0.000358, -178.900390, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[10] = CreateDynamicObject(3861, 788.916198, -1341.082031, 13.662813, 0.000000, 0.000000, 89.999977, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[11] = CreateDynamicObject(1514, 789.438964, -1341.880615, 13.546884, 0.000000, 0.000000, 90.400009, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[12] = CreateDynamicObject(1514, 789.428100, -1340.310302, 13.546884, 0.000000, 0.000000, 90.400009, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[13] = CreateDynamicObject(19564, 789.634277, -1340.928100, 13.356876, 91.599967, 0.000000, -91.600021, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[14] = CreateDynamicObject(19564, 789.623046, -1341.328002, 13.356876, 91.599967, 0.000000, -91.600021, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_bikeRental[15] = CreateDynamicObject(1239, 787.512023, -1341.100830, 14.196878, 0.000000, 0.000000, -87.099975, VW_MAIN, MAPS_BIKERENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
