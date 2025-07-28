#include <YSI\y_hooks>

// Global interior define
#define MAPS_BOATRENTAL_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Boat rental in LS points
#define BOATRENTAL_COORDS    -72.2616, -567.8605, 3.0632

// Map variables
new object_boatRental[6];
new text3D_boatRental[1];
new actor_boatRental[1];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // 3DTextLabels
    text3D_boatRental[0] = _:CreateDynamic3DTextLabel("Bootsverleih\n" COLOR_HEX_WHITE "Steige in ein beliebiges Boot deiner Wahl ein!", COLOR_BLUE, BOATRENTAL_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_BOATRENTAL_INTERIOR);

    // Actors
    actor_boatRental[0] = CreateDynamicActor(154, -73.7655, -557.1809, 3.5920, 268.2356, .worldid = VW_MAIN, .interiorid = MAPS_BOATRENTAL_INTERIOR); // Shirtless dude
    ApplyDynamicActorAnimation(actor_boatRental[0], "GANGS", "leanIDLE", 4.0, 1, 0, 0, 0, 0);

	// Objects
	object_boatRental[0] = CreateDynamicObject(8557, -74.18366, -592.90991, -0.33781,   0.00000, 0.00000, 86.17582, VW_MAIN, MAPS_BOATRENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_boatRental[1] = CreateDynamicObject(9361, -76.04680, -556.54553, 5.03518,   0.00000, 0.00000, 40.49857, VW_MAIN, MAPS_BOATRENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_boatRental[2] = CreateDynamicObject(1984, -77.06577, -557.46478, 2.65995,   0.00000, 0.00000, 355.11841, VW_MAIN, MAPS_BOATRENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_boatRental[3] = CreateDynamicObject(2162, -78.83092, -559.13843, 2.66599,   0.00000, 0.00000, 265.26736, VW_MAIN, MAPS_BOATRENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_boatRental[4] = CreateDynamicObject(1671, -75.72526, -558.70087, 3.09344,   0.00000, 0.00000, 182.31647, VW_MAIN, MAPS_BOATRENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_boatRental[5] = CreateDynamicObject(2108, -74.66832, -553.19415, 2.68993,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BOATRENTAL_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
