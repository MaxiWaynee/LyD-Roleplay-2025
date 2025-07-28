#include <YSI\y_hooks>

// Global interior define
#define MAPS_LSPDEXTERIOR_INTERIOR      0
#define MAPS_LSPDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 250.0;
static Float:DRAWDISTANCE   = 230.0;

// LSPD points
#define LSPD_INTERIOR_ENTER_COORDS		        1555.3770, -1675.5115, 16.1953
#define LSPD_INTERIOR_EXIT_COORDS		        1619.5063, -1377.3353, 1962.5280
#define LSPD_INTERIOR_ENTER_FACING		        0.0000
#define LSPD_INTERIOR_EXIT_FACING               270.0000
#define LSPD_STATEREPAIR_COORDS			        1585.9081, -1677.1216, 5.8970
#define LSPD_ARREST_COORDS                      1528.2202, -1677.7194, 5.8906
#define LSPD_HELI_STAIRS_POINT                  1565.0234,-1684.4841,28.3956
#define LSPD_HELI_STAIRS_POINT_FACING           90.0000
#define LSPD_INTERIOR_HELI_STAIRS_POINT         1626.2921, -1369.3011, 1962.5068
#define LSPD_INTERIOR_HELI_STAIRS_POINT_FACING  180.0000
#define LSPD_GATE_FOR_RANGE_COORDS	            1544.45618, -1622.11987, 12.93280
#define LSPD_GATE2_FOR_RANGE_COORDS	            1596.02783, -1638.10132, 14.59349
#define LSPD_GATE_OPEN_Z                        2.93280
#define LSPD_GATE_CLOSED_Z                      12.93280
#define LSPD_GATE2_OPEN_Z                        4.59349
#define LSPD_GATE2_CLOSED_Z                      14.59349

#define LSPD_INTERIOR_GARAGE_POINT              1642.4449, -1388.1652, 1962.5164
#define LSPD_INTERIOR_GARAGE_POINT_FACING       0.0000
#define LSPD_GARAGE_POINT                       1568.5732, -1689.9707, 6.2188
#define LSPD_GARAGE_POINT_FACING                270.0000

// Map variables
new object_lspdExterior[24];
new pickup_lspdExterior[4];
new text3D_lspdExterior[2];
new actor_lspdExterior[1];
new TOR_LSPD[2];


hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) 
{
	if (newkeys & KEY_SECONDARY_ATTACK) 
    {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_HELI_STAIRS_POINT)) 
		{ // Helicopter Stairway
			// -- Not needed to check if the user is a part of the executive
			SetPlayerFacingAngle(playerid, LSPD_INTERIOR_HELI_STAIRS_POINT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, LSPD_INTERIOR_HELI_STAIRS_POINT, MAPS_LSPDINTERIOR_INTERIOR, VW_LSPDINTERIOR);
			return 1;
		} 
		else if (IsPlayerInRangeOfPoint(playerid, 2.0, LSPD_GARAGE_POINT)) 
		{ // Garage point
			// -- Not needed to check if the user is a part of the executive
			SetPlayerFacingAngle(playerid, LSPD_INTERIOR_GARAGE_POINT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, LSPD_INTERIOR_GARAGE_POINT, MAPS_LSPDINTERIOR_INTERIOR, VW_LSPDINTERIOR);
			return 1;
		}
	}
	return 1;
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(LSPD_INTERIOR_ENTER_COORDS, 30, 0, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR);

	// Pickups
	pickup_lspdExterior[0] = CreateDynamicPickup(1239, 1, LSPD_STATEREPAIR_COORDS, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Staterepair
    pickup_lspdExterior[1] = CreateDynamicPickup(1247, 1, LSPD_ARREST_COORDS, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Arrest
    pickup_lspdExterior[2] = CreateDynamicPickup(19197, 1, LSPD_HELI_STAIRS_POINT, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Helicopter Stairway
    pickup_lspdExterior[3] = CreateDynamicPickup(19197, 1, LSPD_GARAGE_POINT, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR); // Garage Point

    // 3DTextLabels
    text3D_lspdExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, LSPD_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LSPDEXTERIOR_INTERIOR); // Staterepair
    text3D_lspdExterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Einsperrpunkt\n" COLOR_HEX_WHITE "Tippe /Arrest", COLOR_WHITE, LSPD_ARREST_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_LSPDEXTERIOR_INTERIOR); // /arrest
    
    // Actors
    actor_lspdExterior[0] = CreateDynamicActor(50, 1031.0018, -1619.6342, 6.2667, -0.1000); //Mechanic
    ApplyDynamicActorAnimation(actor_lspdExterior[0], "BD_FIRE", "M_SMKLEAN_LOOP", 4.0999, 1, 0, 0, 0, 0);

	// Vehicles
	
	// Objects
	object_lspdExterior[0] = CreateDynamicObject(3881, 1543.50684, -1620.11011, 14.21720,   0.00000, 0.00000, 269.96298, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[1] = CreateDynamicObject(3881, 1543.12158, -1632.96313, 14.21720,   0.00000, 0.00000, 269.68613, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[2] = CreateDynamicObject(19967, 1539.41162, -1630.99060, 12.37391,   0.00000, 0.00000, 260.76089, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[3] = CreateDynamicObject(8674, 1607.99329, -1617.97717, 15.91576,   0.00000, 0.00000, 270.03876, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[4] = CreateDynamicObject(8674, 1539.62134, -1612.64148, 15.91580,   0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[5] = CreateDynamicObject(8674, 1555.10999, -1602.31836, 15.91580,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[6] = CreateDynamicObject(8674, 1544.77722, -1602.31836, 15.91580,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[7] = CreateDynamicObject(8674, 1602.85999, -1637.95532, 15.91580,   0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[8] = CreateDynamicObject(8674, 1565.42188, -1602.33655, 15.91580,   0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[9] = CreateDynamicObject(8674, 1575.73560, -1602.36719, 15.91580,   0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[10] = CreateDynamicObject(8674, 1586.00989, -1602.41418, 15.91580,   0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[11] = CreateDynamicObject(8674, 1596.31262, -1602.44263, 15.91580,   0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[12] = CreateDynamicObject(8674, 1539.62793, -1607.49109, 15.91576,   0.00000, 0.00000, 270.03876, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[13] = CreateDynamicObject(8674, 1607.99316, -1607.69946, 15.91576,   0.00000, 0.00000, 270.03876, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[14] = CreateDynamicObject(8674, 1608.01904, -1632.78918, 15.91576,   0.00000, 0.00000, 270.03876, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[15] = CreateDynamicObject(8674, 1608.00940, -1628.29993, 15.91576,   0.00000, 0.00000, 270.03876, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[16] = CreateDynamicObject(8674, 1602.81287, -1602.47852, 15.91580,   0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[17] = CreateDynamicObject(8674, 1544.72034, -1617.82117, 15.91580,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[18] = CreateDynamicObject(984, 1571.94458, -1620.22766, 13.09645,   0.00000, 0.00000, 270.10999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[19] = CreateDynamicObject(984, 1554.34009, -1620.29077, 13.09645,   0.00000, 0.00000, 270.10999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[20] = CreateDynamicObject(984, 1567.14685, -1620.24683, 13.09645,   0.00000, 0.00000, 270.10999, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[21] = CreateDynamicObject(1361, 1578.84241, -1620.19409, 13.26574,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[22] = CreateDynamicObject(1495, 1582.59033, -1637.97705, 12.39340,   0.00000, 0.00000, 358.46552, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_lspdExterior[23] = CreateDynamicObject(2164, 1543.32507, -1631.44116, 12.46464,   0.00000, 0.00000, 274.29651, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	TOR_LSPD[0] = CreateDynamicObject(19912, 1544.45618, -1622.11987, 12.93280,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPMetalGate1
	TOR_LSPD[1] = CreateDynamicObject(19912, 1596.02783, -1638.10132, 14.59349,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_LSPDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPMetalGate1
}
