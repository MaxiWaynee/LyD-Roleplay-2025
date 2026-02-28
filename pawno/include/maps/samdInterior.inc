#include <YSI\y_hooks>

// Global interior define
#define MAPS_SAMDEXTERIOR_INTERIOR      0
#define MAPS_SAMDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// SAMD elevator points and health insurance
#define SAMD_INTERIOR_ELEVATOR_1_DOWN_COORDS    1457.1490, -1000.6125, 675.6033
#define SAMD_INTERIOR_ELEVATOR_2_DOWN_COORDS    1454.0316, -1000.6125, 675.6033
#define SAMD_INTERIOR_ELEVATOR_1_UP_COORDS      1459.4672, -1000.8427, 675.6033
#define SAMD_INTERIOR_ELEVATOR_2_UP_COORDS      1456.5504, -1000.8427, 675.6033
#define SAMD_INTERIOR_ELEVATOR_DOWN_FACING      0.0
#define SAMD_INTERIOR_ELEVATOR_UP_FACING        0.0
#define SAMD_INTERIOR_HEALTH_INSURANCE_COORDS   1460.9501, -997.5841, 675.6033
#define SAMD_GARAGE_ELEVATOR_COORDS               1091.2504,-1357.4307,13.7805

#define SAMD_INTERIOR_SPAWN_POINT               1462.2633, -981.9429, 675.6134
#define SAMD_INTERIOR_SPAWN_POINT_FACING        180.0
#define SAMD_INTERIOR_DUTY_POINT                1466.7092, -983.1359, 675.6134

// Map variables
new object_samdInterior[284];
new pickup_samdInterior[4];
new text3D_samdInterior[2];
new actor_samdInterior[3];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 2.0, SAMD_INTERIOR_EXIT_COORDS) && GetPlayerVirtualWorld(playerid) == VW_SAMDINTERIOR) { // Exit
            SetPlayerFacingAngle(playerid, SAMD_INTERIOR_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, SAMD_INTERIOR_ENTER_COORDS, MAPS_SAMDEXTERIOR_INTERIOR, VW_MAIN);
            return 1;
        /*} else if (IsPlayerInRangeOfPoint(playerid, 1.0, SAMD_INTERIOR_ELEVATOR_1_DOWN_COORDS) && GetPlayerVirtualWorld(playerid) == VW_SAMDINTERIOR) { // Elevator 1
            SetPlayerFacingAngle(playerid, SAMD_INTERIOR_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, SAMD_INTERIOR_ELEVATOR_1_UP_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_SAMDINTERIOR2);
            return 1;*/
        } else if (IsPlayerInRangeOfPoint(playerid, 1.0, SAMD_INTERIOR_ELEVATOR_2_DOWN_COORDS) && GetPlayerVirtualWorld(playerid) == VW_SAMDINTERIOR) { // Elevator 2
            SetPlayerFacingAngle(playerid, SAMD_INTERIOR_ELEVATOR_UP_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, SAMD_INTERIOR_ELEVATOR_2_UP_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_SAMDINTERIOR2);
            return 1;
        }else if(IsPlayerInRangeOfPoint(playerid,1.0,SAMD_INTERIOR_ELEVATOR_1_DOWN_COORDS) && GetPlayerVirtualWorld(playerid) == VW_SAMDINTERIOR){ // Aufzug zu Garage
            SetPlayerPosEx(playerid, SAMD_GARAGE_ELEVATOR_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_MAIN);
            SetCameraBehindPlayer(playerid);
            return 1;
        }else if(IsPlayerInRangeOfPoint(playerid,1.0,SAMD_GARAGE_ELEVATOR_COORDS)){ //Aufzug von Garage
        SetPlayerPosEx(playerid,SAMD_INTERIOR_ELEVATOR_1_DOWN_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_SAMDINTERIOR);
        SetCameraBehindPlayer(playerid);
        return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
	// Pickups
	pickup_samdInterior[0] = CreateDynamicPickup(1239, 1, SAMD_INTERIOR_HEALTH_INSURANCE_COORDS, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR); // Health insurance
    pickup_samdInterior[1] = CreateDynamicPickup(19197, 1, SAMD_INTERIOR_ELEVATOR_1_DOWN_COORDS, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR); // Elevator 1
    pickup_samdInterior[2] = CreateDynamicPickup(19197, 1, SAMD_INTERIOR_ELEVATOR_2_DOWN_COORDS, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR); // Elevator 2
    pickup_samdInterior[3] = CreateDynamicPickup(19197, 1, SAMD_GARAGE_ELEVATOR_COORDS, VW_MAIN, MAPS_SAMDINTERIOR_INTERIOR); // Elevator Garage
	// 3DTextLabels
	text3D_samdInterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Krankenversicherung\n" COLOR_HEX_WHITE "Keine Behandlungskosten für 7 Tage! Preis: $50.000\nTippe /Krankenversicherung", COLOR_WHITE, SAMD_INTERIOR_HEALTH_INSURANCE_COORDS, 25.0, .testlos = 1, .worldid = VW_SAMDINTERIOR, .interiorid = MAPS_SAMDINTERIOR_INTERIOR); // Health insurance
    text3D_samdInterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "AUFZUG GARAGE", COLOR_YELLOW, SAMD_INTERIOR_ELEVATOR_1_DOWN_COORDS, 25.0, .testlos = 1, .worldid = VW_SAMDINTERIOR, .interiorid = MAPS_SAMDINTERIOR_INTERIOR); // Elevator 1 Out of Order

    // Actors
    actor_samdInterior[0] = CreateDynamicActor(308, 1463.3958, -995.9808, 675.6033, 90.0000, .worldid = VW_SAMDINTERIOR, .interiorid = MAPS_SAMDINTERIOR_INTERIOR);
    actor_samdInterior[1] = CreateDynamicActor(274, 1463.3962, -997.5598, 675.6033, 90.0000, .worldid = VW_SAMDINTERIOR, .interiorid = MAPS_SAMDINTERIOR_INTERIOR);
    actor_samdInterior[2] = CreateDynamicActor(276, 1463.3967, -999.2609, 675.6033, 90.0000, .worldid = VW_SAMDINTERIOR, .interiorid = MAPS_SAMDINTERIOR_INTERIOR);

	// Objects
	object_samdInterior[0] = CreateDynamicObject(19464, 1451.3685, -1001.4539, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[0], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[1] = CreateDynamicObject(18981, 1455.6219, -1002.9718, 674.1033, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_samdInterior[1], 0, 14488, "dogsgym", "AH_bgmartiles", 0xFFFFFFFF);
    object_samdInterior[2] = CreateDynamicObject(19464, 1457.2789, -1001.4580, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[2], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[3] = CreateDynamicObject(18762, 1462.5539, -1000.8618, 676.9522, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[3], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[4] = CreateDynamicObject(18762, 1462.5539, -993.9918, 676.9522, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[4], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[5] = CreateDynamicObject(19464, 1457.3281, -990.3745, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[5], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[6] = CreateDynamicObject(19464, 1451.3979, -990.3745, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[6], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[7] = CreateDynamicObject(19464, 1448.5279, -998.6046, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[7], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[8] = CreateDynamicObject(19464, 1448.5279, -992.6649, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[8], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[9] = CreateDynamicObject(18766, 1446.1893, -996.3944, 676.3732, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[9], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[10] = CreateDynamicObject(18766, 1446.1893, -986.4746, 676.3734, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[10], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[11] = CreateDynamicObject(18766, 1446.1893, -986.4746, 674.2133, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[11], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[12] = CreateDynamicObject(18766, 1451.7392, -1003.8153, 677.9628, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[12], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[13] = CreateDynamicObject(18766, 1446.1893, -996.4348, 679.9230, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[13], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[14] = CreateDynamicObject(18766, 1446.1893, -986.4650, 679.9232, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[14], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[15] = CreateDynamicObject(18766, 1446.1893, -996.4348, 674.2133, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[15], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[16] = CreateDynamicObject(18766, 1446.1893, -986.4650, 677.9628, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[16], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[17] = CreateDynamicObject(11714, 1448.6679, -995.9509, 675.8566, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MaintenanceDoors1
    object_samdInterior[18] = CreateDynamicObject(18981, 1455.6219, -1002.9718, 680.0332, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_samdInterior[18], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[19] = CreateDynamicObject(19565, 1448.6495, -994.4436, 677.0604, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[19], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[20] = CreateDynamicObject(19565, 1448.6495, -997.7236, 677.0604, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[20], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[21] = CreateDynamicObject(19565, 1448.6495, -995.3432, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[21], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[22] = CreateDynamicObject(19565, 1448.6495, -997.0137, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[22], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[23] = CreateDynamicObject(19565, 1448.6495, -996.5537, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[23], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[24] = CreateDynamicObject(19565, 1448.6495, -994.4035, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[24], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[25] = CreateDynamicObject(19565, 1448.6495, -994.8734, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[25], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[26] = CreateDynamicObject(19565, 1448.6495, -995.8031, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[26], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[27] = CreateDynamicObject(19565, 1448.6495, -996.0833, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[27], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[28] = CreateDynamicObject(19565, 1448.6495, -994.4436, 675.1804, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[28], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[29] = CreateDynamicObject(19565, 1448.6495, -994.4436, 675.6405, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[29], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[30] = CreateDynamicObject(19565, 1448.6495, -997.7333, 675.6904, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[30], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[31] = CreateDynamicObject(19565, 1448.6495, -997.7333, 675.2205, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[31], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[32] = CreateDynamicObject(19565, 1448.6495, -994.4436, 674.7205, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[32], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[33] = CreateDynamicObject(19565, 1448.6495, -997.7333, 674.7506, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[33], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[34] = CreateDynamicObject(19565, 1448.6495, -997.4837, 677.0604, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[34], 0, 10765, "airportgnd_sfse", "white", 0xFF7B0A2A);
    object_samdInterior[35] = CreateDynamicObject(19464, 1463.2674, -990.3745, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[35], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[36] = CreateDynamicObject(11711, 1448.6656, -995.9738, 677.2222, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ExitSign1
    SetDynamicObjectMaterial(object_samdInterior[36], 0, 14785, "gen_offtrackint", "exitgreen_64", 0xFFFFFFFF);
    object_samdInterior[37] = CreateDynamicObject(19464, 1463.1975, -1001.4547, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[37], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[38] = CreateDynamicObject(18766, 1446.1893, -996.4550, 677.9628, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[38], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[39] = CreateDynamicObject(18766, 1451.7392, -1003.8153, 676.3626, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[39], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[40] = CreateDynamicObject(18766, 1461.7287, -1003.8153, 676.3626, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[40], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[41] = CreateDynamicObject(18766, 1461.7287, -1003.8153, 677.9625, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[41], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[42] = CreateDynamicObject(18766, 1453.5382, -1003.8153, 679.9223, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[42], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[43] = CreateDynamicObject(18766, 1463.5183, -1003.8153, 679.9223, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[43], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[44] = CreateDynamicObject(18766, 1453.5482, -1003.8153, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[44], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[45] = CreateDynamicObject(18766, 1463.5478, -1003.8153, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[45], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[46] = CreateDynamicObject(18766, 1463.5478, -988.0250, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[46], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[47] = CreateDynamicObject(18766, 1453.5482, -988.0250, 674.2119, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[47], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[48] = CreateDynamicObject(18766, 1453.5482, -988.0250, 679.9218, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[48], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[49] = CreateDynamicObject(18766, 1463.5384, -988.0250, 679.9218, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[49], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[50] = CreateDynamicObject(18766, 1453.5583, -988.0250, 677.9619, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[50], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[51] = CreateDynamicObject(18766, 1463.5583, -988.0250, 677.9619, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[51], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[52] = CreateDynamicObject(18766, 1453.6579, -988.0250, 676.3623, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[52], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[53] = CreateDynamicObject(18766, 1463.6573, -988.0250, 676.3623, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[53], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[54] = CreateDynamicObject(3051, 1453.4558, -1001.3096, 675.9667, 0.0000, 0.0000, -43.6999, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_samdInterior[54], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_samdInterior[55] = CreateDynamicObject(3051, 1456.5815, -1001.3095, 675.9667, 0.0000, 0.0000, -43.6999, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_samdInterior[55], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_samdInterior[56] = CreateDynamicObject(19175, 1457.2138, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[56], 0, "EG", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[56], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[57] = CreateDynamicObject(3051, 1454.6435, -1001.3146, 675.9667, 0.0000, 0.0000, 136.3000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_samdInterior[57], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_samdInterior[58] = CreateDynamicObject(3051, 1457.7705, -1001.3126, 675.9667, 0.0000, 0.0000, 136.3999, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lift_dr
    SetDynamicObjectMaterial(object_samdInterior[58], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0xFFFFFFFF);
    object_samdInterior[59] = CreateDynamicObject(19175, 1454.0938, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[59], 0, "EG", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[59], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[60] = CreateDynamicObject(19175, 1454.0938, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[60], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[60], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[61] = CreateDynamicObject(19175, 1454.0938, -1001.3010, 677.8820, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[61], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[61], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[62] = CreateDynamicObject(19175, 1453.2838, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[62], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[62], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[63] = CreateDynamicObject(19175, 1454.6440, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[63], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[63], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[64] = CreateDynamicObject(19175, 1457.1839, -1001.3010, 677.6220, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[64], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[64], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[65] = CreateDynamicObject(19175, 1457.1838, -1001.3010, 677.8820, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[65], 0, "____________", 90, "Arial", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[65], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[66] = CreateDynamicObject(19175, 1456.3741, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[66], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[66], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[67] = CreateDynamicObject(19175, 1457.7343, -1001.3010, 677.6317, 0.0000, 90.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[67], 0, "__", 90, "Arial", 26, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[67], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[68] = CreateDynamicObject(19175, 1455.5832, -1001.3211, 676.0718, 0.0000, 180.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[68], 0, "y", 90, "Wingdings", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[68], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[69] = CreateDynamicObject(19175, 1455.5832, -1001.3211, 676.2221, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[69], 0, "y", 90, "Wingdings", 24, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[69], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[70] = CreateDynamicObject(18075, 1453.0991, -995.8640, 679.6024, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_samdInterior[71] = CreateDynamicObject(18075, 1463.5500, -995.8640, 679.6024, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
    object_samdInterior[72] = CreateDynamicObject(18766, 1458.3153, -986.5477, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[72], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[73] = CreateDynamicObject(18766, 1452.9439, -986.6677, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[73], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[74] = CreateDynamicObject(18766, 1448.5946, -986.6588, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[74], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[75] = CreateDynamicObject(18766, 1462.5765, -1005.4172, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[75], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[76] = CreateDynamicObject(18766, 1452.2552, -993.6773, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[76], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[77] = CreateDynamicObject(18766, 1462.2541, -993.6773, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[77], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[78] = CreateDynamicObject(18766, 1462.2541, -998.0974, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[78], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[79] = CreateDynamicObject(18766, 1452.2547, -998.0974, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[79], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[80] = CreateDynamicObject(18766, 1448.5946, -996.6386, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[80], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[81] = CreateDynamicObject(18766, 1462.5765, -995.4174, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[81], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[82] = CreateDynamicObject(18766, 1458.3153, -996.5479, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[82], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[83] = CreateDynamicObject(18766, 1452.9439, -996.6685, 682.0175, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[83], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[84] = CreateDynamicObject(19450, 1453.3864, -997.8765, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[84], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[85] = CreateDynamicObject(19450, 1453.3864, -998.3267, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[85], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[86] = CreateDynamicObject(19450, 1463.0168, -997.8765, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[86], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[87] = CreateDynamicObject(19450, 1463.0168, -998.3264, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[87], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[88] = CreateDynamicObject(19450, 1463.0168, -993.9058, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[88], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[89] = CreateDynamicObject(19450, 1463.0168, -993.4354, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[89], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[90] = CreateDynamicObject(19450, 1453.3852, -993.9058, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[90], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[91] = CreateDynamicObject(19450, 1453.3852, -993.4354, 681.2546, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
    SetDynamicObjectMaterial(object_samdInterior[91], 0, 10765, "airportgnd_sfse", "white", 0xFF840410);
    object_samdInterior[92] = CreateDynamicObject(2125, 1457.2263, -996.5808, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[92], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[93] = CreateDynamicObject(2125, 1457.2263, -995.6304, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[93], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[94] = CreateDynamicObject(1811, 1457.1905, -996.5625, 675.1563, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[94], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[95] = CreateDynamicObject(1811, 1457.1905, -995.6213, 675.1563, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[95], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[96] = CreateDynamicObject(2125, 1456.2557, -996.5808, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[96], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[97] = CreateDynamicObject(2125, 1455.3348, -996.5808, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[97], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[98] = CreateDynamicObject(2125, 1454.3739, -996.5808, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[98], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[99] = CreateDynamicObject(2125, 1453.2730, -996.5808, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[99], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[100] = CreateDynamicObject(1811, 1456.2999, -996.5625, 675.1563, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[100], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[101] = CreateDynamicObject(1811, 1455.3488, -996.5625, 675.1563, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[101], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[102] = CreateDynamicObject(1811, 1454.4083, -996.5625, 675.1563, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[102], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[103] = CreateDynamicObject(1811, 1453.3072, -996.5625, 675.1563, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[103], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[104] = CreateDynamicObject(2125, 1456.2453, -995.6304, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[104], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[105] = CreateDynamicObject(2125, 1455.3646, -995.6304, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[105], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[106] = CreateDynamicObject(2125, 1454.4039, -995.6304, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[106], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[107] = CreateDynamicObject(2125, 1453.2928, -995.6304, 674.9063, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_1
    SetDynamicObjectMaterial(object_samdInterior[107], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[108] = CreateDynamicObject(1811, 1456.2796, -995.6213, 675.1563, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[108], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[109] = CreateDynamicObject(1811, 1455.3391, -995.6213, 675.1563, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[109], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[110] = CreateDynamicObject(1811, 1454.3980, -995.6213, 675.1563, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[110], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[111] = CreateDynamicObject(19430, 1454.5191, -996.0631, 674.5145, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[111], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_samdInterior[112] = CreateDynamicObject(19565, 1452.9991, -1001.3632, 677.3004, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[112], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[113] = CreateDynamicObject(19565, 1453.4697, -1001.3632, 677.3004, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[113], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[114] = CreateDynamicObject(19565, 1453.9300, -1001.3632, 677.3004, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[114], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[115] = CreateDynamicObject(19565, 1454.4005, -1001.3632, 677.3004, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[115], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[116] = CreateDynamicObject(19565, 1454.8509, -1001.3632, 677.3004, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[116], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[117] = CreateDynamicObject(19565, 1455.0910, -1001.3632, 677.3004, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[117], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[118] = CreateDynamicObject(19565, 1455.0511, -1001.3632, 677.0805, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[118], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[119] = CreateDynamicObject(19565, 1452.7607, -1001.3632, 677.0805, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[119], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[120] = CreateDynamicObject(19565, 1455.9018, -1001.3632, 677.0805, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[120], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[121] = CreateDynamicObject(19565, 1458.1729, -1001.3632, 677.0805, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[121], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[122] = CreateDynamicObject(19565, 1458.2131, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[122], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[123] = CreateDynamicObject(19565, 1456.1424, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[123], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[124] = CreateDynamicObject(19565, 1456.6129, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[124], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[125] = CreateDynamicObject(19565, 1457.0822, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[125], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[126] = CreateDynamicObject(19565, 1457.7530, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[126], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[127] = CreateDynamicObject(19565, 1457.2827, -1001.3632, 677.2105, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[127], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[128] = CreateDynamicObject(19565, 1455.9029, -1001.3632, 675.6303, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[128], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[129] = CreateDynamicObject(19565, 1455.9029, -1001.3632, 675.1701, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[129], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[130] = CreateDynamicObject(19565, 1455.9029, -1001.3632, 674.6998, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[130], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[131] = CreateDynamicObject(19565, 1455.0521, -1001.3632, 675.6398, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[131], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[132] = CreateDynamicObject(19565, 1455.0521, -1001.3632, 675.1795, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[132], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[133] = CreateDynamicObject(19565, 1455.0521, -1001.3632, 674.7091, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[133], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[134] = CreateDynamicObject(19565, 1452.7611, -1001.3632, 675.6394, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[134], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[135] = CreateDynamicObject(19565, 1452.7611, -1001.3632, 675.1693, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[135], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[136] = CreateDynamicObject(19565, 1452.7611, -1001.3632, 674.6992, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[136], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[137] = CreateDynamicObject(19565, 1458.1723, -1001.3632, 675.6389, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[137], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[138] = CreateDynamicObject(19565, 1458.1723, -1001.3632, 675.1687, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[138], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[139] = CreateDynamicObject(19565, 1458.1723, -1001.3632, 674.6984, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[139], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[140] = CreateDynamicObject(1811, 1453.3172, -995.6213, 675.1563, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_DIN_CHAIR_5
    SetDynamicObjectMaterial(object_samdInterior[140], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[141] = CreateDynamicObject(19430, 1456.0804, -996.0631, 674.5164, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[141], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_samdInterior[142] = CreateDynamicObject(19430, 1456.0804, -996.0631, 674.5164, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[142], 0, 14847, "mp_policesf", "mp_cop_carpet", 0xFFFFFFFF);
    object_samdInterior[143] = CreateDynamicObject(19430, 1456.0804, -995.3226, 673.8060, 90.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[143], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[144] = CreateDynamicObject(19430, 1456.0804, -996.8734, 673.8060, 90.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[144], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[145] = CreateDynamicObject(19430, 1454.5091, -996.8729, 673.8040, 90.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[145], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[146] = CreateDynamicObject(19430, 1457.7412, -996.0628, 672.8560, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[146], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[147] = CreateDynamicObject(1522, 1453.2943, -990.4735, 674.5986, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_samdInterior[147], 0, 2878, "cj_vic", "CJ_VICT_DOOR", 0xFFFFFFFF);
    object_samdInterior[148] = CreateDynamicObject(19430, 1452.8498, -996.0628, 672.8560, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[148], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[149] = CreateDynamicObject(19430, 1454.5091, -995.3226, 673.8040, 90.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
    SetDynamicObjectMaterial(object_samdInterior[149], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[150] = CreateDynamicObject(19565, 1456.7430, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[150], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[151] = CreateDynamicObject(1522, 1456.1341, -990.4735, 674.5986, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
    SetDynamicObjectMaterial(object_samdInterior[151], 0, 18008, "intclothesa", "CJ_VICT_DOOR2", 0xFFFFFFFF);
    object_samdInterior[152] = CreateDynamicObject(19565, 1456.2827, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[152], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[153] = CreateDynamicObject(19565, 1457.2136, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[153], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[154] = CreateDynamicObject(19565, 1457.5139, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[154], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[155] = CreateDynamicObject(19565, 1454.6737, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[155], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[156] = CreateDynamicObject(19565, 1454.2038, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[156], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[157] = CreateDynamicObject(19565, 1453.7436, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[157], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[158] = CreateDynamicObject(19565, 1453.4442, -990.4932, 676.9505, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[158], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[159] = CreateDynamicObject(19565, 1453.4442, -990.4932, 676.8604, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[159], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[160] = CreateDynamicObject(19565, 1454.6745, -990.4932, 676.8604, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[160], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[161] = CreateDynamicObject(19565, 1456.2840, -990.4932, 676.8604, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[161], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[162] = CreateDynamicObject(19565, 1457.5152, -990.4932, 676.8604, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[162], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[163] = CreateDynamicObject(19565, 1457.4753, -990.4932, 675.6199, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[163], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[164] = CreateDynamicObject(19565, 1457.4753, -990.4932, 675.1696, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[164], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[165] = CreateDynamicObject(19565, 1457.4753, -990.4932, 674.7000, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[165], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[166] = CreateDynamicObject(19565, 1456.0445, -990.4932, 675.6301, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[166], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[167] = CreateDynamicObject(19565, 1456.0445, -990.4932, 675.1599, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[167], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[168] = CreateDynamicObject(19565, 1456.0445, -990.4932, 674.6998, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[168], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[169] = CreateDynamicObject(19565, 1454.6335, -990.4932, 675.6295, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[169], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[170] = CreateDynamicObject(19565, 1454.6335, -990.4932, 675.1596, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[170], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[171] = CreateDynamicObject(19565, 1454.6335, -990.4932, 674.6892, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[171], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[172] = CreateDynamicObject(19565, 1453.2126, -990.4932, 675.6295, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[172], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[173] = CreateDynamicObject(19565, 1453.2126, -990.4932, 675.1596, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[173], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[174] = CreateDynamicObject(19565, 1453.2126, -990.4932, 674.6898, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //IceCreamBarsBox1
    SetDynamicObjectMaterial(object_samdInterior[174], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[175] = CreateDynamicObject(19175, 1455.4632, -990.5114, 677.8021, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[175], 0, "WC", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[175], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[176] = CreateDynamicObject(19175, 1455.9034, -990.5114, 676.2714, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[176], 0, "Damen", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[176], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[177] = CreateDynamicObject(19175, 1455.0428, -990.5114, 676.7017, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[177], 0, "________", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[177], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[178] = CreateDynamicObject(19175, 1455.0827, -990.5114, 676.5415, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[178], 0, "Herren", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[178], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[179] = CreateDynamicObject(19175, 1455.0428, -990.5114, 676.5114, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[179], 0, "________", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[179], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[180] = CreateDynamicObject(19175, 1455.9134, -990.5114, 676.4415, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[180], 0, "________", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[180], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[181] = CreateDynamicObject(19175, 1455.9134, -990.5114, 676.2415, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[181], 0, "________", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[181], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[182] = CreateDynamicObject(19175, 1455.6932, -990.5114, 676.2614, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[182], 0, "___", 130, "Arial", 29, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[182], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[183] = CreateDynamicObject(19175, 1455.4029, -990.5114, 676.5317, 0.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[183], 0, "___", 130, "Arial", 29, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[183], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[184] = CreateDynamicObject(19452, 1448.6180, -992.2463, 674.6970, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall092
    SetDynamicObjectMaterial(object_samdInterior[184], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_samdInterior[185] = CreateDynamicObject(19452, 1448.6180, -999.6569, 674.6970, 90.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall092
    SetDynamicObjectMaterial(object_samdInterior[185], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_samdInterior[186] = CreateDynamicObject(19452, 1448.6080, -995.2965, 679.1967, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall092
    SetDynamicObjectMaterial(object_samdInterior[186], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
    object_samdInterior[187] = CreateDynamicObject(18766, 1462.5457, -999.3781, 673.3037, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[187], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[188] = CreateDynamicObject(1649, 1462.4332, -1001.1080, 678.7218, 0.0000, 0.0000, 270.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_samdInterior[188], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_samdInterior[189] = CreateDynamicObject(1649, 1462.4332, -996.6682, 678.7211, 0.0000, 0.0000, 270.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_samdInterior[189], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_samdInterior[190] = CreateDynamicObject(1649, 1462.4332, -996.6682, 678.7211, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_samdInterior[190], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_samdInterior[191] = CreateDynamicObject(1649, 1462.4332, -1001.1088, 678.7211, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
    SetDynamicObjectMaterial(object_samdInterior[191], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
    object_samdInterior[192] = CreateDynamicObject(19089, 1462.4355, -998.8853, 684.4215, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_samdInterior[192], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[193] = CreateDynamicObject(19089, 1462.4355, -994.2241, 677.0520, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_samdInterior[193], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[194] = CreateDynamicObject(19089, 1462.4355, -996.1350, 684.4215, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_samdInterior[194], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[195] = CreateDynamicObject(19089, 1462.4355, -994.4635, 678.6898, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_samdInterior[195], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[196] = CreateDynamicObject(18762, 1462.5638, -993.9818, 677.2224, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[196], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[197] = CreateDynamicObject(1536, 1460.9912, -992.1058, 674.5522, 0.0000, 0.0000, 36.0999, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorEXT15
    SetDynamicObjectMaterial(object_samdInterior[197], 0, 1569, "adam_v_doort", "ws_guardhousedoor", 0xFFFFFFFF);
    SetDynamicObjectMaterial(object_samdInterior[197], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[198] = CreateDynamicObject(19383, 1462.1462, -992.0239, 676.3167, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
    SetDynamicObjectMaterial(object_samdInterior[198], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[199] = CreateDynamicObject(18762, 1462.5539, -996.9918, 679.1926, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[199], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[200] = CreateDynamicObject(18762, 1462.5638, -1001.9713, 679.1926, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[200], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[201] = CreateDynamicObject(19175, 1462.0654, -993.2716, 676.4915, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[201], 0, "______________", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[201], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[202] = CreateDynamicObject(19175, 1462.0654, -993.2716, 676.3115, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[202], 0, "STAFF ONLY", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[202], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[203] = CreateDynamicObject(19175, 1462.0654, -993.2716, 676.2714, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[203], 0, "______________", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[203], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[204] = CreateDynamicObject(19175, 1462.0654, -993.8519, 676.3115, 0.0000, 90.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[204], 0, "___", 130, "Arial", 30, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[204], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[205] = CreateDynamicObject(19383, 1462.1462, -992.0236, 679.8170, 0.0000, 180.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
    SetDynamicObjectMaterial(object_samdInterior[205], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[206] = CreateDynamicObject(19383, 1462.1562, -992.0236, 678.0661, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall031
    SetDynamicObjectMaterial(object_samdInterior[206], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[207] = CreateDynamicObject(18762, 1462.5239, -996.9821, 675.3118, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[207], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_samdInterior[208] = CreateDynamicObject(18762, 1462.5339, -997.8623, 675.3098, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[208], 0, 14581, "ab_mafiasuitea", "cof_wood2", 0xFFFFFFFF);
    object_samdInterior[209] = CreateDynamicObject(19089, 1462.4355, -994.4844, 684.4216, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_samdInterior[209], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[210] = CreateDynamicObject(19089, 1462.4355, -1000.3551, 684.4216, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Rope3
    SetDynamicObjectMaterial(object_samdInterior[210], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[211] = CreateDynamicObject(19175, 1462.4353, -995.3712, 677.9423, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[211], 0, "i", 130, "Webdings", 130, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[211], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[212] = CreateDynamicObject(19175, 1462.4353, -997.5217, 677.9121, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[212], 0, "Anmeldung", 90, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[212], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[213] = CreateDynamicObject(19175, 1462.4353, -999.6516, 677.9423, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[213], 0, "i", 130, "Webdings", 130, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[213], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[214] = CreateDynamicObject(19175, 1462.4353, -997.5017, 678.2222, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[214], 0, "_________________________________", 100, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[214], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[215] = CreateDynamicObject(19175, 1462.4353, -997.5017, 677.7421, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[215], 0, "_________________________________", 100, "Arial", 40, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[215], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[216] = CreateDynamicObject(19464, 1469.1971, -990.3745, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[216], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[217] = CreateDynamicObject(19464, 1469.1270, -1001.4550, 677.0742, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[217], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[218] = CreateDynamicObject(19464, 1468.1864, -998.4249, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[218], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[219] = CreateDynamicObject(19464, 1468.1864, -992.4942, 677.0742, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_samdInterior[219], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
    object_samdInterior[220] = CreateDynamicObject(18766, 1470.5180, -995.5045, 676.3623, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[220], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[221] = CreateDynamicObject(18766, 1470.5180, -1005.5042, 676.3623, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[221], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[222] = CreateDynamicObject(18766, 1471.7177, -1003.8143, 676.3623, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[222], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[223] = CreateDynamicObject(18766, 1471.7177, -1003.8143, 677.9625, 90.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[223], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[224] = CreateDynamicObject(18766, 1470.5356, -996.3646, 677.9625, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[224], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[225] = CreateDynamicObject(18766, 1470.5356, -986.3651, 677.9625, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[225], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[226] = CreateDynamicObject(18766, 1470.5356, -986.3651, 674.2125, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[226], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[227] = CreateDynamicObject(18766, 1470.5356, -996.3842, 674.2125, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[227], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[228] = CreateDynamicObject(18766, 1470.5356, -996.3842, 679.9223, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[228], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[229] = CreateDynamicObject(18766, 1470.5356, -986.3845, 679.9223, 90.0000, 90.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[229], 0, 10765, "airportgnd_sfse", "white", 0xFF5F0A15);
    object_samdInterior[230] = CreateDynamicObject(18766, 1472.2534, -993.6773, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[230], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[231] = CreateDynamicObject(18766, 1472.2534, -998.0985, 682.0175, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_samdInterior[231], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
    object_samdInterior[232] = CreateDynamicObject(19175, 1462.0350, -996.0114, 675.3317, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[232], 0, "1", 90, "Arial", 45, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[232], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[233] = CreateDynamicObject(19175, 1462.0350, -999.0618, 675.3317, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[233], 0, "3", 90, "Arial", 45, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[233], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[234] = CreateDynamicObject(19175, 1462.0350, -996.0112, 675.3416, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[234], 0, "c", 90, "Webdings", 50, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[234], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[235] = CreateDynamicObject(19175, 1462.0350, -997.5615, 675.3317, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[235], 0, "2", 90, "Arial", 45, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[235], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[236] = CreateDynamicObject(19175, 1462.0350, -997.5615, 675.3416, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[236], 0, "c", 90, "Webdings", 50, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[236], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[237] = CreateDynamicObject(19175, 1462.0350, -999.0620, 675.3416, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[237], 0, "c", 90, "Webdings", 50, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[237], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[238] = CreateDynamicObject(2164, 1465.1563, -1001.2930, 674.5921, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_5
    object_samdInterior[239] = CreateDynamicObject(2161, 1466.9239, -1001.2976, 675.8933, 0.0000, 0.0000, 180.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_4
    object_samdInterior[240] = CreateDynamicObject(2163, 1468.2353, -992.1754, 675.6295, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_samdInterior[241] = CreateDynamicObject(2163, 1468.2353, -998.8457, 675.6295, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_2
    object_samdInterior[242] = CreateDynamicObject(2162, 1468.0467, -995.6303, 674.5885, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_1
    object_samdInterior[243] = CreateDynamicObject(2167, 1468.1108, -997.5277, 674.6019, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
    object_samdInterior[244] = CreateDynamicObject(2167, 1468.1108, -994.4774, 674.6019, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //MED_OFFICE_UNIT_7
    object_samdInterior[245] = CreateDynamicObject(16377, 1466.8885, -991.2139, 675.5413, 0.0000, 0.0000, 144.6999, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tv_stand_by
    object_samdInterior[246] = CreateDynamicObject(16377, 1465.2562, -991.0628, 675.5413, 0.0000, 0.0000, 144.6999, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tv_stand_by
    object_samdInterior[247] = CreateDynamicObject(1714, 1464.3249, -996.0477, 674.6038, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_samdInterior[248] = CreateDynamicObject(1714, 1464.3249, -997.6279, 674.6038, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_samdInterior[249] = CreateDynamicObject(1714, 1464.3249, -999.2186, 674.6038, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_swivelchair1
    object_samdInterior[250] = CreateDynamicObject(19273, 1462.2066, -993.0828, 675.8120, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //KeypadNonDynamic
    object_samdInterior[251] = CreateDynamicObject(19273, 1462.0865, -993.2827, 675.8120, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //KeypadNonDynamic
    object_samdInterior[252] = CreateDynamicObject(19808, 1462.7413, -997.5413, 675.8281, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_samdInterior[253] = CreateDynamicObject(19808, 1462.7413, -999.2612, 675.8281, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_samdInterior[254] = CreateDynamicObject(19808, 1462.7413, -995.9909, 675.8281, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Keyboard1
    object_samdInterior[255] = CreateDynamicObject(2263, 1462.9327, -995.9862, 675.9511, -6.2999, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_samdInterior[255], 0, 10765, "airportgnd_sfse", "white", 0xFF4C75B7);
    SetDynamicObjectMaterial(object_samdInterior[255], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[256] = CreateDynamicObject(2263, 1462.9327, -997.5662, 675.9511, -6.2999, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_samdInterior[256], 0, 10765, "airportgnd_sfse", "white", 0xFF2A77A1);
    SetDynamicObjectMaterial(object_samdInterior[256], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[257] = CreateDynamicObject(2263, 1462.9327, -999.2764, 675.9511, -6.2999, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_samdInterior[257], 0, 10765, "airportgnd_sfse", "white", 0xFF2A77A1);
    SetDynamicObjectMaterial(object_samdInterior[257], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[258] = CreateDynamicObject(2263, 1461.9488, -997.5261, 675.8422, 6.2999, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_samdInterior[258], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    SetDynamicObjectMaterial(object_samdInterior[258], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[259] = CreateDynamicObject(2263, 1461.9488, -999.2363, 675.8422, 6.2999, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_samdInterior[259], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    SetDynamicObjectMaterial(object_samdInterior[259], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[260] = CreateDynamicObject(2263, 1461.9488, -995.9458, 675.8422, 6.2999, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Frame_SLIM_4
    SetDynamicObjectMaterial(object_samdInterior[260], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    SetDynamicObjectMaterial(object_samdInterior[260], 1, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[261] = CreateDynamicObject(2601, 1462.3562, -997.5656, 675.9000, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[261], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[262] = CreateDynamicObject(2601, 1462.3562, -995.9752, 675.9000, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[262], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[263] = CreateDynamicObject(2601, 1462.3562, -995.9752, 676.0601, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[263], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[264] = CreateDynamicObject(2601, 1462.3762, -995.9750, 676.1400, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[264], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[265] = CreateDynamicObject(2601, 1462.3562, -997.5656, 676.0700, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[265], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[266] = CreateDynamicObject(2601, 1462.3562, -997.5656, 676.1901, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[266], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[267] = CreateDynamicObject(2601, 1462.3562, -999.2557, 675.8297, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[267], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[268] = CreateDynamicObject(2601, 1462.3762, -995.9750, 675.7899, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[268], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[269] = CreateDynamicObject(2601, 1462.3562, -997.5656, 675.8297, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[269], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[270] = CreateDynamicObject(2601, 1462.3562, -999.2557, 676.0698, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[270], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[271] = CreateDynamicObject(2601, 1462.3562, -999.2557, 675.9298, 0.0000, 0.0000, 0.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[271], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[272] = CreateDynamicObject(2601, 1462.3562, -999.2557, 676.1198, 0.0000, 90.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_JUICE_CAN
    SetDynamicObjectMaterial(object_samdInterior[272], 0, 10765, "airportgnd_sfse", "white", 0xFF000000);
    object_samdInterior[273] = CreateDynamicObject(19175, 1462.4151, -999.2420, 676.2332, -6.2999, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[273], 0, "Windows 10", 130, "Arial", 18, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[273], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[274] = CreateDynamicObject(19175, 1462.4151, -997.5418, 676.2332, -6.2999, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[274], 0, "Windows 10", 130, "Arial", 18, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[274], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[275] = CreateDynamicObject(19175, 1462.4151, -995.9515, 676.2332, -6.2999, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[275], 0, "Windows 10", 130, "Arial", 18, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[275], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[276] = CreateDynamicObject(19807, 1462.5505, -998.3848, 675.8701, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telephone1
    object_samdInterior[277] = CreateDynamicObject(19807, 1462.5505, -996.7346, 675.8701, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telephone1
    object_samdInterior[278] = CreateDynamicObject(19814, 1463.0506, -996.7371, 675.5280, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_samdInterior[279] = CreateDynamicObject(19814, 1463.0506, -998.3873, 675.5280, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ElectricalOutlet2
    object_samdInterior[280] = CreateDynamicObject(11713, 1451.1019, -990.5280, 676.0142, 0.0000, 0.0000, -90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FireExtPanel1
    object_samdInterior[281] = CreateDynamicObject(11713, 1451.1019, -1001.2980, 676.0142, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //FireExtPanel1
    object_samdInterior[282] = CreateDynamicObject(19175, 1462.4353, -995.2611, 677.9423, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[282], 0, "i", 130, "Webdings", 130, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[282], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_samdInterior[283] = CreateDynamicObject(19175, 1462.4353, -999.5816, 677.9423, 0.0000, 0.0000, 90.0000, VW_SAMDINTERIOR, MAPS_SAMDINTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_samdInterior[283], 0, "i", 130, "Webdings", 130, 1, 0xFFFFFFFF, 0x0, 1);
    SetDynamicObjectMaterial(object_samdInterior[283], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
}
