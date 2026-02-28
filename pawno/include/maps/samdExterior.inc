#include <YSI\y_hooks>

// Global interior define
#define MAPS_SAMDEXTERIOR_INTERIOR      0
#define MAPS_SAMDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// SAMD enter / exit points, staterepair and garage points
#define SAMD_INTERIOR_ENTER_COORDS		1465.6685, -1048.3032, 24.0305
#define SAMD_INTERIOR_EXIT_COORDS		1449.6344, -995.9602, 675.6033
#define SAMD_INTERIOR_ENTER_FACING		0.0
#define SAMD_INTERIOR_EXIT_FACING   	270.0
#define SAMD_STATEREPAIR_COORDS			1449.4838, -1070.6021, 16.8900
#define SAMD_GARAGE_FOR_RANGE_COORDS	1440.6060, -1066.2077, 21.7887
#define SAMD_GARAGE_OPEN_Z				16.2287
#define SAMD_GARAGE_CLOSED_Z			21.7887

// Map variables
new object_samdExterior[381];
new pickup_samdExterior[1];
new text3D_samdExterior[2];
new object_samdExterior_garageDoor;

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 4585, 1451.9922, -1067.3984, 112.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 4626, 1451.9922, -1067.3984, 112.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 4743, 1451.9922, -1067.3984, 112.5391, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1453.5000, -1038.1484, 27.3516, 0.25);
	RemoveBuildingForPlayer(playerid, 1294, 1477.5313, -1070.1406, 27.1797, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) 
	{
		if (IsPlayerInRangeOfPoint(playerid, 2.0, SAMD_INTERIOR_ENTER_COORDS)) { // Entrance
			SetPlayerFacingAngle(playerid, SAMD_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, SAMD_INTERIOR_EXIT_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_SAMDINTERIOR);
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
	// Map Icon
    CreateDynamicMapIcon(SAMD_INTERIOR_ENTER_COORDS, 22, 0, VW_MAIN, MAPS_SAMDINTERIOR_INTERIOR);

	// Pickups
	pickup_samdExterior[0] = CreateDynamicPickup(1239, 1, SAMD_STATEREPAIR_COORDS, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR); // Staterepair

	// 3DTextLabels
	text3D_samdExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_BLUE "Krankenhaus\n" COLOR_HEX_WHITE "Gebäude betreten mit 'Enter'", COLOR_WHITE, SAMD_INTERIOR_ENTER_COORDS, 20.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SAMDEXTERIOR_INTERIOR); // Entrance
	text3D_samdExterior[1] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, SAMD_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SAMDEXTERIOR_INTERIOR); // Staterepair

	// Vehicles

	// Objects
	object_samdExterior[0] = CreateDynamicObject(18981, 1459.5190, -1055.5102, 22.3278, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[0], 0, 17545, "burnsground", "indund_64", 0xFF9F9D94);
	object_samdExterior[1] = CreateDynamicObject(18981, 1459.5377, -1078.2406, 22.3078, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[1], 0, 4835, "airoads_las", "concretenewb256", 0xFF9F9D94);
	object_samdExterior[2] = CreateDynamicObject(18981, 1459.5384, -1078.4990, 22.3379, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[2], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
	object_samdExterior[3] = CreateDynamicObject(19464, 1432.1074, -1052.8159, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[3], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[4] = CreateDynamicObject(19464, 1440.8889, -1090.8851, 20.9727, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[4], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[5] = CreateDynamicObject(19464, 1446.8288, -1090.8851, 20.9727, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[5], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[6] = CreateDynamicObject(19464, 1432.1074, -1046.8863, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[6], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[7] = CreateDynamicObject(19464, 1432.1074, -1064.6942, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[7], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[8] = CreateDynamicObject(19464, 1432.1074, -1070.6357, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[8], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[9] = CreateDynamicObject(19464, 1432.1074, -1076.5748, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[9], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[10] = CreateDynamicObject(19464, 1432.1074, -1082.5144, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[10], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[11] = CreateDynamicObject(19464, 1432.0974, -1088.0240, 20.9428, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[11], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[12] = CreateDynamicObject(19464, 1432.1074, -1076.5748, 15.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[12], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[13] = CreateDynamicObject(19464, 1432.1074, -1082.5144, 15.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[13], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[14] = CreateDynamicObject(19464, 1432.0974, -1088.0240, 15.8528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[14], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[15] = CreateDynamicObject(19464, 1434.9477, -1090.8951, 20.9727, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[15], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[16] = CreateDynamicObject(19464, 1452.7684, -1090.8851, 20.9727, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[16], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[17] = CreateDynamicObject(19464, 1458.7075, -1090.8851, 20.9727, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[17], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[18] = CreateDynamicObject(19464, 1464.6477, -1090.8851, 20.9727, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[18], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[19] = CreateDynamicObject(19464, 1469.0300, -1090.8751, 20.9927, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[19], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[20] = CreateDynamicObject(19464, 1458.7075, -1090.8951, 15.9125, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[20], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[21] = CreateDynamicObject(19464, 1452.7674, -1090.8951, 15.9125, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[21], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[22] = CreateDynamicObject(19464, 1446.8264, -1090.8951, 15.9125, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[22], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[23] = CreateDynamicObject(19464, 1440.8857, -1090.8951, 15.9125, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[23], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[24] = CreateDynamicObject(19464, 1434.9554, -1090.8851, 15.9125, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[24], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[25] = CreateDynamicObject(18981, 1445.9576, -1077.4541, 15.3900, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[25], 0, 16640, "a51", "concretemanky", 0xFF515459);
	object_samdExterior[26] = CreateDynamicObject(18981, 1433.6555, -1078.4282, 10.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[26], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[27] = CreateDynamicObject(18981, 1446.4543, -1090.3974, 10.3079, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[27], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[28] = CreateDynamicObject(18981, 1459.5190, -1064.1700, 22.3080, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[28], 0, 4835, "airoads_las", "concretenewb256", 0xFF9F9D94);
	object_samdExterior[29] = CreateDynamicObject(18981, 1460.8454, -1090.3974, 10.3079, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[29], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[30] = CreateDynamicObject(18981, 1445.9576, -1055.6214, 18.8775, 0.0000, 73.9000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[30], 0, 16640, "a51", "concretemanky", 0xFF515459);
	object_samdExterior[31] = CreateDynamicObject(18981, 1433.6568, -1055.9886, 10.3177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[31], 0, 17545, "burnsground", "indund_64", 0xFF9F9D94);
	object_samdExterior[32] = CreateDynamicObject(18981, 1447.5168, -1055.9886, 10.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[32], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[33] = CreateDynamicObject(19464, 1442.8292, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[33], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[34] = CreateDynamicObject(19464, 1438.4393, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[34], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[35] = CreateDynamicObject(19464, 1447.7904, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[35], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[36] = CreateDynamicObject(19464, 1452.3000, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[36], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[37] = CreateDynamicObject(18981, 1460.8387, -1077.4541, 15.3872, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[37], 0, 16640, "a51", "concretemanky", 0xFF515459);
	object_samdExterior[38] = CreateDynamicObject(19464, 1456.4105, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[38], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[39] = CreateDynamicObject(19464, 1460.6317, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[39], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[40] = CreateDynamicObject(19464, 1469.0919, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[40], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[41] = CreateDynamicObject(19175, 1445.6861, -1065.9702, 21.1501, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[41], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[41], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[42] = CreateDynamicObject(18980, 1444.6462, -1066.4632, 21.9645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_samdExterior[42], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[43] = CreateDynamicObject(19175, 1440.2645, -1065.9603, 21.7803, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[43], 0, "Einfahrt", 90, "Arial", 60, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[43], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[44] = CreateDynamicObject(19175, 1442.9862, -1065.9702, 21.1501, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[44], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[44], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[45] = CreateDynamicObject(19175, 1435.4654, -1065.9702, 21.1501, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[45], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[45], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[46] = CreateDynamicObject(19175, 1438.1562, -1065.9702, 21.1501, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[46], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[46], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[47] = CreateDynamicObject(19175, 1438.1562, -1065.9702, 22.4603, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[47], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[47], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[48] = CreateDynamicObject(19175, 1435.4659, -1065.9702, 22.4603, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[48], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[48], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[49] = CreateDynamicObject(19175, 1445.6977, -1065.9702, 22.4603, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[49], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[49], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[50] = CreateDynamicObject(19175, 1442.9984, -1065.9702, 22.4603, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[50], 0, "______________________________________", 140, "Arial", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[50], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[51] = CreateDynamicObject(18980, 1446.5788, -1066.4730, 22.2945, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_samdExterior[51], 0, 4835, "airoads_las", "concretenewb256", 0xFF9F9D94);
	object_samdExterior[52] = CreateDynamicObject(18981, 1433.6654, -1055.9886, 10.2979, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[52], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[53] = CreateDynamicObject(18981, 1470.7978, -1053.0943, 11.9448, 0.0000, 73.9000, -90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[53], 0, 16640, "a51", "concretemanky", 0xFF515459);
	object_samdExterior[54] = CreateDynamicObject(18981, 1457.9687, -1055.9886, 10.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[54], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[55] = CreateDynamicObject(18981, 1473.8210, -1055.9886, 10.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[55], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[56] = CreateDynamicObject(19464, 1454.5383, -1068.3553, 15.1625, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[56], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[57] = CreateDynamicObject(19464, 1454.5383, -1068.3553, 20.2628, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[57], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[58] = CreateDynamicObject(19464, 1450.2082, -1068.3454, 15.1625, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[58], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[59] = CreateDynamicObject(19464, 1450.2082, -1068.3454, 20.2628, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[59], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[60] = CreateDynamicObject(19464, 1464.9128, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[60], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[61] = CreateDynamicObject(19464, 1473.1938, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[61], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[62] = CreateDynamicObject(19451, 1458.8752, -1081.3486, 14.1693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[62], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[63] = CreateDynamicObject(19451, 1468.5051, -1081.3483, 14.1688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[63], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[64] = CreateDynamicObject(19464, 1460.6313, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[64], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[65] = CreateDynamicObject(19464, 1464.9111, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[65], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[66] = CreateDynamicObject(19464, 1469.0916, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[66], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[67] = CreateDynamicObject(19464, 1434.2181, -1086.9195, 13.3563, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[67], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[68] = CreateDynamicObject(18981, 1473.8171, -1077.4499, 10.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[68], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[69] = CreateDynamicObject(19464, 1432.1074, -1058.7547, 20.9528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[69], 0, 4552, "ammu_lan2", "sl_lavicdtwall1", 0xFFFFFFFF);
	object_samdExterior[70] = CreateDynamicObject(19451, 1434.1059, -1078.9803, 14.1588, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[70], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[71] = CreateDynamicObject(19451, 1434.1059, -1062.6202, 15.5696, 16.0998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[71], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[72] = CreateDynamicObject(19451, 1434.1059, -1069.3431, 14.1588, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[72], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[73] = CreateDynamicObject(19451, 1434.1059, -1053.3586, 18.2430, 16.0998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[73], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[74] = CreateDynamicObject(19451, 1434.1059, -1048.0804, 19.7558, 16.0998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[74], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[75] = CreateDynamicObject(19451, 1447.0770, -1048.0804, 19.7558, 16.0998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[75], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[76] = CreateDynamicObject(19451, 1447.0770, -1057.3336, 17.0853, 16.0998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[76], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[77] = CreateDynamicObject(19451, 1447.0770, -1066.5860, 14.4146, 16.0998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[77], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[78] = CreateDynamicObject(19451, 1447.0771, -1063.6927, 14.1588, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[78], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[79] = CreateDynamicObject(19451, 1451.9774, -1068.4245, 14.1588, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[79], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[80] = CreateDynamicObject(19451, 1453.6678, -1068.4245, 14.1485, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[80], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[81] = CreateDynamicObject(19451, 1473.3690, -1078.9803, 14.1588, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[81], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[82] = CreateDynamicObject(19451, 1473.3790, -1069.7513, 14.1485, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[82], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[83] = CreateDynamicObject(19451, 1473.3806, -1060.7856, 12.8758, 16.0998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[83], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[84] = CreateDynamicObject(19451, 1473.3806, -1051.5255, 10.2025, 16.0998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[84], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[85] = CreateDynamicObject(19451, 1473.3806, -1042.2740, 7.5317, 16.0998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[85], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[86] = CreateDynamicObject(19451, 1458.3996, -1060.7856, 12.8758, 16.0998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[86], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[87] = CreateDynamicObject(19451, 1458.3966, -1066.6645, 11.0782, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[87], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[88] = CreateDynamicObject(19451, 1458.3996, -1051.5333, 10.2052, 16.0998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[88], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[89] = CreateDynamicObject(19451, 1458.3996, -1042.2812, 7.5345, 16.0998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[89], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[90] = CreateDynamicObject(19451, 1465.8564, -1053.3957, 7.5398, 73.8999, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[90], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[91] = CreateDynamicObject(19451, 1465.8564, -1061.3414, 9.8332, 73.8999, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[91], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[92] = CreateDynamicObject(19451, 1440.5782, -1062.1179, 12.5235, 73.8999, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[92], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[93] = CreateDynamicObject(19451, 1440.5782, -1053.5965, 14.9833, 73.8999, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[93], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[94] = CreateDynamicObject(19451, 1440.5782, -1044.2193, 17.6898, 73.8999, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[94], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[95] = CreateDynamicObject(19451, 1439.0157, -1043.4565, 21.1217, 0.0000, -16.7999, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[95], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[96] = CreateDynamicObject(19451, 1447.5931, -1043.4565, 21.1217, 0.0000, -16.7999, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[96], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[97] = CreateDynamicObject(18981, 1465.1274, -1036.0638, 10.5474, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[97], 0, 16640, "a51", "concretemanky", 0xFF515459);
	object_samdExterior[98] = CreateDynamicObject(18981, 1473.8210, -1030.9908, 10.1478, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[98], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[99] = CreateDynamicObject(19464, 1473.1938, -1028.4798, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[99], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[100] = CreateDynamicObject(19464, 1452.7237, -1028.4787, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[100], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[101] = CreateDynamicObject(19464, 1457.5649, -1028.4798, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[101], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[102] = CreateDynamicObject(19464, 1463.1958, -1028.4802, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[102], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[103] = CreateDynamicObject(19464, 1468.2054, -1028.4698, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[103], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[104] = CreateDynamicObject(18981, 1445.8177, -1043.9979, 9.0979, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[104], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[105] = CreateDynamicObject(18981, 1452.1268, -1030.9908, 10.1176, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[105], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[106] = CreateDynamicObject(18981, 1465.0354, -1023.0811, 10.3079, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[106], 0, 18065, "ab_sfammumain", "breezewall", 0xFFFFFFFF);
	object_samdExterior[107] = CreateDynamicObject(19451, 1468.5356, -1031.5323, 9.2987, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[107], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[108] = CreateDynamicObject(19451, 1458.9056, -1031.5323, 9.2987, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[108], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[109] = CreateDynamicObject(19451, 1449.2757, -1031.5328, 9.2987, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[109], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[110] = CreateDynamicObject(19464, 1473.1938, -1022.5399, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[110], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[111] = CreateDynamicObject(19464, 1468.2025, -1022.5399, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[111], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[112] = CreateDynamicObject(19464, 1463.1921, -1022.5399, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[112], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[113] = CreateDynamicObject(19464, 1457.5699, -1022.5399, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[113], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[114] = CreateDynamicObject(19464, 1452.7275, -1022.5399, 8.5064, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[114], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[115] = CreateDynamicObject(19451, 1473.3790, -1043.4919, 9.3086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[115], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[116] = CreateDynamicObject(19451, 1473.3790, -1036.4316, 9.2987, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[116], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[117] = CreateDynamicObject(19451, 1452.5589, -1036.4316, 9.2987, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[117], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[118] = CreateDynamicObject(19451, 1452.5593, -1043.4919, 9.3086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[118], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[119] = CreateDynamicObject(19451, 1453.6800, -1043.5520, 9.3086, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[119], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[120] = CreateDynamicObject(19451, 1458.3988, -1048.3031, 9.3086, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[120], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[121] = CreateDynamicObject(18981, 1446.6667, -1078.4708, 21.9577, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[121], 0, 13628, "8stad", "stadroof", 0xFFFFFFFF);
	object_samdExterior[122] = CreateDynamicObject(18981, 1460.9471, -1078.4708, 21.9479, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[122], 0, 13628, "8stad", "stadroof", 0xFFFFFFFF);
	object_samdExterior[123] = CreateDynamicObject(18981, 1460.9493, -1053.5876, 21.9078, -0.1999, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[123], 0, 13628, "8stad", "stadroof", 0xFFFFFFFF);
	object_samdExterior[124] = CreateDynamicObject(18981, 1461.2496, -1036.0179, 21.8379, -0.1999, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[124], 0, 13628, "8stad", "stadroof", 0xFFFFFFFF);
	object_samdExterior[125] = CreateDynamicObject(18075, 1473.3951, -1031.2646, 16.2108, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[126] = CreateDynamicObject(18075, 1473.3951, -1043.7551, 16.2108, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[127] = CreateDynamicObject(18075, 1473.3951, -1057.0057, 16.2108, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[128] = CreateDynamicObject(18075, 1473.3951, -1070.7154, 16.2108, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[129] = CreateDynamicObject(18075, 1473.3951, -1082.9858, 16.2108, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[130] = CreateDynamicObject(18075, 1452.5533, -1031.2646, 16.2108, 90.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[131] = CreateDynamicObject(18075, 1452.5852, -1043.7551, 16.2108, 90.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[132] = CreateDynamicObject(18075, 1458.3940, -1057.0057, 16.2108, 90.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[133] = CreateDynamicObject(18075, 1434.1258, -1070.7154, 16.2108, 90.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[134] = CreateDynamicObject(18075, 1434.0959, -1082.9858, 16.2108, 90.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lightD
	object_samdExterior[135] = CreateDynamicObject(18981, 1444.4881, -1078.4990, 22.3180, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[135], 0, 4835, "airoads_las", "concretenewb256", 0xFF9F9D94);
	object_samdExterior[136] = CreateDynamicObject(18981, 1444.4881, -1078.4990, 22.3379, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[136], 0, 10765, "airportgnd_sfse", "desgreengrass", 0xFFFFFFFF);
	object_samdExterior[137] = CreateDynamicObject(3934, 1461.5189, -1077.4039, 22.8362, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
	object_samdExterior[138] = CreateDynamicObject(3934, 1442.4781, -1077.4039, 22.8463, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
	object_samdExterior[139] = CreateDynamicObject(19449, 1464.5611, -1077.6638, 22.7502, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
	SetDynamicObjectMaterial(object_samdExterior[139], 0, 4726, "libhelipad_lan2", "helipad_basepanel", 0xFFFFFFFF);
	object_samdExterior[140] = CreateDynamicObject(19449, 1458.7904, -1077.6638, 22.7502, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
	SetDynamicObjectMaterial(object_samdExterior[140], 0, 4726, "libhelipad_lan2", "helipad_basepanel", 0xFFFFFFFF);
	object_samdExterior[141] = CreateDynamicObject(19449, 1461.7110, -1077.6638, 22.7602, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
	SetDynamicObjectMaterial(object_samdExterior[141], 0, 4726, "libhelipad_lan2", "helipad_basepanel", 0xFFFFFFFF);
	object_samdExterior[142] = CreateDynamicObject(19449, 1442.4897, -1077.6638, 22.7702, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
	SetDynamicObjectMaterial(object_samdExterior[142], 0, 4726, "libhelipad_lan2", "helipad_basepanel", 0xFFFFFFFF);
	object_samdExterior[143] = CreateDynamicObject(19449, 1445.4798, -1077.6638, 22.7602, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
	SetDynamicObjectMaterial(object_samdExterior[143], 0, 4726, "libhelipad_lan2", "helipad_basepanel", 0xFFFFFFFF);
	object_samdExterior[144] = CreateDynamicObject(19449, 1439.7690, -1077.6638, 22.7602, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall089
	SetDynamicObjectMaterial(object_samdExterior[144], 0, 4726, "libhelipad_lan2", "helipad_basepanel", 0xFFFFFFFF);
	object_samdExterior[145] = CreateDynamicObject(18980, 1444.6462, -1066.4632, 22.3047, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_samdExterior[145], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[146] = CreateDynamicObject(19430, 1445.4874, -1072.9392, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[146], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[147] = CreateDynamicObject(19430, 1439.7673, -1072.9289, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[147], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[148] = CreateDynamicObject(19430, 1443.2679, -1072.9289, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[148], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[149] = CreateDynamicObject(19430, 1464.5688, -1072.9289, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[149], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[150] = CreateDynamicObject(19430, 1461.0687, -1072.9289, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[150], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[151] = CreateDynamicObject(19430, 1458.7784, -1072.9392, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[151], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[152] = CreateDynamicObject(19430, 1443.2679, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[152], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[153] = CreateDynamicObject(19430, 1439.7677, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[153], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[154] = CreateDynamicObject(19430, 1446.7668, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[154], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[155] = CreateDynamicObject(19430, 1450.2674, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[155], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[156] = CreateDynamicObject(19430, 1453.7661, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[156], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[157] = CreateDynamicObject(19464, 1454.4895, -1073.6040, 22.7327, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[157], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[158] = CreateDynamicObject(19464, 1454.4895, -1079.5339, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[158], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[159] = CreateDynamicObject(19464, 1449.7790, -1073.6040, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[159], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[160] = CreateDynamicObject(19464, 1449.7790, -1079.5249, 22.7126, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[160], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[161] = CreateDynamicObject(19464, 1449.7790, -1068.9637, 22.7126, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[161], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[162] = CreateDynamicObject(19464, 1454.4792, -1068.9637, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[162], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[163] = CreateDynamicObject(19430, 1457.2657, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[163], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[164] = CreateDynamicObject(19430, 1460.7673, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[164], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[165] = CreateDynamicObject(19430, 1464.2677, -1082.3996, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[165], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[166] = CreateDynamicObject(19430, 1464.5577, -1082.3896, 22.2653, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[166], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[167] = CreateDynamicObject(19430, 1466.2198, -1074.5898, 22.2653, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[167], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[168] = CreateDynamicObject(19430, 1466.2198, -1080.7308, 22.2751, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[168], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[169] = CreateDynamicObject(19430, 1466.2099, -1077.5295, 22.2553, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[169], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[170] = CreateDynamicObject(19430, 1438.1168, -1077.5295, 22.2553, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[170], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[171] = CreateDynamicObject(19430, 1438.1101, -1074.5998, 22.2653, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[171], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[172] = CreateDynamicObject(19430, 1438.1074, -1080.7308, 22.2751, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[172], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[173] = CreateDynamicObject(661, 1467.7164, -1087.6323, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[174] = CreateDynamicObject(661, 1467.7164, -1078.7606, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[175] = CreateDynamicObject(661, 1467.7164, -1070.3402, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[176] = CreateDynamicObject(661, 1433.7060, -1087.7423, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[177] = CreateDynamicObject(661, 1433.7060, -1078.8403, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[178] = CreateDynamicObject(661, 1433.7060, -1070.7889, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[179] = CreateDynamicObject(817, 1464.0638, -1069.3967, 23.3038, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
	object_samdExterior[180] = CreateDynamicObject(817, 1460.1030, -1069.3967, 23.3038, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
	object_samdExterior[181] = CreateDynamicObject(817, 1439.6815, -1069.3967, 23.3038, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
	object_samdExterior[182] = CreateDynamicObject(817, 1444.0421, -1069.3967, 23.3038, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowers01
	object_samdExterior[183] = CreateDynamicObject(325, 1441.7761, -1069.0354, 22.8663, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flowera
	object_samdExterior[184] = CreateDynamicObject(325, 1462.0964, -1069.0354, 22.8663, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //flowera
	object_samdExterior[185] = CreateDynamicObject(869, 1463.8470, -1086.9619, 23.2357, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_samdExterior[186] = CreateDynamicObject(869, 1440.3037, -1086.9619, 23.2357, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_samdExterior[187] = CreateDynamicObject(661, 1450.6490, -1087.8221, 22.7621, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //pinetree07
	object_samdExterior[188] = CreateDynamicObject(869, 1447.3033, -1086.9619, 23.2357, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_samdExterior[189] = CreateDynamicObject(869, 1456.7469, -1086.9619, 23.2357, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
	object_samdExterior[190] = CreateDynamicObject(19954, 1455.2375, -1023.5623, 10.9448, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[190], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[191] = CreateDynamicObject(19954, 1460.5987, -1023.5623, 10.9448, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[191], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[192] = CreateDynamicObject(19954, 1465.8990, -1023.5623, 10.9448, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[192], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[193] = CreateDynamicObject(19954, 1470.7491, -1023.5623, 10.9448, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[193], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[194] = CreateDynamicObject(19175, 1460.6728, -1023.5858, 13.6667, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[194], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[194], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[195] = CreateDynamicObject(19175, 1465.9653, -1023.5858, 13.6667, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[195], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[195], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[196] = CreateDynamicObject(19175, 1455.3017, -1023.5858, 13.6667, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[196], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[196], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[197] = CreateDynamicObject(19175, 1470.8137, -1023.5858, 13.6667, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[197], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[197], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[198] = CreateDynamicObject(19175, 1465.9134, -1023.5759, 13.3268, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[198], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[198], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[199] = CreateDynamicObject(19175, 1470.7635, -1023.5759, 13.3268, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[199], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[199], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[200] = CreateDynamicObject(19175, 1460.6218, -1023.5759, 13.3268, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[200], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[200], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[201] = CreateDynamicObject(19175, 1455.2502, -1023.5759, 13.3268, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[201], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[201], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[202] = CreateDynamicObject(914, 1453.4039, -1023.5878, 20.5732, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GRILL
	object_samdExterior[203] = CreateDynamicObject(914, 1472.5759, -1023.5878, 20.5732, 0.0000, 90.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GRILL
	object_samdExterior[204] = CreateDynamicObject(914, 1472.5456, -1089.8873, 20.5732, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GRILL
	object_samdExterior[205] = CreateDynamicObject(914, 1434.9259, -1089.8873, 20.5732, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GRILL
	object_samdExterior[206] = CreateDynamicObject(19464, 1453.8051, -1085.6166, 13.3459, 0.0000, 0.0000, 31.1000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[206], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[207] = CreateDynamicObject(19464, 1454.8537, -1087.3535, 13.3464, 0.0000, 0.0000, 31.1000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[207], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[208] = CreateDynamicObject(19954, 1445.2053, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[208], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[208], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[209] = CreateDynamicObject(19954, 1449.9265, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[209], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[209], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[210] = CreateDynamicObject(19954, 1440.5947, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[210], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[210], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[211] = CreateDynamicObject(19954, 1436.2331, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[211], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[211], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[212] = CreateDynamicObject(19954, 1458.4637, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[212], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[212], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[213] = CreateDynamicObject(19954, 1462.7342, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[213], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[213], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[214] = CreateDynamicObject(19954, 1467.0146, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[214], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[214], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[215] = CreateDynamicObject(19954, 1471.1760, -1089.9039, 15.9448, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
	SetDynamicObjectMaterial(object_samdExterior[215], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[215], 2, 10765, "airportgnd_sfse", "white", 0xFF3B4E78);
	object_samdExterior[216] = CreateDynamicObject(19175, 1458.4022, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[216], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[216], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[217] = CreateDynamicObject(19175, 1462.6728, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[217], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[217], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[218] = CreateDynamicObject(19175, 1466.9438, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[218], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[218], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[219] = CreateDynamicObject(19175, 1471.1545, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[219], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[219], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[220] = CreateDynamicObject(19175, 1449.8657, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[220], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[220], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[221] = CreateDynamicObject(19175, 1445.1451, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[221], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[221], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[222] = CreateDynamicObject(19175, 1440.5434, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[222], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[222], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[223] = CreateDynamicObject(19175, 1436.1826, -1089.8940, 18.6769, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[223], 0, "P", 90, "Arial Black", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[223], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[224] = CreateDynamicObject(19175, 1467.0106, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[224], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[224], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[225] = CreateDynamicObject(19175, 1462.7298, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[225], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[225], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[226] = CreateDynamicObject(19175, 1471.1715, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[226], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[226], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[227] = CreateDynamicObject(19175, 1449.9116, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[227], 0, "Personal", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[227], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[228] = CreateDynamicObject(19175, 1440.5721, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[228], 0, "Personal", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[228], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[229] = CreateDynamicObject(19175, 1445.1820, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[229], 0, "Personal", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[229], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[230] = CreateDynamicObject(19175, 1436.2220, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[230], 0, "Personal", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[230], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[231] = CreateDynamicObject(19451, 1449.3273, -1081.3483, 14.1688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[231], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[232] = CreateDynamicObject(19175, 1437.1861, -1045.0144, 22.4472, -106.1998, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[232], 0, "EINFAHRT", 90, "Arial", 60, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[232], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[233] = CreateDynamicObject(19985, 1444.2292, -1065.9093, 19.4729, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign38
	SetDynamicObjectMaterial(object_samdExterior[233], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[234] = CreateDynamicObject(19985, 1436.5284, -1065.9093, 19.4729, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign38
	SetDynamicObjectMaterial(object_samdExterior[234], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[235] = CreateDynamicObject(19430, 1457.0985, -1071.2878, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[235], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[236] = CreateDynamicObject(19430, 1457.0985, -1067.7877, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[236], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[237] = CreateDynamicObject(19430, 1447.2170, -1067.7877, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[237], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[238] = CreateDynamicObject(19430, 1447.2170, -1071.2884, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[238], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[239] = CreateDynamicObject(19175, 1443.9560, -1045.0144, 22.4472, -73.5998, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[239], 0, "S T O P", 90, "Arial", 80, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[239], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[240] = CreateDynamicObject(19464, 1449.7790, -1063.0340, 22.7126, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[240], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[241] = CreateDynamicObject(19464, 1449.7790, -1057.1041, 22.7126, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[241], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[242] = CreateDynamicObject(19464, 1449.7790, -1051.1645, 22.7126, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[242], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[243] = CreateDynamicObject(19464, 1449.7790, -1046.9045, 22.7026, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[243], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[244] = CreateDynamicObject(19464, 1454.4792, -1063.0339, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[244], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[245] = CreateDynamicObject(19464, 1454.4792, -1057.1040, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[245], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[246] = CreateDynamicObject(19464, 1454.4792, -1051.1739, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[246], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[247] = CreateDynamicObject(19464, 1454.4792, -1046.9034, 22.7327, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[247], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[248] = CreateDynamicObject(19464, 1459.5793, -1063.0339, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[248], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[249] = CreateDynamicObject(19464, 1464.6793, -1063.0339, 22.7227, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[249], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[250] = CreateDynamicObject(19464, 1469.4593, -1063.0339, 22.7126, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[250], 0, 3967, "cj_airprt", "bigbrick", 0xFFFFFFFF);
	object_samdExterior[251] = CreateDynamicObject(19430, 1447.2170, -1064.2878, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[251], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[252] = CreateDynamicObject(19430, 1447.2170, -1060.7867, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[252], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[253] = CreateDynamicObject(19430, 1447.2170, -1057.2867, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[253], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[254] = CreateDynamicObject(19430, 1447.2170, -1053.7867, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[254], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[255] = CreateDynamicObject(19430, 1447.2170, -1050.2873, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[255], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[256] = CreateDynamicObject(19430, 1447.2170, -1046.7872, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[256], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[257] = CreateDynamicObject(19430, 1447.2071, -1045.6468, 22.2751, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[257], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[258] = CreateDynamicObject(19430, 1457.0985, -1058.2873, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[258], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[259] = CreateDynamicObject(19430, 1457.0985, -1054.7871, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[259], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[260] = CreateDynamicObject(19430, 1457.0985, -1051.2867, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[260], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[261] = CreateDynamicObject(19430, 1457.0985, -1047.7867, 22.2852, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[261], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[262] = CreateDynamicObject(19430, 1457.1185, -1045.6767, 22.2751, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[262], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[263] = CreateDynamicObject(19430, 1458.7584, -1066.0775, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[263], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[264] = CreateDynamicObject(19430, 1462.2585, -1066.0775, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[264], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[265] = CreateDynamicObject(19430, 1465.7585, -1066.0775, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[265], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[266] = CreateDynamicObject(19430, 1469.2589, -1066.0775, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[266], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[267] = CreateDynamicObject(19430, 1470.2689, -1066.0875, 22.2651, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[267], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[268] = CreateDynamicObject(19430, 1470.2689, -1060.0769, 22.2651, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[268], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[269] = CreateDynamicObject(19430, 1466.7685, -1060.0869, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[269], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[270] = CreateDynamicObject(19430, 1463.2679, -1060.0869, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[270], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[271] = CreateDynamicObject(19430, 1459.7674, -1060.0869, 22.2751, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[271], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[272] = CreateDynamicObject(19430, 1458.7574, -1060.0969, 22.2852, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[272], 0, 12944, "ce_bankalley2", "sw_brick04", 0xFFFFFFFF);
	object_samdExterior[273] = CreateDynamicObject(19464, 1464.8785, -1049.0085, 24.0757, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[273], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[274] = CreateDynamicObject(19464, 1463.5493, -1050.5887, 24.0757, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[274], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[275] = CreateDynamicObject(19464, 1467.7396, -1050.5887, 24.0757, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[275], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[276] = CreateDynamicObject(1522, 1464.1308, -1048.9442, 23.3409, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	SetDynamicObjectMaterial(object_samdExterior[276], 0, 10763, "airport1_sfse", "ws_airportdoors1", 0xFFFFFFFF);
	object_samdExterior[277] = CreateDynamicObject(1522, 1465.6307, -1048.9442, 23.3309, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gen_doorSHOP3
	SetDynamicObjectMaterial(object_samdExterior[277], 0, 10763, "airport1_sfse", "ws_airportdoors1", 0xFFFFFFFF);
	object_samdExterior[278] = CreateDynamicObject(14416, 1465.5930, -1048.2501, 21.0881, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs07
	SetDynamicObjectMaterial(object_samdExterior[278], 0, 3900, "station", "stairstep01_64", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[278], 1, 3900, "station", "stairstep01_64", 0xFFFFFFFF);
	object_samdExterior[279] = CreateDynamicObject(19432, 1462.8625, -1047.7093, 24.4939, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall072
	SetDynamicObjectMaterial(object_samdExterior[279], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[280] = CreateDynamicObject(19432, 1462.8625, -1047.6993, 24.8838, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall072
	SetDynamicObjectMaterial(object_samdExterior[280], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[281] = CreateDynamicObject(19432, 1461.2530, -1047.7196, 23.1639, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall072
	SetDynamicObjectMaterial(object_samdExterior[281], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
	object_samdExterior[282] = CreateDynamicObject(19432, 1461.2530, -1047.7093, 24.8738, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall072
	SetDynamicObjectMaterial(object_samdExterior[282], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
	object_samdExterior[283] = CreateDynamicObject(19432, 1459.6529, -1047.7093, 24.8738, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall072
	SetDynamicObjectMaterial(object_samdExterior[283], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
	object_samdExterior[284] = CreateDynamicObject(19432, 1459.6529, -1047.7196, 24.4738, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall072
	SetDynamicObjectMaterial(object_samdExterior[284], 0, 12855, "cunte_cop", "sw_brick05", 0xFFFFFFFF);
	object_samdExterior[285] = CreateDynamicObject(19387, 1467.8636, -1046.9132, 24.4256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
	SetDynamicObjectMaterial(object_samdExterior[285], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[285], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[286] = CreateDynamicObject(19464, 1465.0089, -1047.8586, 26.2259, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[286], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[287] = CreateDynamicObject(19387, 1462.1335, -1046.9132, 24.4256, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall035
	SetDynamicObjectMaterial(object_samdExterior[287], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[287], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[288] = CreateDynamicObject(18762, 1463.5423, -1045.8487, 27.0645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[288], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[289] = CreateDynamicObject(18762, 1465.4525, -1045.8586, 27.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[289], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[290] = CreateDynamicObject(18762, 1463.5427, -1045.8487, 28.0645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[290], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[291] = CreateDynamicObject(18762, 1465.4525, -1045.8586, 28.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[291], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[292] = CreateDynamicObject(19464, 1464.4582, -1047.8686, 30.1359, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[292], 0, 9575, "archbrij", "conc_wall_stripd2128h", 0xFF46597A);
	object_samdExterior[293] = CreateDynamicObject(19175, 1459.3989, -1047.6053, 24.9442, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[293], 0, "Call", 90, "Arial Black", 60, 1, 0xFF840410, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[293], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[294] = CreateDynamicObject(19175, 1459.3687, -1047.6153, 24.4041, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[294], 0, "112", 90, "Arial Black", 60, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[294], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[295] = CreateDynamicObject(19175, 1458.4604, -1089.8874, 18.3469, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[295], 0, "Fraktion", 90, "Arial", 20, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[295], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[296] = CreateDynamicObject(19175, 1462.3781, -1045.3542, 27.1340, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[296], 0, "Department", 90, "Arial Black", 50, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[296], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[297] = CreateDynamicObject(19450, 1469.6036, -1047.7447, 26.5459, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[297], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[298] = CreateDynamicObject(19450, 1459.7839, -1047.7447, 26.8659, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[298], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[299] = CreateDynamicObject(19464, 1467.7395, -1050.5688, 28.9659, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[299], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[300] = CreateDynamicObject(18762, 1469.3728, -1045.8586, 31.7345, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[300], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[301] = CreateDynamicObject(19436, 1465.2312, -1047.7585, 30.0631, 90.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall076
	SetDynamicObjectMaterial(object_samdExterior[301], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0xFFFFFFFF);
	object_samdExterior[302] = CreateDynamicObject(19450, 1471.2834, -1049.4453, 26.5459, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[302], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[303] = CreateDynamicObject(19450, 1458.1134, -1049.4453, 26.5459, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[303], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[304] = CreateDynamicObject(19464, 1464.4582, -1047.8386, 28.8159, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[304], 0, 9575, "archbrij", "conc_wall_stripd2128h", 0xFF46597A);
	object_samdExterior[305] = CreateDynamicObject(19464, 1468.3277, -1047.8785, 30.1359, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[305], 0, 9575, "archbrij", "conc_wall_stripd2128h", 0xFF46597A);
	object_samdExterior[306] = CreateDynamicObject(19464, 1461.0373, -1047.8785, 30.1359, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[306], 0, 9575, "archbrij", "conc_wall_stripd2128h", 0xFF46597A);
	object_samdExterior[307] = CreateDynamicObject(19464, 1465.9985, -1047.7983, 28.8159, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[307], 0, 10765, "airportgnd_sfse", "white", 0xFF20202C);
	object_samdExterior[308] = CreateDynamicObject(18762, 1469.3728, -1045.8586, 32.7345, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[308], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[309] = CreateDynamicObject(19175, 1469.4090, -1045.3441, 32.4342, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[309], 0, "+", 90, "Arial Black", 150, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[309], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[310] = CreateDynamicObject(18762, 1471.4332, -1047.8885, 32.7644, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[310], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[311] = CreateDynamicObject(19175, 1469.4388, -1045.3238, 32.4640, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[311], 0, "+", 90, "Arial Black", 150, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[311], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[312] = CreateDynamicObject(18762, 1471.4332, -1047.8785, 31.7644, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[312], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[313] = CreateDynamicObject(18762, 1469.3728, -1046.8586, 31.7345, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[313], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[314] = CreateDynamicObject(18762, 1469.3728, -1047.8581, 31.7345, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[314], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[315] = CreateDynamicObject(18762, 1469.3728, -1046.8585, 32.7345, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[315], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[316] = CreateDynamicObject(18762, 1469.3728, -1047.8581, 32.7345, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[316], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[317] = CreateDynamicObject(18762, 1463.5423, -1046.8391, 27.0645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[317], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[318] = CreateDynamicObject(18762, 1463.5423, -1047.8393, 27.0645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[318], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[319] = CreateDynamicObject(18762, 1463.5427, -1046.8487, 28.0645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[319], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[320] = CreateDynamicObject(18762, 1463.5427, -1047.8485, 28.0645, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[320], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[321] = CreateDynamicObject(18762, 1465.4525, -1046.8586, 28.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[321], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[322] = CreateDynamicObject(18762, 1465.4525, -1047.8585, 28.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[322], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[323] = CreateDynamicObject(18762, 1465.4322, -1046.8591, 27.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[323], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[324] = CreateDynamicObject(18762, 1465.4322, -1047.8590, 27.0545, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[324], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[325] = CreateDynamicObject(19450, 1458.1439, -1052.9355, 27.1860, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[325], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[326] = CreateDynamicObject(18762, 1471.4132, -1052.1483, 31.7644, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[326], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[327] = CreateDynamicObject(18762, 1471.4132, -1052.1483, 32.7644, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[327], 0, 14707, "labig3int2", "bathtile02_int", 0xFF722A3F);
	object_samdExterior[328] = CreateDynamicObject(19450, 1471.2834, -1052.9355, 26.5459, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[328], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[329] = CreateDynamicObject(19450, 1471.2950, -1056.4156, 26.9260, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[329], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[330] = CreateDynamicObject(19450, 1458.1239, -1056.4156, 26.5459, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[330], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[331] = CreateDynamicObject(19450, 1458.1234, -1049.4453, 27.1860, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[331], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[332] = CreateDynamicObject(19450, 1466.1333, -1058.0959, 26.9260, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[332], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[333] = CreateDynamicObject(19450, 1462.6428, -1058.0959, 26.9360, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[333], 0, 3979, "civic01_lan", "sl_concretewall1", 0xFFFFFFFF);
	object_samdExterior[334] = CreateDynamicObject(19450, 1469.6335, -1058.0959, 26.9360, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[334], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[335] = CreateDynamicObject(19450, 1459.7923, -1058.0860, 26.9360, 90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[335], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[336] = CreateDynamicObject(19450, 1458.1339, -1056.4156, 27.1760, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall090
	SetDynamicObjectMaterial(object_samdExterior[336], 0, 3629, "arprtxxref_las", "grn_window2_16", 0xFFFFFFFF);
	object_samdExterior[337] = CreateDynamicObject(18766, 1461.2998, -1047.6877, 32.2374, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[337], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[338] = CreateDynamicObject(18766, 1461.2998, -1052.6876, 32.2374, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[338], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[339] = CreateDynamicObject(18766, 1463.9906, -1047.6678, 32.2472, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[339], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[340] = CreateDynamicObject(18766, 1461.2998, -1055.7170, 32.2374, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[340], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[341] = CreateDynamicObject(18766, 1467.1595, -1055.7170, 32.2374, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[341], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[342] = CreateDynamicObject(18766, 1466.1794, -1050.7170, 32.2374, 90.0000, 90.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
	SetDynamicObjectMaterial(object_samdExterior[342], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[343] = CreateDynamicObject(1231, 1451.8441, -1049.0987, 24.0697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	object_samdExterior[344] = CreateDynamicObject(1231, 1451.8441, -1060.0190, 24.0697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	object_samdExterior[345] = CreateDynamicObject(1231, 1451.8441, -1065.9392, 24.0697, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	object_samdExterior[346] = CreateDynamicObject(1231, 1451.8441, -1082.1096, 24.2098, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	object_samdExterior[347] = CreateDynamicObject(1231, 1464.2043, -1060.2794, 24.2198, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	object_samdExterior[348] = CreateDynamicObject(1231, 1464.2043, -1065.9095, 24.1898, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
	object_samdExterior[349] = CreateDynamicObject(1649, 1467.7823, -1048.0487, 24.3756, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(object_samdExterior[349], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdExterior[350] = CreateDynamicObject(1649, 1467.9425, -1048.0487, 24.3756, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(object_samdExterior[350], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdExterior[351] = CreateDynamicObject(1649, 1462.0517, -1048.0487, 24.3756, 0.0000, 0.0000, 270.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(object_samdExterior[351], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdExterior[352] = CreateDynamicObject(1649, 1462.2016, -1048.0487, 24.3756, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wglasssmash
	SetDynamicObjectMaterial(object_samdExterior[352], 0, 18065, "ab_sfammumain", "shelf_glas", 0xFFFFFFFF);
	object_samdExterior[353] = CreateDynamicObject(18981, 1432.6761, -1055.9886, 10.3079, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[353], 0, 17545, "burnsground", "indund_64", 0xFF9F9D94);
	object_samdExterior[354] = CreateDynamicObject(19175, 1461.5372, -1045.3542, 27.4741, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[354], 0, "Medical", 90, "Arial Black", 50, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[354], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[355] = CreateDynamicObject(19175, 1462.4793, -1045.3542, 27.8141, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[355], 0, "San Andreas", 90, "Arial Black", 50, 1, 0xFFFFFFFF, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[355], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[356] = CreateDynamicObject(19175, 1459.3587, -1047.6152, 24.9542, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[356], 0, "Call", 90, "Arial Black", 60, 1, 0xFF000000, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[356], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[357] = CreateDynamicObject(19175, 1459.3989, -1047.6053, 24.3840, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[357], 0, "112", 90, "Arial Black", 60, 1, 0xFF840410, 0x0, 0);
	SetDynamicObjectMaterial(object_samdExterior[357], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[358] = CreateDynamicObject(19451, 1439.8447, -1081.3486, 14.1693, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[358], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[359] = CreateDynamicObject(19451, 1438.8770, -1081.3483, 14.1688, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall091
	SetDynamicObjectMaterial(object_samdExterior[359], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[360] = CreateDynamicObject(19464, 1473.1929, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[360], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[361] = CreateDynamicObject(19464, 1456.4117, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[361], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[362] = CreateDynamicObject(19464, 1452.3013, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[362], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[363] = CreateDynamicObject(19464, 1447.7901, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[363], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[364] = CreateDynamicObject(19464, 1442.8281, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[364], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[365] = CreateDynamicObject(19464, 1438.4368, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[365], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[366] = CreateDynamicObject(19464, 1434.2164, -1084.3480, 13.3566, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[366], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[367] = CreateDynamicObject(19464, 1453.8287, -1087.3883, 13.3464, 0.0000, 0.0000, -31.1000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[367], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[368] = CreateDynamicObject(19464, 1454.8669, -1085.6677, 13.3468, 0.0000, 0.0000, -31.1000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
	SetDynamicObjectMaterial(object_samdExterior[368], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[369] = CreateDynamicObject(19175, 1454.3802, -1082.3280, 15.8768, -90.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[369], 0, "KFZ-Reparatur", 90, "Arial", 42, 1, 0xFFFFFFFF, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[369], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[370] = CreateDynamicObject(19430, 1455.4888, -1083.1500, 14.1615, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[370], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[371] = CreateDynamicObject(19430, 1453.1872, -1083.1500, 14.1615, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[371], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[372] = CreateDynamicObject(19430, 1454.2078, -1083.1479, 14.1619, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall070
	SetDynamicObjectMaterial(object_samdExterior[372], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[373] = CreateDynamicObject(19175, 1454.3802, -1089.8768, 18.1868, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
	SetDynamicObjectMaterialText(object_samdExterior[373], 0, "KFZ-Reparatur", 90, "Arial", 42, 1, 0xFF000000, 0x0, 1);
	SetDynamicObjectMaterial(object_samdExterior[373], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[374] = CreateDynamicObject(18980, 1446.5676, -1066.4670, 9.2044, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_samdExterior[374], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	object_samdExterior[375] = CreateDynamicObject(18980, 1434.6473, -1066.4670, 9.2044, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
	SetDynamicObjectMaterial(object_samdExterior[375], 0, 10765, "airportgnd_sfse", "white", 0xFFFFFFFF);
	
	// Garage door
	object_samdExterior[376] = CreateDynamicObject(2885, 1440.6060, -1066.2077, 21.7887, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //xref_garagedoor
	SetDynamicObjectMaterial(object_samdExterior[376], 0, 9524, "blokmodb", "sf_garagedr1", 0xFFFFFFFF);
	SetDynamicObjectMaterial(object_samdExterior[376], 1, 9524, "blokmodb", "sf_garagedr1", 0xFFFFFFFF);

	// Solid ground
	object_samdExterior[377] = CreateDynamicObject(18981, 1446.4970, -1078.4708, 15.3776, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[377], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[378] = CreateDynamicObject(18981, 1452.6878, -1078.4708, 22.3476, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[378], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[379] = CreateDynamicObject(18981, 1461.3382, -1078.4708, 15.3775, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[379], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
	object_samdExterior[380] = CreateDynamicObject(18981, 1461.3382, -1034.4807, 10.5275, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
	SetDynamicObjectMaterial(object_samdExterior[380], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);

	object_samdExterior_garageDoor = object_samdExterior[376];
}
