#include <YSI\y_hooks>

// Global interior define
#define MAPS_TRUCKERBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Trucker points
#define TRUCKERBASE_JOBSKIN_POINT   43.5684, -261.4508, 1.8305

// Map variables
new object_truckerBase[5];
new pickup_truckerBase[1];
new text3D_truckerBase[1];
new vehicle_truckerBase[18];

hook OnPlayerConnect(playerid) {
	RemoveBuildingForPlayer(playerid, 12956, 96.3281, -261.1953, 3.8594, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
	// Pickups
	pickup_truckerBase[0] = CreateDynamicPickup(1275, 1, TRUCKERBASE_JOBSKIN_POINT, VW_MAIN, MAPS_TRUCKERBASE_INTERIOR); // Job skin

    // 3DTextLabels
    text3D_truckerBase[0] = _:CreateDynamic3DTextLabel("Arbeitskleidung für Trucker\n" COLOR_HEX_WHITE "Tippe /Jobkleidung", COLOR_YELLOW, TRUCKERBASE_JOBSKIN_POINT, 25.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TRUCKERBASE_INTERIOR); // Job skin point
    
    // Vehicles
	vehicle_truckerBase[0] = AddStaticVehicleEx(515, 111.9806, -271.2436, 2.1045, 90.0622, 206, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[1] = AddStaticVehicleEx(515, 111.9751, -263.3154, 2.1953, 90.0618, 206, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[2] = AddStaticVehicleEx(515, 111.9673, -256.0652, 2.2001, 90.0614, 206, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[3] = AddStaticVehicleEx(515, 111.9596, -248.9178, 2.2002, 90.0614, 206, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[4] = AddStaticVehicleEx(515, 111.9519, -241.7516, 2.2002, 90.0614, 206, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[5] = AddStaticVehicleEx(435, 124.0474, -271.2945, 2.2203, 90.1387, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[6] = AddStaticVehicleEx(435, 123.9199, -263.5539, 2.1730, 90.0605, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[7] = AddStaticVehicleEx(435, 123.8529, -256.0350, 2.1798, 90.1762, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[8] = AddStaticVehicleEx(435, 123.9129, -248.8182, 2.2209, 90.1592, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[9] = AddStaticVehicleEx(435, 123.8932, -241.5547, 2.2267, 90.1596, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[10] = AddStaticVehicleEx(584, 91.2023, -286.9339, 2.7498, 359.6140, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[11] = AddStaticVehicleEx(584, 78.0325, -286.9543, 2.7593, 0.0933, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[12] = AddStaticVehicleEx(584, 52.0501, -286.0643, 2.8832, 0.1037, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[13] = AddStaticVehicleEx(584, 65.0615, -286.4729, 2.7277, 0.1350, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[14] = AddStaticVehicleEx(514, 65.0370, -274.7122, 2.1284, 0.0764, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[15] = AddStaticVehicleEx(514, 52.4016, -274.7278, 2.2399, 0.0784, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[16] = AddStaticVehicleEx(514, 77.4810, -274.7199, 2.0988, 0.0407, 252, 1, 60 * 10); // neue trucker base
	vehicle_truckerBase[17] = AddStaticVehicleEx(514, 90.6049, -274.7139, 2.1904, 0.0407, 252, 1, 60 * 10); // neue trucker base

	// Objects
    object_truckerBase[0] = CreateDynamicObject(19464, 73.9355, -221.0299, 1.4654, 0.0000, 0.0000, -92.1000, VW_MAIN, MAPS_TRUCKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_truckerBase[0], 0, 13659, "8bars", "Upt_Fence_Mesh", 0xFFFFFFFF);
    object_truckerBase[1] = CreateDynamicObject(19464, 56.1675, -220.3786, 1.4654, 0.0000, 0.0000, -92.1000, VW_MAIN, MAPS_TRUCKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_truckerBase[1], 0, 13659, "8bars", "Upt_Fence_Mesh", 0xFFFFFFFF);
    object_truckerBase[2] = CreateDynamicObject(19464, 62.0935, -220.5958, 1.4654, 0.0000, 0.0000, -92.1000, VW_MAIN, MAPS_TRUCKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_truckerBase[2], 0, 13659, "8bars", "Upt_Fence_Mesh", 0xFFFFFFFF);
    object_truckerBase[3] = CreateDynamicObject(19464, 68.0095, -220.8126, 1.4654, 0.0000, 0.0000, -92.1000, VW_MAIN, MAPS_TRUCKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_truckerBase[3], 0, 13659, "8bars", "Upt_Fence_Mesh", 0xFFFFFFFF);
    object_truckerBase[4] = CreateDynamicObject(19464, 50.2415, -220.1615, 1.4654, 0.0000, 0.0000, -92.1000, VW_MAIN, MAPS_TRUCKERBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_truckerBase[4], 0, 13659, "8bars", "Upt_Fence_Mesh", 0xFFFFFFFF);
}
