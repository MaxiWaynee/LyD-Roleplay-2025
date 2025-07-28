#include <YSI\y_hooks>

// Global interior define
#define MAPS_OLDTIMERDEALERSHIP_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// Oldtimer dealership points
#define OLDTIMERDEALERSHIP_COORDS  1032.1476, -1416.0865, 13.5953

// Map variables
new object_oldtimerDealership[235];
new text3D_oldtimerDealership[1];
//new actor_oldtimerDealership[1];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 6153, 1007.3125, -1435.1641, 19.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 6154, 1003.1484, -1467.6953, 16.5781, 0.25);
	RemoveBuildingForPlayer(playerid, 6155, 941.2500, -1447.7734, 21.4219, 0.25);
	RemoveBuildingForPlayer(playerid, 6156, 990.0859, -1450.0859, 12.7734, 0.25);
	RemoveBuildingForPlayer(playerid, 6192, 988.9063, -1487.9063, 24.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 620, 930.2422, -1442.9766, 12.2813, 0.25);
	RemoveBuildingForPlayer(playerid, 6148, 941.2500, -1447.7734, 21.4219, 0.25);
	RemoveBuildingForPlayer(playerid, 6104, 1003.1484, -1467.6953, 16.5781, 0.25);
	RemoveBuildingForPlayer(playerid, 6152, 990.0859, -1450.0859, 12.7734, 0.25);
	RemoveBuildingForPlayer(playerid, 6151, 1007.3125, -1435.1641, 19.1172, 0.25);
	RemoveBuildingForPlayer(playerid, 621, 950.1250, -1420.2656, 12.1016, 0.25);
	RemoveBuildingForPlayer(playerid, 1307, 996.7578, -1415.3438, 12.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 1307, 1040.8906, -1415.3438, 12.3672, 0.25);
	RemoveBuildingForPlayer(playerid, 5783, 908.5391, -1384.3281, 24.5156, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
	// Map Icon
    CreateDynamicMapIcon(OLDTIMERDEALERSHIP_COORDS, 55, 0, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR);

    // 3DTextLabels
    text3D_oldtimerDealership[0] = _:CreateDynamic3DTextLabel("Autohaus - Oldtimer\n" COLOR_HEX_WHITE "Steige in ein beliebiges Fahrzeug deiner Wahl ein!", COLOR_BLUE, OLDTIMERDEALERSHIP_COORDS, 30.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_OLDTIMERDEALERSHIP_INTERIOR);

    // Actors
    //actor_oldtimerDealership[0] = CreateDynamicActor(76, 884.4954, -926.4102, 42.4216, 188.5966, .worldid = VW_MAIN, .interiorid = MAPS_OLDTIMERDEALERSHIP_INTERIOR); // Rich saleswoman
    //ApplyDynamicActorAnimation(actor_oldtimerDealership[0], "PED", "SEAT_idle", 4.0, 1, 0, 0, 0, 0);

	// Objects
	CreateObject(11317, 1019.09003, -1435.42004, 23.40000,   0.00000, 0.00000, 270.00000);
	
	object_oldtimerDealership[0] = CreateDynamicObject(19449, 989.60999, -1437.91003, 15.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[1] = CreateDynamicObject(19449, 989.60999, -1437.91003, 22.15000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[2] = CreateDynamicObject(19449, 989.59003, -1420.63000, 15.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[3] = CreateDynamicObject(19430, 989.60999, -1432.31006, 22.15000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[4] = CreateDynamicObject(19430, 989.60999, -1430.70996, 22.15000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[5] = CreateDynamicObject(19430, 989.60999, -1429.12000, 22.15000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[6] = CreateDynamicObject(19430, 989.60999, -1432.31006, 15.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[7] = CreateDynamicObject(19430, 989.60999, -1430.70996, 15.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[8] = CreateDynamicObject(19430, 989.60999, -1429.14001, 15.20000,   0.00000, 0.00000, -0.06000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[9] = CreateDynamicObject(19430, 989.60999, -1427.68994, 15.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[10] = CreateDynamicObject(19430, 989.60999, -1426.21997, 15.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[11] = CreateDynamicObject(19449, 994.34998, -1442.65002, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[12] = CreateDynamicObject(19449, 1003.96997, -1442.65002, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[13] = CreateDynamicObject(19449, 1013.58002, -1442.65002, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[14] = CreateDynamicObject(19449, 994.34998, -1442.65002, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[15] = CreateDynamicObject(19449, 1003.96997, -1442.65002, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[16] = CreateDynamicObject(19449, 1013.59003, -1442.66003, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[17] = CreateDynamicObject(19449, 1015.90997, -1452.79004, 22.15000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[18] = CreateDynamicObject(19449, 1020.70001, -1457.51001, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[19] = CreateDynamicObject(19449, 1015.90997, -1452.79004, 18.68000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[20] = CreateDynamicObject(19449, 1020.71997, -1457.52002, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[21] = CreateDynamicObject(19449, 1030.30005, -1457.51001, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[22] = CreateDynamicObject(19449, 1030.30005, -1457.51001, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[23] = CreateDynamicObject(19449, 1039.93005, -1457.51001, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[24] = CreateDynamicObject(19449, 1039.93005, -1457.51001, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[25] = CreateDynamicObject(19430, 1045.53003, -1457.51001, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[26] = CreateDynamicObject(19430, 1045.53003, -1457.51001, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[27] = CreateDynamicObject(19430, 1047.09998, -1457.51001, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[28] = CreateDynamicObject(19430, 1047.09998, -1457.51001, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[29] = CreateDynamicObject(19430, 1047.81995, -1457.51001, 22.15000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[30] = CreateDynamicObject(19430, 1047.83997, -1457.51001, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[31] = CreateDynamicObject(3851, 991.37000, -1435.45996, 20.16000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[32] = CreateDynamicObject(3851, 997.07001, -1441.09998, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[33] = CreateDynamicObject(3851, 1010.17999, -1441.12000, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[34] = CreateDynamicObject(3851, 1040.93994, -1457.18005, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[35] = CreateDynamicObject(3851, 997.07001, -1417.42004, 14.56000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[36] = CreateDynamicObject(3851, 997.07001, -1417.42004, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[37] = CreateDynamicObject(3851, 1010.19000, -1417.42004, 14.56000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[38] = CreateDynamicObject(3851, 1010.19000, -1417.42004, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[39] = CreateDynamicObject(3851, 1023.34003, -1417.42004, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[40] = CreateDynamicObject(3851, 1041.15002, -1417.42004, 20.16000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[41] = CreateDynamicObject(3851, 1023.34003, -1417.42004, 14.56000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[42] = CreateDynamicObject(3851, 1041.15002, -1417.42004, 14.56000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[43] = CreateDynamicObject(3850, 993.14001, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[44] = CreateDynamicObject(3850, 996.59003, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[45] = CreateDynamicObject(3850, 1000.04999, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[46] = CreateDynamicObject(3850, 1003.50000, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[47] = CreateDynamicObject(3850, 1006.96002, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[48] = CreateDynamicObject(3850, 1010.41998, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[49] = CreateDynamicObject(3850, 1013.88000, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[50] = CreateDynamicObject(3850, 1017.33002, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[51] = CreateDynamicObject(3850, 1020.78998, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[52] = CreateDynamicObject(3850, 1024.25000, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[53] = CreateDynamicObject(3850, 1027.70996, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[54] = CreateDynamicObject(3850, 1031.17004, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[55] = CreateDynamicObject(3850, 1034.62000, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[56] = CreateDynamicObject(3850, 1038.06995, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[57] = CreateDynamicObject(3850, 1041.52002, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[58] = CreateDynamicObject(3850, 1044.97998, -1423.23999, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[59] = CreateDynamicObject(3850, 1017.47998, -1429.03003, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[60] = CreateDynamicObject(3850, 1020.94000, -1429.03003, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[61] = CreateDynamicObject(3850, 1024.39001, -1429.03003, 18.71000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[62] = CreateDynamicObject(3850, 1026.10999, -1430.76001, 18.71000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[63] = CreateDynamicObject(957, 1020.87000, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[64] = CreateDynamicObject(957, 1026.06006, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[65] = CreateDynamicObject(957, 1031.51001, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[66] = CreateDynamicObject(957, 1037.37000, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[67] = CreateDynamicObject(957, 1043.18005, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[68] = CreateDynamicObject(957, 1015.31000, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[69] = CreateDynamicObject(957, 1006.41998, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[70] = CreateDynamicObject(957, 999.85999, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[71] = CreateDynamicObject(957, 992.53003, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[72] = CreateDynamicObject(957, 992.53003, -1437.82996, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[73] = CreateDynamicObject(957, 999.85999, -1437.82996, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[74] = CreateDynamicObject(957, 1006.41998, -1437.82996, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[75] = CreateDynamicObject(957, 1014.77002, -1437.82996, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[76] = CreateDynamicObject(957, 992.53003, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[77] = CreateDynamicObject(957, 999.85999, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[78] = CreateDynamicObject(957, 1006.41998, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[79] = CreateDynamicObject(957, 1015.31000, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[80] = CreateDynamicObject(957, 1020.87000, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[81] = CreateDynamicObject(957, 1026.06006, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[82] = CreateDynamicObject(957, 1031.51001, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[83] = CreateDynamicObject(957, 1037.37000, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[84] = CreateDynamicObject(957, 1043.18005, -1420.51001, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[85] = CreateDynamicObject(957, 992.53003, -1430.75000, 22.14000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[86] = CreateDynamicObject(957, 992.53003, -1437.82996, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[87] = CreateDynamicObject(957, 999.85999, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[88] = CreateDynamicObject(957, 999.85999, -1437.82996, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[89] = CreateDynamicObject(957, 1006.41998, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[90] = CreateDynamicObject(957, 1006.41998, -1437.82996, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[91] = CreateDynamicObject(957, 1014.77002, -1437.82996, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[92] = CreateDynamicObject(957, 1015.31000, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[93] = CreateDynamicObject(957, 1026.06006, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[94] = CreateDynamicObject(957, 1031.51001, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[95] = CreateDynamicObject(957, 1037.37000, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[96] = CreateDynamicObject(957, 1043.18005, -1430.75000, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[97] = CreateDynamicObject(957, 1043.18005, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[98] = CreateDynamicObject(957, 1037.37000, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[99] = CreateDynamicObject(957, 1031.51001, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[100] = CreateDynamicObject(957, 1026.06006, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[101] = CreateDynamicObject(957, 1015.31000, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[102] = CreateDynamicObject(957, 1006.41998, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[103] = CreateDynamicObject(957, 999.85999, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[104] = CreateDynamicObject(957, 992.53003, -1425.19995, 16.55000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[105] = CreateDynamicObject(625, 1046.47998, -1419.83997, 13.47000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[106] = CreateDynamicObject(625, 1036.23999, -1419.83997, 13.47000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[107] = CreateDynamicObject(625, 1018.59003, -1419.83997, 13.47000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[108] = CreateDynamicObject(625, 1005.40002, -1419.83997, 13.47000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[109] = CreateDynamicObject(625, 995.71997, -1419.83997, 13.47000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[110] = CreateDynamicObject(632, 1026.43005, -1432.35999, 18.62000,   0.00000, 0.00000, -131.52000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[111] = CreateDynamicObject(632, 1035.94995, -1432.35999, 18.62000,   0.00000, 0.00000, -131.52000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[112] = CreateDynamicObject(632, 1046.08997, -1432.35999, 13.02000,   0.00000, 0.00000, -90.06000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[113] = CreateDynamicObject(632, 1015.04999, -1433.83997, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[114] = CreateDynamicObject(632, 1015.04999, -1440.92004, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[115] = CreateDynamicObject(632, 1004.00000, -1440.92004, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[116] = CreateDynamicObject(632, 992.67999, -1440.92004, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[117] = CreateDynamicObject(632, 1004.00000, -1424.50000, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[118] = CreateDynamicObject(632, 992.67999, -1424.50000, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[119] = CreateDynamicObject(632, 1015.04999, -1424.50000, 18.62000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[120] = CreateDynamicObject(632, 1035.93994, -1424.50000, 18.62000,   0.00000, 0.00000, -131.52000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[121] = CreateDynamicObject(632, 1046.08997, -1424.50000, 18.62000,   0.00000, 0.00000, -90.06000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[122] = CreateDynamicObject(632, 1026.43005, -1424.50000, 18.62000,   0.00000, 0.00000, -131.52000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[123] = CreateDynamicObject(632, 1046.08997, -1432.35999, 18.60000,   0.00000, 0.00000, -90.06000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[124] = CreateDynamicObject(632, 1035.94995, -1432.35999, 13.02000,   0.00000, 0.00000, -131.52000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[125] = CreateDynamicObject(632, 1015.04999, -1440.92004, 13.02000,   0.00000, 0.00000, -67.14000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[126] = CreateDynamicObject(19430, 1047.83997, -1457.51001, 18.68000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[127] = CreateDynamicObject(19430, 1047.79834, -1415.91284, 14.91900,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[128] = CreateDynamicObject(19449, 1048.55383, -1443.17578, 17.56800,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[129] = CreateDynamicObject(19449, 1048.56104, -1452.75623, 17.56800,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[130] = CreateDynamicObject(19449, 1048.56104, -1452.75623, 14.06600,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[131] = CreateDynamicObject(19449, 1039.93005, -1457.51001, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[132] = CreateDynamicObject(19430, 1045.53003, -1457.51001, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[133] = CreateDynamicObject(19430, 1047.09998, -1457.51001, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[134] = CreateDynamicObject(19430, 1047.83997, -1457.51001, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[135] = CreateDynamicObject(19449, 1030.30005, -1457.51001, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[136] = CreateDynamicObject(19449, 1020.71997, -1457.52002, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[137] = CreateDynamicObject(19449, 1015.90997, -1452.79004, 15.24600,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[138] = CreateDynamicObject(19449, 1013.59003, -1442.66003, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[139] = CreateDynamicObject(19449, 1003.96997, -1442.65002, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[140] = CreateDynamicObject(19449, 994.34998, -1442.65002, 15.24600,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[141] = CreateDynamicObject(19449, 989.60999, -1437.91003, 18.68000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[142] = CreateDynamicObject(19430, 989.60999, -1432.31006, 18.68000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[143] = CreateDynamicObject(19430, 989.60999, -1430.70996, 18.68000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[144] = CreateDynamicObject(19430, 989.60999, -1429.12000, 18.68000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[145] = CreateDynamicObject(19449, 1039.93005, -1457.51001, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[146] = CreateDynamicObject(19430, 1047.83997, -1457.51001, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[147] = CreateDynamicObject(19430, 1047.09998, -1457.51001, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[148] = CreateDynamicObject(19430, 1045.53003, -1457.51001, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[149] = CreateDynamicObject(19449, 1030.30005, -1457.51001, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[150] = CreateDynamicObject(19449, 1020.71997, -1457.52002, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[151] = CreateDynamicObject(19449, 1015.90997, -1452.79004, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[152] = CreateDynamicObject(19449, 1013.59003, -1442.66003, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[153] = CreateDynamicObject(19449, 1003.96997, -1442.65002, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[154] = CreateDynamicObject(19449, 994.34998, -1442.65002, 11.74400,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[155] = CreateDynamicObject(19449, 989.59003, -1420.63000, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[156] = CreateDynamicObject(19430, 989.60999, -1426.21997, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[157] = CreateDynamicObject(19430, 989.60999, -1427.68994, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[158] = CreateDynamicObject(19430, 989.60999, -1429.14001, 11.74400,   0.00000, 0.00000, -0.06000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[159] = CreateDynamicObject(19430, 989.60999, -1430.70996, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[160] = CreateDynamicObject(19430, 989.60999, -1432.31006, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[161] = CreateDynamicObject(19449, 989.60999, -1437.91003, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[162] = CreateDynamicObject(19449, 1015.90997, -1447.55396, 18.68000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[163] = CreateDynamicObject(19449, 1015.90997, -1447.24597, 22.15000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[164] = CreateDynamicObject(19449, 1015.90997, -1446.63000, 15.24600,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[165] = CreateDynamicObject(19449, 1015.90997, -1446.93799, 11.74400,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[166] = CreateDynamicObject(3660, 972.81122, -1441.35815, 14.94820,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[167] = CreateDynamicObject(3660, 980.31824, -1441.35815, 14.94820,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[168] = CreateDynamicObject(3660, 963.76160, -1425.79126, 14.94820,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[169] = CreateDynamicObject(10183, 984.84369, -1436.56140, 12.36220,   0.00000, 0.00000, -135.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[170] = CreateDynamicObject(19126, 1047.59875, -1415.69873, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[171] = CreateDynamicObject(19126, 964.01495, -1415.73938, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[172] = CreateDynamicObject(19126, 990.51239, -1415.67493, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[173] = CreateDynamicObject(19126, 1003.83630, -1415.63428, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[174] = CreateDynamicObject(19126, 1016.75958, -1415.71655, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[175] = CreateDynamicObject(19126, 1029.99622, -1415.68359, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[176] = CreateDynamicObject(19126, 1034.89880, -1415.67200, 12.71442,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[177] = CreateDynamicObject(2773, 1035.39026, -1414.88037, 12.84010,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[178] = CreateDynamicObject(2773, 1029.01843, -1414.88733, 12.84010,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[179] = CreateDynamicObject(632, 1037.81335, -1416.41626, 12.86830,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[180] = CreateDynamicObject(632, 1028.46252, -1416.27954, 12.86830,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[181] = CreateDynamicObject(3660, 963.76160, -1431.67932, 14.94820,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[182] = CreateDynamicObject(8661, 1033.20068, -1425.84314, 12.49430,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[183] = CreateDynamicObject(8661, 1033.61780, -1443.97278, 12.52830,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[184] = CreateDynamicObject(8661, 1029.46973, -1460.68213, 12.52830,   0.00000, 0.00000, -8.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[185] = CreateDynamicObject(8661, 1026.05811, -1472.60498, 12.49430,   0.00000, 0.00000, -8.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[186] = CreateDynamicObject(8661, 993.71497, -1425.81738, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[187] = CreateDynamicObject(8661, 953.85577, -1425.75537, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[188] = CreateDynamicObject(8661, 993.67920, -1445.76648, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[189] = CreateDynamicObject(8661, 993.67291, -1463.90649, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[190] = CreateDynamicObject(8661, 993.46008, -1473.10046, 12.46030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[191] = CreateDynamicObject(8661, 953.75696, -1445.62122, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[192] = CreateDynamicObject(8661, 953.75067, -1465.55347, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[193] = CreateDynamicObject(8661, 954.03864, -1472.78931, 12.46030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[194] = CreateDynamicObject(8661, 945.71039, -1471.58142, 12.42630,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[195] = CreateDynamicObject(8661, 916.69269, -1461.16260, 12.35830,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[196] = CreateDynamicObject(8661, 918.52002, -1441.23840, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[197] = CreateDynamicObject(8661, 915.45135, -1464.31519, 12.16972,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[198] = CreateDynamicObject(19449, 1048.58716, -1443.15564, 14.06600,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[199] = CreateDynamicObject(19449, 1048.56104, -1452.75623, 21.03650,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[200] = CreateDynamicObject(19449, 1048.56104, -1452.75623, 22.27391,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[201] = CreateDynamicObject(19449, 1048.55383, -1443.17578, 20.97844,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[202] = CreateDynamicObject(19449, 1048.55383, -1443.17578, 22.91037,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[203] = CreateDynamicObject(6104, 1003.00793, -1468.03955, 16.14505,   0.00000, 0.00000, -2.04000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[204] = CreateDynamicObject(647, 950.80115, -1418.30005, 13.94000,   356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[205] = CreateDynamicObject(621, 950.39423, -1422.38330, 12.10156,   356.85840, 0.00000, -1.29154, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[206] = CreateDynamicObject(1223, 953.25977, -1419.75146, 12.93322,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[207] = CreateDynamicObject(1223, 954.30151, -1438.14587, 12.93322,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[208] = CreateDynamicObject(1223, 954.33063, -1457.30322, 12.93322,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[209] = CreateDynamicObject(1223, 953.27716, -1476.65918, 12.93322,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[210] = CreateDynamicObject(970, 1006.37946, -1417.46082, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[211] = CreateDynamicObject(970, 1010.56189, -1417.45715, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[212] = CreateDynamicObject(970, 1014.74182, -1417.47070, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[213] = CreateDynamicObject(970, 1019.64996, -1417.47522, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[214] = CreateDynamicObject(970, 1023.81018, -1417.47827, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[215] = CreateDynamicObject(970, 1027.95032, -1417.47778, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[216] = CreateDynamicObject(970, 1037.35522, -1417.43420, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[217] = CreateDynamicObject(970, 1041.53723, -1417.44238, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[218] = CreateDynamicObject(970, 1045.71814, -1417.43115, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[219] = CreateDynamicObject(970, 1000.72540, -1417.45691, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[220] = CreateDynamicObject(970, 996.55719, -1417.43665, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[221] = CreateDynamicObject(970, 992.42340, -1417.44104, 13.06526,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[222] = CreateDynamicObject(19430, 1047.79834, -1415.91284, 11.40993,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[223] = CreateDynamicObject(19449, 1048.56104, -1452.75623, 10.60799,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[224] = CreateDynamicObject(19449, 1048.58716, -1443.15564, 10.57388,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[225] = CreateDynamicObject(8661, 934.65662, -1434.65112, 12.35630,   0.00000, 0.00000, -87.84000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[226] = CreateDynamicObject(6148, 941.25000, -1447.77344, 21.15820,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[227] = CreateDynamicObject(620, 930.24219, -1442.97656, 11.38040,   356.85840, 0.00000, -2.61799);
	object_oldtimerDealership[228] = CreateDynamicObject(3578, 958.53461, -1479.51086, 11.76245,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[229] = CreateDynamicObject(8661, 953.85577, -1425.75537, 12.29030,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[230] = CreateDynamicObject(8661, 969.71729, -1415.83569, 2.30056,   90.00000, 90.00000, 89.70000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[231] = CreateDynamicObject(8661, 1009.47339, -1416.05200, 2.36537,   90.00000, 90.00000, 89.70000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[232] = CreateDynamicObject(3578, 958.35870, -1416.02747, 11.61163,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[233] = CreateDynamicObject(1984, 1019.73773, -1429.48254, 12.54280,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_oldtimerDealership[234] = CreateDynamicObject(1998, 1017.80933, -1430.53735, 12.58780,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_OLDTIMERDEALERSHIP_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
