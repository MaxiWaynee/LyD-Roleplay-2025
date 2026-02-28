#include <YSI\y_hooks>

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// SAMD spawn, duty and fskin points
#define SAMD_INTERIOR_SPAWN_POINT               1462.2633, -981.9429, 675.6134
#define SAMD_INTERIOR_SPAWN_POINT_FACING        180.0
#define SAMD_INTERIOR_DUTY_POINT                1466.7092, -983.1359, 675.6134
#define SAMD_INTERIOR_ENTER_COORDS_DACH			1117.7283, -1320.9902, 40.1298

// Map variables
new object_samdInterior2[422];
new pickup_samdInterior2[3];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 1.0, SAMD_INTERIOR_ELEVATOR_1_UP_COORDS) && GetPlayerVirtualWorld(playerid) == VW_SAMDINTERIOR2) { // Elevator 1 zu Dach
			if(Spieler[playerid][pFraktion] != 3) return SendClientMessage(playerid, COLOR_RED, "[AUFZUG] {FFFFFF}Dieser Aufzug ist nur für Mitarbeiter des Rettungsdienstes!");
            SetPlayerFacingAngle(playerid, SAMD_INTERIOR_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, SAMD_INTERIOR_ENTER_COORDS_DACH, MAPS_SAMDEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
        } if (IsPlayerInRangeOfPoint(playerid, 1.0, SAMD_INTERIOR_ELEVATOR_2_UP_COORDS) && GetPlayerVirtualWorld(playerid) == VW_SAMDINTERIOR2) { // Elevator 2
            SetPlayerFacingAngle(playerid, SAMD_INTERIOR_ELEVATOR_DOWN_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, SAMD_INTERIOR_ELEVATOR_2_DOWN_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_SAMDINTERIOR);
            return 1;
        }
        if (IsPlayerInRangeOfPoint(playerid, 1.0, SAMD_INTERIOR_ENTER_COORDS_DACH)) 
		{
			if(Spieler[playerid][pFraktion] != 3) return SendClientMessage(playerid, COLOR_RED, "[AUFZUG] {FFFFFF}Dieser Aufzug ist nur für Mitarbeiter des Rettungsdienstes!");
			SetPlayerFacingAngle(playerid, SAMD_INTERIOR_ELEVATOR_DOWN_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, SAMD_INTERIOR_ELEVATOR_1_UP_COORDS, MAPS_SAMDEXTERIOR_INTERIOR, VW_SAMDINTERIOR2);
			return 1;
		}
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
    pickup_samdInterior2[0] = CreateDynamicPickup(19197, 1, SAMD_INTERIOR_ELEVATOR_1_UP_COORDS, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR); // Elevator 1
    pickup_samdInterior2[1] = CreateDynamicPickup(19197, 1, SAMD_INTERIOR_ELEVATOR_2_UP_COORDS, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR); // Elevator 2
    pickup_samdInterior2[2] = CreateDynamicPickup(19197, 1, SAMD_INTERIOR_ENTER_COORDS_DACH, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR); // Elevator 2

	// Objects
	object_samdInterior2[0] = CreateDynamicObject(19464, 1451.3685, -1001.4539, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[0], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[1] = CreateDynamicObject(18981, 1455.6219, -977.9721, 674.1032, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdInterior2[1], 0, 14479, "skuzzy_motelmain", "mp_CJ_Laminate1", 0xFFFFFFFF);
	object_samdInterior2[2] = CreateDynamicObject(19464, 1457.2784, -1001.4539, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[2], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[3] = CreateDynamicObject(19565, 1457.1229, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[3], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[4] = CreateDynamicObject(19565, 1455.5229, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[4], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[5] = CreateDynamicObject(2165, 1465.9414, -992.7656, 674.5797, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
	object_samdInterior2[6] = CreateDynamicObject(19464, 1468.1864, -986.5642, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[6], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[7] = CreateDynamicObject(19464, 1448.5279, -998.6046, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[7], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[8] = CreateDynamicObject(19464, 1448.5279, -992.6649, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[8], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[9] = CreateDynamicObject(18766, 1446.1893, -996.3944, 676.3732, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[9], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[10] = CreateDynamicObject(18766, 1446.1893, -986.4746, 676.3734, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[10], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[11] = CreateDynamicObject(18766, 1446.1893, -986.4746, 674.2133, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[11], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[12] = CreateDynamicObject(18766, 1451.7392, -1003.8153, 677.9628, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[12], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[13] = CreateDynamicObject(18766, 1446.1893, -996.4348, 679.9229, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[13], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[14] = CreateDynamicObject(18766, 1446.1893, -986.4650, 679.9232, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[14], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[15] = CreateDynamicObject(18766, 1446.1893, -996.4348, 674.2133, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[15], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[16] = CreateDynamicObject(18766, 1446.1893, -986.4650, 677.9628, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[16], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[17] = CreateDynamicObject(19565, 1455.9934, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[17], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[18] = CreateDynamicObject(18981, 1455.6219, -1002.9718, 680.0332, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdInterior2[18], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[19] = CreateDynamicObject(19565, 1456.4635, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[19], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[20] = CreateDynamicObject(19565, 1456.7336, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[20], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[21] = CreateDynamicObject(19565, 1458.4538, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[21], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[22] = CreateDynamicObject(19565, 1458.9238, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[22], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[23] = CreateDynamicObject(19565, 1459.3940, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[23], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[24] = CreateDynamicObject(19565, 1459.8642, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[24], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[25] = CreateDynamicObject(19565, 1460.3348, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[25], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[26] = CreateDynamicObject(19565, 1460.5249, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[26], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[27] = CreateDynamicObject(19565, 1460.4847, -1001.3538, 677.0001, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[27], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[28] = CreateDynamicObject(19565, 1460.4847, -1001.3538, 675.6301, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[28], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[29] = CreateDynamicObject(19565, 1460.4847, -1001.3538, 675.1599, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[29], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[30] = CreateDynamicObject(19565, 1460.4847, -1001.3538, 674.6903, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[30], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[31] = CreateDynamicObject(19565, 1455.2827, -1001.3538, 676.9702, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[31], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[32] = CreateDynamicObject(19565, 1455.2827, -1001.3538, 675.6403, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[32], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[33] = CreateDynamicObject(19565, 1455.2827, -1001.3538, 675.1702, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[33], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[34] = CreateDynamicObject(19565, 1455.2827, -1001.3538, 674.7005, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[34], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[35] = CreateDynamicObject(19464, 1463.2674, -979.4038, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[35], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[36] = CreateDynamicObject(19565, 1457.5532, -1001.3538, 676.9804, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[36], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[37] = CreateDynamicObject(19464, 1463.1975, -1001.4547, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[37], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[38] = CreateDynamicObject(18766, 1446.1893, -996.4550, 677.9628, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[38], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[39] = CreateDynamicObject(18766, 1451.7392, -1003.8153, 676.3626, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[39], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[40] = CreateDynamicObject(18766, 1461.7287, -1003.8153, 676.3626, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[40], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[41] = CreateDynamicObject(18766, 1461.7287, -1003.8153, 677.9625, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[41], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[42] = CreateDynamicObject(18766, 1453.5382, -1003.8153, 679.9223, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[42], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[43] = CreateDynamicObject(18766, 1463.5183, -1003.8153, 679.9223, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[43], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[44] = CreateDynamicObject(18766, 1453.5482, -1003.8153, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[44], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[45] = CreateDynamicObject(18766, 1463.5478, -1003.8153, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[45], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[46] = CreateDynamicObject(18766, 1463.5478, -977.0451, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[46], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[47] = CreateDynamicObject(19464, 1448.5279, -982.3546, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[47], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[48] = CreateDynamicObject(18981, 1455.6219, -978.0518, 680.0332, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdInterior2[48], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[49] = CreateDynamicObject(18766, 1463.5384, -977.0250, 679.9218, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[49], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[50] = CreateDynamicObject(19464, 1448.5378, -987.8847, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[50], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[51] = CreateDynamicObject(18766, 1463.5583, -977.0347, 677.9619, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[51], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[52] = CreateDynamicObject(18766, 1453.6579, -977.0357, 676.3623, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[52], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[53] = CreateDynamicObject(18766, 1463.6573, -977.0352, 676.3623, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[53], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[54] = CreateDynamicObject(3051, 1455.9459, -1001.3104, 675.9666, 0.0000, 0.0000, -43.6999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
	SetDynamicObjectMaterial(object_samdInterior2[54], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
	object_samdInterior2[55] = CreateDynamicObject(3051, 1458.8872, -1001.3142, 675.9666, 0.0000, 0.0000, -43.6999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
	SetDynamicObjectMaterial(object_samdInterior2[55], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
	object_samdInterior2[56] = CreateDynamicObject(19175, 1459.4847, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[56], 0, "1. Stock", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[56], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[57] = CreateDynamicObject(3051, 1457.1611, -1001.3004, 675.9666, 0.0000, 0.0000, 136.3000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
	SetDynamicObjectMaterial(object_samdInterior2[57], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
	object_samdInterior2[58] = CreateDynamicObject(3051, 1460.1035, -1001.3120, 675.9666, 0.0000, 0.0000, 136.3999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
	SetDynamicObjectMaterial(object_samdInterior2[58], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
	object_samdInterior2[59] = CreateDynamicObject(19175, 1456.5948, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[59], 0, "1. Stock", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[59], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[60] = CreateDynamicObject(19175, 1456.5742, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[60], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[60], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[61] = CreateDynamicObject(19175, 1456.5743, -1001.3010, 677.8820, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[61], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[61], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[62] = CreateDynamicObject(19175, 1455.7635, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[62], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[62], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[63] = CreateDynamicObject(19175, 1457.1346, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[63], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[63], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[64] = CreateDynamicObject(19175, 1459.4952, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[64], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[64], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[65] = CreateDynamicObject(19175, 1459.5041, -1001.3010, 677.8820, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[65], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[65], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[66] = CreateDynamicObject(19175, 1458.6848, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[66], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[66], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[67] = CreateDynamicObject(19175, 1460.0560, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[67], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[67], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[68] = CreateDynamicObject(19175, 1457.9936, -1001.3211, 676.0717, 0.0000, 180.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[68], 0, "y", 90, "Wingdings", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[68], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[69] = CreateDynamicObject(19175, 1457.9941, -1001.3211, 676.2221, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[69], 0, "y", 90, "Wingdings", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[69], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[70] = CreateDynamicObject(18075, 1453.0991, -995.8640, 679.6024, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdInterior2[71] = CreateDynamicObject(18075, 1463.5500, -995.8640, 679.6024, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdInterior2[72] = CreateDynamicObject(18766, 1458.3153, -986.5477, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[72], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[73] = CreateDynamicObject(18766, 1452.9438, -986.6677, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[73], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[74] = CreateDynamicObject(18766, 1448.5946, -986.6588, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[74], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[75] = CreateDynamicObject(18766, 1462.5765, -1005.4171, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[75], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[76] = CreateDynamicObject(18766, 1452.2552, -993.6773, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[76], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[77] = CreateDynamicObject(18766, 1462.2541, -993.6773, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[77], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[78] = CreateDynamicObject(18766, 1462.2541, -998.0974, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[78], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[79] = CreateDynamicObject(18766, 1452.2547, -998.0974, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[79], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[80] = CreateDynamicObject(18766, 1448.5946, -996.6386, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[80], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[81] = CreateDynamicObject(18766, 1462.5765, -995.4174, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[81], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[82] = CreateDynamicObject(18766, 1458.3153, -996.5479, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[82], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[83] = CreateDynamicObject(18766, 1452.9438, -996.6685, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[83], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[84] = CreateDynamicObject(19450, 1453.3863, -997.8765, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[84], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[85] = CreateDynamicObject(19450, 1453.3863, -998.3267, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[85], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[86] = CreateDynamicObject(19450, 1463.0168, -997.8765, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[86], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[87] = CreateDynamicObject(19450, 1463.0168, -998.3264, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[87], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[88] = CreateDynamicObject(19450, 1463.0168, -993.9058, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[88], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[89] = CreateDynamicObject(19450, 1463.0168, -993.4354, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[89], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[90] = CreateDynamicObject(19450, 1453.3852, -993.9058, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[90], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[91] = CreateDynamicObject(19450, 1453.3852, -993.4354, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[91], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[92] = CreateDynamicObject(19565, 1457.5532, -1001.3538, 675.6303, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[92], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[93] = CreateDynamicObject(19565, 1457.5532, -1001.3538, 675.1602, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[93], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[94] = CreateDynamicObject(19565, 1457.5532, -1001.3538, 674.7003, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[94], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[95] = CreateDynamicObject(19565, 1458.2137, -1001.3538, 677.0003, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[95], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[96] = CreateDynamicObject(19565, 1458.2137, -1001.3538, 675.6400, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[96], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[97] = CreateDynamicObject(19565, 1458.2137, -1001.3538, 675.1801, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[97], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[98] = CreateDynamicObject(19565, 1458.2137, -1001.3538, 674.7202, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[98], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[99] = CreateDynamicObject(19464, 1468.1964, -980.6442, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[99], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[100] = CreateDynamicObject(18766, 1470.5356, -976.3956, 674.2125, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[100], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[101] = CreateDynamicObject(18766, 1470.5356, -976.3751, 677.9625, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[101], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[102] = CreateDynamicObject(18766, 1470.5356, -976.3751, 676.3626, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[102], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[103] = CreateDynamicObject(18766, 1470.5356, -986.3748, 676.3626, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[103], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[104] = CreateDynamicObject(18766, 1470.5356, -976.3847, 679.9223, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[104], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[105] = CreateDynamicObject(19464, 1457.3481, -979.4038, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[105], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[106] = CreateDynamicObject(19464, 1451.4183, -979.3839, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[106], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[107] = CreateDynamicObject(18766, 1453.6579, -977.0357, 677.9622, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[107], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[108] = CreateDynamicObject(18766, 1453.6579, -977.0357, 679.9221, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[108], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[109] = CreateDynamicObject(18766, 1453.6579, -977.0357, 674.2122, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[109], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[110] = CreateDynamicObject(18766, 1446.1893, -976.4746, 676.3734, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[110], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[111] = CreateDynamicObject(18766, 1446.1893, -976.4746, 677.9630, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[111], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[112] = CreateDynamicObject(18766, 1446.1893, -976.4746, 674.2030, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[112], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[113] = CreateDynamicObject(18766, 1446.1893, -976.4746, 679.9133, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[113], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[114] = CreateDynamicObject(18075, 1463.5500, -982.7943, 679.6124, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdInterior2[115] = CreateDynamicObject(18766, 1452.9438, -976.6776, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[115], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[116] = CreateDynamicObject(18766, 1448.5931, -976.6776, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[116], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[117] = CreateDynamicObject(18766, 1458.3143, -976.6776, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[117], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[118] = CreateDynamicObject(18766, 1462.5748, -985.4177, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[118], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[119] = CreateDynamicObject(18766, 1462.5748, -975.5177, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[119], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[120] = CreateDynamicObject(18766, 1468.2347, -996.5081, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[120], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[121] = CreateDynamicObject(18766, 1468.2347, -986.5078, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[121], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[122] = CreateDynamicObject(18766, 1468.2347, -976.5380, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[122], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[123] = CreateDynamicObject(18075, 1453.3298, -982.7943, 679.6124, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdInterior2[124] = CreateDynamicObject(19565, 1457.5926, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[124], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[125] = CreateDynamicObject(19464, 1469.1971, -979.4042, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[125], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[126] = CreateDynamicObject(19464, 1469.1269, -1001.4550, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[126], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[127] = CreateDynamicObject(19464, 1468.1864, -998.4249, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[127], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[128] = CreateDynamicObject(19464, 1468.1864, -992.4942, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[128], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[129] = CreateDynamicObject(18766, 1470.5179, -995.5045, 676.3623, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[129], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[130] = CreateDynamicObject(18766, 1470.5179, -1005.5042, 676.3623, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[130], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[131] = CreateDynamicObject(18766, 1471.7176, -1003.8142, 676.3623, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[131], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[132] = CreateDynamicObject(18766, 1471.7176, -1003.8142, 677.9625, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[132], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[133] = CreateDynamicObject(18766, 1470.5356, -996.3646, 677.9625, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[133], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[134] = CreateDynamicObject(18766, 1470.5356, -986.3651, 677.9625, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[134], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[135] = CreateDynamicObject(18766, 1470.5356, -986.3952, 674.2125, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[135], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[136] = CreateDynamicObject(18766, 1470.5356, -996.3842, 674.2125, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[136], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[137] = CreateDynamicObject(18766, 1470.5356, -996.3842, 679.9223, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[137], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[138] = CreateDynamicObject(18766, 1470.5356, -986.3845, 679.9223, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[138], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[139] = CreateDynamicObject(18766, 1472.2534, -993.6773, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[139], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[140] = CreateDynamicObject(18766, 1472.2534, -998.0985, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[140], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[141] = CreateDynamicObject(18766, 1462.7867, -989.4569, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[141], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[142] = CreateDynamicObject(18766, 1462.7867, -984.9569, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[142], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[143] = CreateDynamicObject(18766, 1452.8271, -984.9569, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[143], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[144] = CreateDynamicObject(18766, 1452.8271, -989.4561, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdInterior2[144], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[145] = CreateDynamicObject(19450, 1453.3852, -989.6749, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[145], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[146] = CreateDynamicObject(19450, 1453.3852, -989.2149, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[146], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[147] = CreateDynamicObject(19450, 1453.3852, -985.2150, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[147], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[148] = CreateDynamicObject(19450, 1453.3852, -984.7047, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[148], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[149] = CreateDynamicObject(19450, 1463.0141, -984.7047, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[149], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[150] = CreateDynamicObject(19450, 1463.0141, -985.2147, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[150], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[151] = CreateDynamicObject(19450, 1463.0141, -989.2152, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[151], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[152] = CreateDynamicObject(19450, 1463.0141, -989.6754, 681.2545, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdInterior2[152], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
	object_samdInterior2[153] = CreateDynamicObject(1997, 1450.1771, -998.7487, 674.5985, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hos_trolley
	object_samdInterior2[154] = CreateDynamicObject(1997, 1450.1771, -996.1586, 674.5985, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hos_trolley
	object_samdInterior2[155] = CreateDynamicObject(1997, 1450.1771, -993.5784, 674.5985, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //hos_trolley
	object_samdInterior2[156] = CreateDynamicObject(19430, 1448.6075, -996.0822, 675.1264, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[156], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[157] = CreateDynamicObject(19430, 1448.6075, -998.6624, 675.1264, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[157], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[158] = CreateDynamicObject(19430, 1448.6075, -993.4926, 675.1264, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[158], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[159] = CreateDynamicObject(19430, 1447.9072, -992.9024, 675.1264, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[159], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[160] = CreateDynamicObject(19430, 1447.9072, -994.0827, 675.1162, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[160], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[161] = CreateDynamicObject(19430, 1447.9072, -995.4926, 675.1162, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[161], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[162] = CreateDynamicObject(19430, 1447.9072, -996.6727, 675.1162, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[162], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[163] = CreateDynamicObject(19430, 1447.9072, -998.0629, 675.1162, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[163], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[164] = CreateDynamicObject(19430, 1447.9072, -999.2432, 675.1162, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[164], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[165] = CreateDynamicObject(19430, 1449.6772, -996.0822, 674.5161, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[165], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[166] = CreateDynamicObject(19430, 1449.6772, -998.6627, 674.5161, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[166], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[167] = CreateDynamicObject(19430, 1449.6772, -993.4826, 674.5161, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[167], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[168] = CreateDynamicObject(19430, 1449.5959, -999.2431, 673.8062, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[168], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[169] = CreateDynamicObject(19430, 1449.5959, -998.0629, 673.8062, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[169], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[170] = CreateDynamicObject(19430, 1449.5959, -996.6727, 673.8062, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[170], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[171] = CreateDynamicObject(19430, 1449.5959, -995.4926, 673.8062, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[171], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[172] = CreateDynamicObject(19430, 1449.5959, -994.0822, 673.8062, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[172], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[173] = CreateDynamicObject(19430, 1449.5959, -992.9019, 673.8062, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[173], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[174] = CreateDynamicObject(19430, 1451.3365, -993.4821, 672.8660, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[174], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[175] = CreateDynamicObject(19430, 1451.3365, -996.0822, 672.8660, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[175], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[176] = CreateDynamicObject(19430, 1451.3365, -998.6624, 672.8660, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[176], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[177] = CreateDynamicObject(19903, 1449.0268, -997.4340, 674.5999, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
	object_samdInterior2[178] = CreateDynamicObject(19903, 1449.0268, -994.8040, 674.5999, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MechanicComputer1
	object_samdInterior2[179] = CreateDynamicObject(19464, 1452.4018, -990.5230, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[179], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[180] = CreateDynamicObject(19430, 1446.9764, -993.4921, 676.7960, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[180], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[181] = CreateDynamicObject(19430, 1446.9764, -996.0822, 676.7960, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[181], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[182] = CreateDynamicObject(19430, 1446.9764, -998.6624, 676.7960, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[182], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdInterior2[183] = CreateDynamicObject(19383, 1455.2833, -992.1254, 676.2385, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
	SetDynamicObjectMaterial(object_samdInterior2[183], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[184] = CreateDynamicObject(19464, 1446.9383, -990.5233, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[184], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[185] = CreateDynamicObject(19325, 1455.2728, -985.1372, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[185], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[186] = CreateDynamicObject(19325, 1455.2728, -995.7871, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[186], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[187] = CreateDynamicObject(19383, 1455.2833, -988.8261, 676.2385, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
	SetDynamicObjectMaterial(object_samdInterior2[187], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[188] = CreateDynamicObject(19325, 1455.2728, -981.0175, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[188], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[189] = CreateDynamicObject(1491, 1455.3089, -992.8582, 674.4879, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_samdInterior2[189], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdInterior2[189], 1, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	object_samdInterior2[190] = CreateDynamicObject(19325, 1455.2728, -999.9074, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[190], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[191] = CreateDynamicObject(1491, 1455.2889, -988.0576, 674.4879, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_samdInterior2[191], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdInterior2[191], 1, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	object_samdInterior2[192] = CreateDynamicObject(19089, 1455.2711, -983.0410, 681.7448, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[192], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[193] = CreateDynamicObject(19089, 1455.2711, -987.2114, 681.7448, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[193], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[194] = CreateDynamicObject(19089, 1455.2711, -979.5407, 681.7448, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[194], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[195] = CreateDynamicObject(19089, 1455.2711, -1001.0905, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[195], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[196] = CreateDynamicObject(19089, 1455.2711, -997.8513, 680.4843, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[196], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[197] = CreateDynamicObject(19089, 1455.2711, -1001.3217, 681.7448, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[197], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[198] = CreateDynamicObject(19089, 1455.2711, -993.7221, 679.5050, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[198], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[199] = CreateDynamicObject(19089, 1455.2711, -1001.1010, 679.5050, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[199], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[200] = CreateDynamicObject(19089, 1455.2711, -993.7208, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[200], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[201] = CreateDynamicObject(19089, 1455.2711, -979.8402, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[201], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[202] = CreateDynamicObject(19814, 1448.7286, -998.6093, 676.7985, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[203] = CreateDynamicObject(19089, 1455.2711, -972.5302, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[203], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[204] = CreateDynamicObject(19089, 1455.2711, -972.4406, 679.5247, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[204], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[205] = CreateDynamicObject(19089, 1455.2711, -979.8308, 679.5247, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[205], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[206] = CreateDynamicObject(19089, 1455.2711, -979.8308, 674.6245, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[206], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[207] = CreateDynamicObject(19089, 1455.2711, -972.4807, 674.6245, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[207], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[208] = CreateDynamicObject(19089, 1455.2711, -993.7207, 674.6245, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[208], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[209] = CreateDynamicObject(19089, 1455.2711, -1001.0808, 674.6245, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[209], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[210] = CreateDynamicObject(19430, 1455.2773, -991.3201, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[210], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[211] = CreateDynamicObject(19430, 1455.2773, -992.9199, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[211], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[212] = CreateDynamicObject(19430, 1455.2773, -989.7199, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[212], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[213] = CreateDynamicObject(19430, 1455.2773, -988.1198, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[213], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[214] = CreateDynamicObject(19430, 1455.2673, -988.0297, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[214], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[215] = CreateDynamicObject(19089, 1455.2711, -993.7312, 681.7448, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[215], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[216] = CreateDynamicObject(19814, 1448.7286, -996.0390, 676.7985, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[217] = CreateDynamicObject(19814, 1448.7286, -993.4790, 676.7985, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[218] = CreateDynamicObject(2163, 1451.0565, -1001.5103, 675.9207, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
	object_samdInterior2[219] = CreateDynamicObject(2163, 1450.2464, -990.4298, 675.9207, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
	object_samdInterior2[220] = CreateDynamicObject(2167, 1448.6240, -992.0811, 674.5944, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
	object_samdInterior2[221] = CreateDynamicObject(2167, 1448.6240, -991.1712, 674.5944, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
	object_samdInterior2[222] = CreateDynamicObject(2167, 1448.6240, -999.9312, 674.5944, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
	object_samdInterior2[223] = CreateDynamicObject(2167, 1448.6240, -1000.8311, 674.5944, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
	object_samdInterior2[224] = CreateDynamicObject(2163, 1453.8364, -1001.5103, 675.9207, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
	object_samdInterior2[225] = CreateDynamicObject(1811, 1451.9591, -1000.9165, 675.1572, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[226] = CreateDynamicObject(2163, 1453.8364, -1001.5103, 675.0106, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
	object_samdInterior2[227] = CreateDynamicObject(11706, 1450.9681, -1001.0988, 674.5532, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
	object_samdInterior2[228] = CreateDynamicObject(11706, 1450.2081, -1001.0988, 674.5532, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
	object_samdInterior2[229] = CreateDynamicObject(2163, 1453.1267, -990.4298, 675.9207, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
	object_samdInterior2[230] = CreateDynamicObject(19825, 1452.0179, -1001.2766, 677.7705, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
	SetDynamicObjectMaterial(object_samdInterior2[230], 0, 14802, "lee_bdupsflat", "Bdup_Clock", 0xFFFFFFFF);
	object_samdInterior2[231] = CreateDynamicObject(2163, 1453.1267, -990.4298, 675.0006, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
	object_samdInterior2[232] = CreateDynamicObject(1811, 1451.9591, -991.0560, 675.1572, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[233] = CreateDynamicObject(11706, 1450.9681, -990.8986, 674.5532, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
	object_samdInterior2[234] = CreateDynamicObject(11706, 1450.2181, -990.8986, 674.5532, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SmallWasteBin1
	object_samdInterior2[235] = CreateDynamicObject(19825, 1452.0179, -990.6967, 677.7705, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
	SetDynamicObjectMaterial(object_samdInterior2[235], 0, 14802, "lee_bdupsflat", "Bdup_Clock", 0xFFFFFFFF);
	object_samdInterior2[236] = CreateDynamicObject(19175, 1455.3851, -992.1207, 677.5618, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[236], 0, "_________________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[236], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[237] = CreateDynamicObject(19175, 1455.3851, -992.1207, 677.6118, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[237], 0, "Behandlungsraum", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[237], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[238] = CreateDynamicObject(19175, 1455.3851, -992.1207, 677.8820, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[238], 0, "_________________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[238], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[239] = CreateDynamicObject(19175, 1455.3851, -988.8206, 677.5618, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[239], 0, "__________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[239], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[240] = CreateDynamicObject(19175, 1455.3851, -988.8208, 677.6118, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[240], 0, "Büroraum", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[240], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[241] = CreateDynamicObject(19175, 1455.3851, -988.8206, 677.8820, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[241], 0, "__________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[241], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[242] = CreateDynamicObject(19175, 1455.2650, -995.7606, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[242], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[242], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[243] = CreateDynamicObject(19175, 1455.2650, -981.2105, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[243], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[243], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[244] = CreateDynamicObject(19175, 1455.2650, -999.5208, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[244], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[244], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[245] = CreateDynamicObject(19175, 1455.2650, -985.0407, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[245], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[245], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[246] = CreateDynamicObject(19089, 1455.2711, -993.7105, 676.5744, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[246], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[247] = CreateDynamicObject(19089, 1455.2711, -993.7105, 676.9545, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[247], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[248] = CreateDynamicObject(19089, 1455.2711, -979.8609, 676.9545, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[248], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[249] = CreateDynamicObject(19089, 1455.2711, -979.8609, 676.5844, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[249], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[250] = CreateDynamicObject(19089, 1455.2711, -972.5208, 676.5844, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[250], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[251] = CreateDynamicObject(19089, 1455.2711, -972.5208, 676.9544, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[251], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[252] = CreateDynamicObject(19089, 1455.2711, -1001.0712, 676.9544, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[252], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[253] = CreateDynamicObject(19089, 1455.2711, -1001.0712, 676.5841, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[253], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[254] = CreateDynamicObject(19325, 1460.7535, -999.9074, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[254], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[255] = CreateDynamicObject(19325, 1460.7535, -995.7772, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[255], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[256] = CreateDynamicObject(19383, 1460.7231, -992.1254, 676.2385, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
	SetDynamicObjectMaterial(object_samdInterior2[256], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[257] = CreateDynamicObject(19383, 1460.7237, -988.8261, 676.2385, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
	SetDynamicObjectMaterial(object_samdInterior2[257], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[258] = CreateDynamicObject(19464, 1463.6040, -990.5230, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[258], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[259] = CreateDynamicObject(19464, 1469.5598, -990.5230, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdInterior2[259], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[260] = CreateDynamicObject(19325, 1460.7535, -985.1774, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[260], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[261] = CreateDynamicObject(19325, 1460.7535, -981.0471, 677.3466, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lsmall_window01
	SetDynamicObjectMaterial(object_samdInterior2[261], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdInterior2[262] = CreateDynamicObject(1491, 1460.7386, -992.8582, 674.4879, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_samdInterior2[262], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdInterior2[262], 1, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	object_samdInterior2[263] = CreateDynamicObject(1491, 1460.6993, -988.0374, 674.4879, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorINT01
	SetDynamicObjectMaterial(object_samdInterior2[263], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdInterior2[263], 1, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
	object_samdInterior2[264] = CreateDynamicObject(19175, 1460.6451, -988.7905, 677.8720, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[264], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[264], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[265] = CreateDynamicObject(19175, 1460.6352, -992.1207, 677.6118, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[265], 0, "Ausbildungsraum", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[265], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[266] = CreateDynamicObject(19175, 1460.6451, -988.7907, 677.6118, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[266], 0, "Dienstraum", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[266], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[267] = CreateDynamicObject(19175, 1460.6451, -988.7905, 677.5618, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[267], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[267], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[268] = CreateDynamicObject(19175, 1460.6451, -992.1104, 677.8720, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[268], 0, "_________________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[268], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[269] = CreateDynamicObject(19175, 1460.6451, -992.1104, 677.5720, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[269], 0, "_________________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[269], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[270] = CreateDynamicObject(19430, 1460.7176, -988.0197, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[270], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[271] = CreateDynamicObject(19430, 1460.7176, -989.6298, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[271], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[272] = CreateDynamicObject(19430, 1460.7176, -991.2296, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[272], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[273] = CreateDynamicObject(19430, 1460.7176, -992.8297, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[273], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[274] = CreateDynamicObject(19430, 1460.7275, -992.9298, 679.5866, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdInterior2[274], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdInterior2[275] = CreateDynamicObject(19089, 1460.7508, -993.7208, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[275], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[276] = CreateDynamicObject(19089, 1460.7508, -1001.0607, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[276], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[277] = CreateDynamicObject(19089, 1460.7508, -979.9505, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[277], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[278] = CreateDynamicObject(19089, 1460.7508, -972.5703, 678.4047, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[278], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[279] = CreateDynamicObject(19089, 1460.7508, -972.5706, 679.5045, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[279], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[280] = CreateDynamicObject(19089, 1460.7508, -979.9204, 679.5045, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[280], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[281] = CreateDynamicObject(19089, 1460.7508, -993.7000, 679.5045, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[281], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[282] = CreateDynamicObject(19089, 1460.7508, -1001.0297, 679.5045, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[282], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[283] = CreateDynamicObject(19089, 1460.7508, -1001.0297, 674.6146, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[283], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[284] = CreateDynamicObject(19089, 1460.7508, -993.6696, 674.6146, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[284], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[285] = CreateDynamicObject(19089, 1460.7508, -979.9696, 674.6146, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[285], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[286] = CreateDynamicObject(19089, 1460.7508, -972.6395, 674.6146, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[286], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[287] = CreateDynamicObject(19089, 1460.7508, -983.1300, 679.5244, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[287], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[288] = CreateDynamicObject(19089, 1460.7508, -987.2003, 679.5244, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[288], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[289] = CreateDynamicObject(19089, 1460.7508, -979.5399, 679.5244, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[289], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[290] = CreateDynamicObject(19089, 1460.7508, -993.7401, 679.5244, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[290], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[291] = CreateDynamicObject(19089, 1460.7508, -997.8405, 679.5244, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[291], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[292] = CreateDynamicObject(19089, 1460.7508, -1001.3109, 679.5244, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[292], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[293] = CreateDynamicObject(19089, 1460.7519, -993.7105, 676.9545, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[293], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[294] = CreateDynamicObject(19089, 1460.7519, -1001.0806, 676.9545, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[294], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[295] = CreateDynamicObject(19089, 1460.7519, -979.8505, 676.9545, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[295], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[296] = CreateDynamicObject(19089, 1460.7519, -972.5407, 676.9545, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[296], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[297] = CreateDynamicObject(19175, 1460.7651, -981.3908, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[297], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[297], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[298] = CreateDynamicObject(19175, 1460.7651, -995.8510, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[298], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[298], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[299] = CreateDynamicObject(19175, 1460.7651, -999.5911, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[299], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[299], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[300] = CreateDynamicObject(19175, 1460.7651, -985.1207, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[300], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[300], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[301] = CreateDynamicObject(19175, 1460.7651, -985.1207, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[301], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[301], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[302] = CreateDynamicObject(19175, 1460.7651, -981.3908, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[302], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[302], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[303] = CreateDynamicObject(19175, 1455.2850, -985.0407, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[303], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[303], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[304] = CreateDynamicObject(19175, 1455.2850, -981.2105, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[304], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[304], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[305] = CreateDynamicObject(19175, 1455.2850, -995.7606, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[305], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[305], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[306] = CreateDynamicObject(19175, 1455.2850, -999.5208, 676.7819, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[306], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[306], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[307] = CreateDynamicObject(19175, 1460.7651, -999.5911, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[307], 0, "Medical Department", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[307], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[308] = CreateDynamicObject(19175, 1460.7651, -995.8510, 676.7819, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[308], 0, "San Andreas", 90, "Arial", 30, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[308], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[309] = CreateDynamicObject(19089, 1460.7519, -972.4807, 676.5744, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[309], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[310] = CreateDynamicObject(19089, 1460.7519, -979.8004, 676.5744, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[310], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[311] = CreateDynamicObject(19089, 1460.7519, -993.6204, 676.5744, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[311], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[312] = CreateDynamicObject(19089, 1460.7519, -1000.9605, 676.5744, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
	SetDynamicObjectMaterial(object_samdInterior2[312], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
	object_samdInterior2[313] = CreateDynamicObject(2165, 1451.1583, -987.2744, 674.5872, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
	object_samdInterior2[314] = CreateDynamicObject(2165, 1451.1583, -981.6945, 674.5872, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
	object_samdInterior2[315] = CreateDynamicObject(2165, 1451.1583, -984.4047, 674.5872, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_DESK_1
	object_samdInterior2[316] = CreateDynamicObject(1714, 1449.7358, -987.8787, 674.5797, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
	object_samdInterior2[317] = CreateDynamicObject(1714, 1449.7358, -985.0285, 674.5797, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
	object_samdInterior2[318] = CreateDynamicObject(1714, 1449.7358, -982.3380, 674.5797, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
	object_samdInterior2[319] = CreateDynamicObject(1811, 1452.8841, -981.7899, 675.2282, 0.0000, 0.0000, 18.7999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	SetDynamicObjectMaterial(object_samdInterior2[319], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
	object_samdInterior2[320] = CreateDynamicObject(1811, 1452.8769, -983.0177, 675.2282, 0.0000, 0.0000, -12.0999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	SetDynamicObjectMaterial(object_samdInterior2[320], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
	object_samdInterior2[321] = CreateDynamicObject(1811, 1452.8797, -985.4832, 675.2282, 0.0000, 0.0000, -12.0999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	SetDynamicObjectMaterial(object_samdInterior2[321], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
	object_samdInterior2[322] = CreateDynamicObject(1811, 1452.9088, -984.4415, 675.2282, 0.0000, 0.0000, 17.2999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	SetDynamicObjectMaterial(object_samdInterior2[322], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
	object_samdInterior2[323] = CreateDynamicObject(1811, 1452.9281, -987.3264, 675.2282, 0.0000, 0.0000, 17.2999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	SetDynamicObjectMaterial(object_samdInterior2[323], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
	object_samdInterior2[324] = CreateDynamicObject(1811, 1452.9134, -988.5360, 675.2282, 0.0000, 0.0000, -19.7999, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	SetDynamicObjectMaterial(object_samdInterior2[324], 1, 2772, "airp_prop", "cj_chromepipe", 0xFFFFFFFF);
	object_samdInterior2[325] = CreateDynamicObject(2161, 1448.6407, -986.5227, 675.3988, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
	object_samdInterior2[326] = CreateDynamicObject(2161, 1448.6207, -983.7426, 675.3988, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
	object_samdInterior2[327] = CreateDynamicObject(2613, 1451.5106, -985.7628, 674.5460, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_WASTEBIN
	object_samdInterior2[328] = CreateDynamicObject(2613, 1451.5106, -982.4729, 674.5460, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_WASTEBIN
	object_samdInterior2[329] = CreateDynamicObject(2164, 1452.6340, -979.5134, 674.5706, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
	object_samdInterior2[330] = CreateDynamicObject(19825, 1448.7336, -984.8812, 677.2152, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SprunkClock1
	SetDynamicObjectMaterial(object_samdInterior2[330], 0, 14802, "lee_bdupsflat", "Bdup_Clock", 0xFFFFFFFF);
	object_samdInterior2[331] = CreateDynamicObject(2164, 1453.4239, -990.3933, 674.5706, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
	object_samdInterior2[332] = CreateDynamicObject(2162, 1450.6700, -990.3842, 675.1179, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
	object_samdInterior2[333] = CreateDynamicObject(2162, 1449.8497, -979.4843, 675.1179, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
	object_samdInterior2[334] = CreateDynamicObject(18981, 1455.6219, -1002.9718, 674.1032, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdInterior2[334], 0, 14479, "skuzzy_motelmain", "mp_CJ_Laminate1", 0xFFFFFFFF);
	object_samdInterior2[335] = CreateDynamicObject(1811, 1465.4697, -991.4575, 675.2163, 0.0000, 0.0000, 75.5998, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[336] = CreateDynamicObject(1811, 1466.0599, -998.6375, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[337] = CreateDynamicObject(1811, 1464.3502, -998.6375, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[338] = CreateDynamicObject(1811, 1462.6600, -998.6375, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[339] = CreateDynamicObject(1811, 1462.6600, -995.6677, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[340] = CreateDynamicObject(1811, 1464.2700, -995.6677, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[341] = CreateDynamicObject(1811, 1466.0506, -995.6677, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[342] = CreateDynamicObject(1811, 1464.3502, -997.2072, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[343] = CreateDynamicObject(1811, 1462.6402, -997.2072, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[344] = CreateDynamicObject(1811, 1466.0301, -997.2072, 675.2163, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
	object_samdInterior2[345] = CreateDynamicObject(1744, 1468.2187, -984.5518, 674.6848, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[345], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[346] = CreateDynamicObject(18981, 1473.2320, -977.9022, 674.1134, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdInterior2[346], 0, 14712, "lahss2bint2", "WH_carpet2", 0xFFFFFFFF);
	object_samdInterior2[347] = CreateDynamicObject(18981, 1442.7414, -977.9022, 674.1134, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdInterior2[347], 0, 14712, "lahss2bint2", "WH_carpet2", 0xFFFFFFFF);
	object_samdInterior2[348] = CreateDynamicObject(11729, 1467.8708, -983.0620, 674.5424, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	object_samdInterior2[349] = CreateDynamicObject(11729, 1467.8800, -983.7108, 674.5485, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	object_samdInterior2[350] = CreateDynamicObject(11730, 1467.8492, -982.4121, 674.5462, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
	object_samdInterior2[351] = CreateDynamicObject(11730, 1467.8293, -986.3427, 674.5462, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
	object_samdInterior2[352] = CreateDynamicObject(11729, 1467.8398, -987.0012, 674.5485, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerClosed1
	object_samdInterior2[353] = CreateDynamicObject(11730, 1467.8293, -987.6627, 674.5462, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GymLockerOpen1
	object_samdInterior2[354] = CreateDynamicObject(1744, 1468.2187, -980.6516, 674.6848, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[354], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[355] = CreateDynamicObject(1744, 1468.2187, -988.4716, 674.6848, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[355], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[356] = CreateDynamicObject(1744, 1465.2076, -979.3718, 675.6348, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[356], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[357] = CreateDynamicObject(1744, 1462.6269, -979.3718, 675.6348, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[357], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[358] = CreateDynamicObject(11738, 1465.1090, -979.6978, 676.0145, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicCase1
	object_samdInterior2[359] = CreateDynamicObject(11738, 1466.2390, -979.6978, 676.0145, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicCase1
	object_samdInterior2[360] = CreateDynamicObject(11738, 1465.6988, -979.6978, 676.0145, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicCase1
	object_samdInterior2[361] = CreateDynamicObject(11736, 1462.6756, -979.6713, 675.9788, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicalSatchel1
	object_samdInterior2[362] = CreateDynamicObject(11736, 1463.4654, -979.6713, 675.9788, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicalSatchel1
	object_samdInterior2[363] = CreateDynamicObject(1744, 1464.3387, -983.6019, 674.6848, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[363], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[364] = CreateDynamicObject(1744, 1464.3387, -985.5319, 674.6848, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[364], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[365] = CreateDynamicObject(1744, 1464.0284, -986.4818, 674.6868, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[365], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[366] = CreateDynamicObject(1744, 1464.0284, -984.5615, 674.6868, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[366], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[367] = CreateDynamicObject(1744, 1466.1579, -990.5825, 675.6348, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[367], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[368] = CreateDynamicObject(1744, 1463.4775, -990.5825, 675.6348, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_SHELF
	SetDynamicObjectMaterial(object_samdInterior2[368], 0, 2627, "genintint_gym", "bench_test2b", 0xFFFFFFFF);
	object_samdInterior2[369] = CreateDynamicObject(11738, 1465.6988, -990.2581, 676.0145, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicCase1
	object_samdInterior2[370] = CreateDynamicObject(11738, 1466.2292, -990.2581, 676.0145, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicCase1
	object_samdInterior2[371] = CreateDynamicObject(11738, 1465.1391, -990.2581, 676.0145, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicCase1
	object_samdInterior2[372] = CreateDynamicObject(11736, 1463.4654, -990.2515, 675.9788, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicalSatchel1
	object_samdInterior2[373] = CreateDynamicObject(11736, 1462.6053, -990.2515, 675.9788, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MedicalSatchel1
	object_samdInterior2[374] = CreateDynamicObject(2613, 1464.6944, -978.8363, 674.6873, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_WASTEBIN
	object_samdInterior2[375] = CreateDynamicObject(19565, 1457.4571, -979.5081, 675.6251, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[375], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[376] = CreateDynamicObject(1522, 1456.1224, -979.4901, 674.5573, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	SetDynamicObjectMaterial(object_samdInterior2[376], 0, 2878, "cj_vic", "CJ_VICT_DOOR", 0xFFFFFFFF);
	object_samdInterior2[377] = CreateDynamicObject(2613, 1464.6944, -989.3170, 674.6873, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //POLICE_WASTEBIN
	object_samdInterior2[378] = CreateDynamicObject(1522, 1458.2822, -979.4901, 674.5573, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	SetDynamicObjectMaterial(object_samdInterior2[378], 0, 18008, "intclothesa", "CJ_VICT_DOOR2", 0xFFFFFFFF);
	object_samdInterior2[379] = CreateDynamicObject(19565, 1457.4571, -979.5081, 675.1452, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[379], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[380] = CreateDynamicObject(19565, 1457.4571, -979.5081, 674.6652, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[380], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[381] = CreateDynamicObject(19565, 1458.2175, -979.5081, 674.6652, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[381], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[382] = CreateDynamicObject(19565, 1458.2175, -979.5081, 675.1453, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[382], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[383] = CreateDynamicObject(19565, 1458.2175, -979.5081, 675.6154, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[383], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[384] = CreateDynamicObject(19565, 1458.2175, -979.5081, 676.9055, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[384], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[385] = CreateDynamicObject(19565, 1458.2175, -979.5081, 676.4556, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[385], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[386] = CreateDynamicObject(19565, 1458.2175, -979.5081, 676.0855, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[386], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[387] = CreateDynamicObject(19565, 1457.4571, -979.5081, 676.0855, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[387], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[388] = CreateDynamicObject(19565, 1457.4571, -979.5081, 676.9055, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[388], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[389] = CreateDynamicObject(19565, 1457.4571, -979.5081, 676.5355, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[389], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[390] = CreateDynamicObject(19565, 1456.0572, -979.5081, 676.5355, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[390], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[391] = CreateDynamicObject(19565, 1456.0572, -979.5081, 676.0753, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[391], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[392] = CreateDynamicObject(19565, 1456.0572, -979.5081, 675.6054, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[392], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[393] = CreateDynamicObject(19565, 1456.0572, -979.5081, 675.1555, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[393], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[394] = CreateDynamicObject(19565, 1456.0572, -979.5081, 674.6857, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[394], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[395] = CreateDynamicObject(19565, 1457.1971, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[395], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[396] = CreateDynamicObject(19565, 1456.0566, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[396], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[397] = CreateDynamicObject(19565, 1456.3269, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[397], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[398] = CreateDynamicObject(19565, 1456.9272, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[398], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[399] = CreateDynamicObject(19565, 1456.6571, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[399], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[400] = CreateDynamicObject(19565, 1456.5467, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[400], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[401] = CreateDynamicObject(19565, 1458.4769, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[401], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[402] = CreateDynamicObject(19565, 1458.7469, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[402], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[403] = CreateDynamicObject(19565, 1459.0074, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[403], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[404] = CreateDynamicObject(19565, 1459.2777, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[404], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[405] = CreateDynamicObject(19565, 1459.5378, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[405], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[406] = CreateDynamicObject(19565, 1459.6080, -979.5081, 676.9058, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[406], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[407] = CreateDynamicObject(19565, 1459.6080, -979.5081, 676.4458, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[407], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[408] = CreateDynamicObject(19565, 1459.6080, -979.5081, 675.9758, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[408], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[409] = CreateDynamicObject(19565, 1459.6080, -979.5081, 675.5158, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[409], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[410] = CreateDynamicObject(19565, 1459.6080, -979.5081, 675.0557, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[410], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[411] = CreateDynamicObject(19565, 1459.6080, -979.5081, 674.5960, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[411], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[412] = CreateDynamicObject(19565, 1459.0577, -979.5081, 676.9959, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[412], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[413] = CreateDynamicObject(19565, 1456.9272, -979.5081, 676.9959, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
	SetDynamicObjectMaterial(object_samdInterior2[413], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
	object_samdInterior2[414] = CreateDynamicObject(19814, 1468.0423, -992.9724, 674.7946, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[415] = CreateDynamicObject(19175, 1456.9355, -979.5509, 677.1820, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[415], 0, "Herren", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[415], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[416] = CreateDynamicObject(19175, 1459.0561, -979.5509, 677.1820, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdInterior2[416], 0, "Damen", 130, "Arial", 23, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdInterior2[416], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdInterior2[417] = CreateDynamicObject(19814, 1448.6622, -987.1823, 674.7946, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[418] = CreateDynamicObject(19814, 1448.6622, -984.4921, 674.7946, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[419] = CreateDynamicObject(19814, 1448.6622, -982.6420, 674.7946, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
	object_samdInterior2[420] = CreateDynamicObject(948, 1451.5959, -990.1137, 674.5888, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
	object_samdInterior2[421] = CreateDynamicObject(948, 1451.5959, -979.8339, 674.5888, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR2, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plant_Pot_10
}