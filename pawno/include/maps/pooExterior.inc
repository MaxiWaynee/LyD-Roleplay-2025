#include <YSI\y_hooks>

// Global interior define
#define MAPS_POOEXTERIOR_INTERIOR      0
#define MAPS_POOINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
//static Float:STREAMDISTANCE = 200.0;
//static Float:DRAWDISTANCE   = 180.0;

// POO points
#define POO_INTERIOR_ENTER_COORDS		901.4260,-1257.4941,15.9038
#define POO_INTERIOR_EXIT_COORDS		1932.5820, -2002.2120, 823.4130
#define POO_INTERIOR_ENTER_FACING		181.8887
#define POO_INTERIOR_EXIT_FACING   	    239.3597
#define POO_STATEREPAIR_COORDS			853.44, -1276.70, 16.24

#define POO_INTERIOR_ROOF_POINT         1945.6727, -2025.2015, 823.4130
#define POO_INTERIOR_ROOF_POINT_FACING  180.0000
#define POO_ROOF_POINT                  919.4372,-1250.5099,20.5875
#define POO_ROOF_POINT_FACING           84.9632

#define POO_BARRIER_FOR_RANGE_COORDS    1982.4076, -1330.9158, 24.0087
#define POO_BARRIER_OPEN_RY             0.0000
#define POO_BARRIER_CLOSED_RY           -90.0000

// Map variables
//new object_pooExterior[195];
new pickup_pooExterior[3];
new text3D_pooExterior[1];
new object_pooExterior_barrier;

CMD:ogate(playerid, params[]) {
    if (!(Spieler[playerid][pFraktion] == 1 || Spieler[playerid][pFraktion] == 2 || Spieler[playerid][pFraktion] == 3 || Spieler[playerid][pFraktion] == 5 || Spieler[playerid][pFraktion] == 9 || Spieler[playerid][pFraktion] == 18))
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");

    if (IsPlayerInRangeOfPoint(playerid, 10.0, POO_BARRIER_FOR_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ, Float:fRX, Float:fRY, Float:fRZ;
        GetDynamicObjectPos(object_pooExterior_barrier, fX, fY, fZ);
        GetDynamicObjectRot(object_pooExterior_barrier, fRX, fRY, fRZ);

        if (fRY == POO_BARRIER_OPEN_RY)
            MoveDynamicObject(object_pooExterior_barrier, fX, fY, fZ + 0.0001, 0.0002, fRX, POO_BARRIER_CLOSED_RY, fRZ);
        else
            MoveDynamicObject(object_pooExterior_barrier, fX, fY, fZ - 0.0001, 0.0002, fRX, POO_BARRIER_OPEN_RY, fRZ);

        return 1;
    }
    
    return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe der Schranke.");
}

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
	/*
    RemoveBuildingForPlayer(playerid, 5636, 2042.1800, -1346.8000, 24.0077, 0.10); // LAEalpha4
    RemoveBuildingForPlayer(playerid, 5461, 2011.4699, -1300.9000, 28.6952, 0.10); // laeGlenPark05
    RemoveBuildingForPlayer(playerid, 5597, 2011.4699, -1300.9000, 28.6952, 0.10); // LOD Model of laeGlenPark05
    RemoveBuildingForPlayer(playerid, 5631, 2011.4100, -1302.9499, 28.2733, 0.10); // apartmntalpha
    RemoveBuildingForPlayer(playerid, 5465, 1993.3000, -1284.9399, 26.7343, 0.10); // laeGlenPark05Nt
    RemoveBuildingForPlayer(playerid, 1308, 2008.6300, -1271.3100, 23.1641, 0.10); // telgrphpole02
	*/
	
	RemoveBuildingForPlayer(playerid, 3777, 831.9609, -1191.1406, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 3777, 868.1328, -1191.1406, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 5926, 816.3359, -1217.1484, 26.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 5978, 887.9844, -1287.1328, 18.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 5979, 918.8828, -1293.4609, 14.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 5980, 917.7188, -1259.5234, 16.1875, 0.25);
	RemoveBuildingForPlayer(playerid, 3777, 902.3359, -1191.1406, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 6005, 895.2578, -1256.9297, 31.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 5836, 816.3359, -1217.1484, 26.4453, 0.25);
	RemoveBuildingForPlayer(playerid, 3776, 831.9609, -1191.1406, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 5706, 887.9844, -1287.1328, 18.2656, 0.25);
	RemoveBuildingForPlayer(playerid, 5735, 918.8828, -1293.4609, 14.9297, 0.25);
	RemoveBuildingForPlayer(playerid, 3776, 868.1328, -1191.1406, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 5838, 895.2578, -1256.9297, 31.2344, 0.25);
	RemoveBuildingForPlayer(playerid, 3776, 902.3359, -1191.1406, 25.0391, 0.25);
	RemoveBuildingForPlayer(playerid, 5736, 917.7188, -1259.5234, 16.1875, 0.25);

}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, POO_INTERIOR_ENTER_COORDS)) { // Entrance
			SetPlayerFacingAngle(playerid, POO_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, POO_INTERIOR_EXIT_COORDS, MAPS_POOINTERIOR_INTERIOR, VW_POOINTERIOR);
			return 1;
		} else if (IsPlayerInRangeOfPoint(playerid, 2.0, POO_ROOF_POINT)) { // Roof Entrance
            SetPlayerFacingAngle(playerid, POO_INTERIOR_ROOF_POINT_FACING);
            SetCameraBehindPlayer(playerid);
            SetPlayerPosEx(playerid, POO_INTERIOR_ROOF_POINT, MAPS_POOINTERIOR_INTERIOR, VW_POOINTERIOR);
            return 1;
        }
	}

	return 1;
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(POO_INTERIOR_ENTER_COORDS, 11, 0, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR);
    
	// Pickups
	pickup_pooExterior[0] = CreateDynamicPickup(19197, 1, POO_INTERIOR_ENTER_COORDS, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Entrance
    pickup_pooExterior[1] = CreateDynamicPickup(1239, 1, POO_STATEREPAIR_COORDS, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Staterepair
    pickup_pooExterior[2] = CreateDynamicPickup(19197, 1, POO_ROOF_POINT, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR); // Roof Entrance

    // 3DTextLabels
    text3D_pooExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, POO_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_POOEXTERIOR_INTERIOR); // Staterepair

    // Vehicles
/*
	// Objects
	object_pooExterior[0] = CreateDynamicObject(19538, 2028.5295, -1300.8879, 22.7416, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //Plane62_5x125Conc1
    object_pooExterior[1] = CreateDynamicObject(18981, 1974.6335, -1281.1074, 11.6372, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[1], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[2] = CreateDynamicObject(19543, 2053.4216, -1301.0262, 22.9780, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Plane62_5x15Grass1
    object_pooExterior[3] = CreateDynamicObject(8661, 2026.0146, -1280.8653, 22.9829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_pooExterior[3], 0, 4835, "airoads_las", "concretenewb256", 0xFF696969);
    object_pooExterior[4] = CreateDynamicObject(8661, 2026.0146, -1300.8454, 22.9824, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_pooExterior[4], 0, 4835, "airoads_las", "concretenewb256", 0xFF696969);
    object_pooExterior[5] = CreateDynamicObject(8661, 1986.0155, -1280.8653, 22.9829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_pooExterior[5], 0, 4835, "airoads_las", "concretenewb256", 0xFF696969);
    object_pooExterior[6] = CreateDynamicObject(19172, 2044.5006, -1301.2252, 24.1422, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[6], 0, "platz", OBJECT_MATERIAL_SIZE_256x128, "Courier New", 70, 1, 0xFFFFA500, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[6], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[7] = CreateDynamicObject(8661, 2026.0146, -1320.8260, 22.9829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_pooExterior[7], 0, 4835, "airoads_las", "concretenewb256", 0xFF696969);
    object_pooExterior[8] = CreateDynamicObject(1569, 1975.9023, -1303.1728, 22.8927, 0.0000, 0.0000, 45.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    SetDynamicObjectMaterial(object_pooExterior[8], 0, 11008, "firehouse_sfse", "halldoor01_law", 0xFFFFFFFF);
    object_pooExterior[9] = CreateDynamicObject(19464, 1975.9139, -1281.7302, 25.5193, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[9], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[10] = CreateDynamicObject(18981, 1966.5179, -1294.1274, 15.3374, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[10], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[11] = CreateDynamicObject(18981, 1966.5172, -1318.3968, 13.8464, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[11], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[12] = CreateDynamicObject(19464, 1969.9774, -1281.7302, 25.5193, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[12], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[13] = CreateDynamicObject(19464, 1978.7596, -1284.5814, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[13], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[14] = CreateDynamicObject(19354, 1979.1853, -1296.6649, 25.5447, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[14], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[15] = CreateDynamicObject(10183, 1992.3850, -1275.6781, 22.9892, -0.1500, 0.1500, 225.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_pooExterior[16] = CreateDynamicObject(18981, 2001.9133, -1281.1074, 11.6372, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[16], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[17] = CreateDynamicObject(19464, 1977.6290, -1290.5168, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[17], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[18] = CreateDynamicObject(19464, 1967.1279, -1284.5814, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[18], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[19] = CreateDynamicObject(19464, 1967.1279, -1290.5179, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[19], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[20] = CreateDynamicObject(19464, 1967.1279, -1296.4554, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[20], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[21] = CreateDynamicObject(19464, 1969.9774, -1305.2309, 25.5193, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[21], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[22] = CreateDynamicObject(19464, 1976.2884, -1299.5278, 25.5209, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[22], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[23] = CreateDynamicObject(19464, 1972.8288, -1302.3811, 25.5191, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[23], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[24] = CreateDynamicObject(19464, 1979.1300, -1296.6733, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[24], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[25] = CreateDynamicObject(19464, 1976.2790, -1293.5771, 25.5209, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[25], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[26] = CreateDynamicObject(18981, 2046.1053, -1308.3750, 11.6372, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[26], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[27] = CreateDynamicObject(18766, 2019.2197, -1330.4372, 21.6340, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[27], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[28] = CreateDynamicObject(19464, 1971.3984, -1304.6622, 25.5181, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[28], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[29] = CreateDynamicObject(19464, 1978.4294, -1297.6097, 25.5181, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[29], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[30] = CreateDynamicObject(18981, 2046.1097, -1318.4471, 11.6350, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[30], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[31] = CreateDynamicObject(19464, 1976.3702, -1302.5842, 25.5172, 0.0000, 0.0000, -45.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[31], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[32] = CreateDynamicObject(10183, 1987.3393, -1275.6457, 22.9902, -0.1500, 0.1500, 225.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ferspaces
    object_pooExterior[33] = CreateDynamicObject(18981, 2013.9371, -1283.3780, 11.6385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[33], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[34] = CreateDynamicObject(19464, 2027.1711, -1330.8031, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[34], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[35] = CreateDynamicObject(18766, 2019.2197, -1271.3841, 21.6340, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[35], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[36] = CreateDynamicObject(18766, 2040.6510, -1271.3819, 21.6340, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[36], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[37] = CreateDynamicObject(19464, 1964.0417, -1281.7302, 25.5193, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[37], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[38] = CreateDynamicObject(19464, 1971.6468, -1302.3431, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[38], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[39] = CreateDynamicObject(18981, 2046.1053, -1283.3752, 11.6372, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[39], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[40] = CreateDynamicObject(18766, 2040.6190, -1330.4420, 21.6340, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[40], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[41] = CreateDynamicObject(18981, 2000.9482, -1330.4388, 11.6372, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[41], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[42] = CreateDynamicObject(1215, 2024.5257, -1330.5621, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[43] = CreateDynamicObject(1569, 1969.2656, -1299.3974, 28.0764, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //ADAM_V_DOOR
    SetDynamicObjectMaterial(object_pooExterior[43], 0, 10023, "bigwhitesfe", "liftdoors_kb_256", 0x00000000);
    object_pooExterior[44] = CreateDynamicObject(3854, 1969.6340, -1282.9261, 22.0622, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //GAY_telgrphpole
    object_pooExterior[45] = CreateDynamicObject(1215, 2035.2965, -1330.5621, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[46] = CreateDynamicObject(1215, 2013.9559, -1299.9925, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[47] = CreateDynamicObject(19464, 1975.9090, -1287.4360, 25.5209, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[47], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[48] = CreateDynamicObject(19464, 2006.7536, -1281.7147, 20.4500, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[48], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[49] = CreateDynamicObject(1215, 2013.9559, -1296.9101, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[50] = CreateDynamicObject(19464, 1984.5920, -1315.1584, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[50], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[51] = CreateDynamicObject(8661, 1986.0155, -1300.8447, 22.9824, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_pooExterior[51], 0, 4835, "airoads_las", "concretenewb256", 0xFF696969);
    object_pooExterior[52] = CreateDynamicObject(1372, 1978.3542, -1291.7486, 23.1068, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_Dump2_LOW
    object_pooExterior[53] = CreateDynamicObject(1339, 1978.3441, -1289.0174, 23.5977, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BinNt09_LA
    SetDynamicObjectMaterial(object_pooExterior[53], 0, -1, "none", "none", 0xFFFFFFFF);
    object_pooExterior[54] = CreateDynamicObject(1339, 1978.3441, -1289.8768, 23.5977, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //BinNt09_LA
    SetDynamicObjectMaterial(object_pooExterior[54], 0, -1, "none", "none", 0xFFFFFFFF);
    object_pooExterior[55] = CreateDynamicObject(19172, 1967.0068, -1309.1279, 24.9759, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[55], 0, "Reparieren", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[55], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[56] = CreateDynamicObject(18981, 2001.9442, -1298.4532, 11.6372, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[56], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[57] = CreateDynamicObject(19354, 1978.8149, -1284.5749, 25.5447, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[57], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[58] = CreateDynamicObject(19354, 1969.9051, -1305.2954, 25.5447, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[58], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[59] = CreateDynamicObject(18981, 2013.9371, -1318.4383, 11.6385, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx25mx25m
    SetDynamicObjectMaterial(object_pooExterior[59], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[60] = CreateDynamicObject(19464, 2033.1080, -1330.8031, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[60], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[61] = CreateDynamicObject(19464, 1985.5222, -1330.8031, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[61], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[62] = CreateDynamicObject(19464, 1979.5854, -1330.8031, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[62], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[63] = CreateDynamicObject(19464, 2027.1866, -1271.0141, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[63], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[64] = CreateDynamicObject(19464, 2033.1234, -1271.0141, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[64], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[65] = CreateDynamicObject(19464, 1987.4327, -1312.0622, 20.4507, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[65], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[66] = CreateDynamicObject(19173, 1989.6468, -1330.5727, 24.9202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[66], 0, "Los", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[66], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[67] = CreateDynamicObject(869, 1973.7589, -1327.5942, 23.3782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[68] = CreateDynamicObject(18766, 1971.0904, -1327.4946, 22.4932, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[68], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_pooExterior[69] = CreateDynamicObject(869, 1969.5174, -1327.3249, 23.3782, 0.0000, 0.0000, -176.7001, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[70] = CreateDynamicObject(19464, 1969.0450, -1325.0721, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[70], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[71] = CreateDynamicObject(19464, 1973.1948, -1325.0731, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[71], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[72] = CreateDynamicObject(19464, 1976.1059, -1327.9145, 20.4540, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[72], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[73] = CreateDynamicObject(18766, 1993.9227, -1327.4946, 22.4932, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[73], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_pooExterior[74] = CreateDynamicObject(18766, 2003.9228, -1327.4946, 22.4932, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[74], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_pooExterior[75] = CreateDynamicObject(18766, 2008.7729, -1327.4946, 22.4923, 90.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[75], 0, 4835, "airoads_las", "grassdry_128HV", 0xFFFFFFFF);
    object_pooExterior[76] = CreateDynamicObject(19464, 2010.4842, -1325.0721, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[76], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[77] = CreateDynamicObject(19464, 2004.5483, -1325.0721, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[77], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[78] = CreateDynamicObject(19464, 1998.6120, -1325.0721, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[78], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[79] = CreateDynamicObject(19464, 1992.6750, -1325.0721, 20.4540, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[79], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[80] = CreateDynamicObject(19464, 1991.8242, -1325.0731, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[80], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[81] = CreateDynamicObject(19464, 1988.9421, -1327.9134, 20.4540, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[81], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[82] = CreateDynamicObject(869, 1992.6395, -1327.5942, 23.3782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[83] = CreateDynamicObject(869, 1996.9493, -1327.5942, 23.3782, 0.0000, 0.0000, 160.6000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[84] = CreateDynamicObject(869, 2001.6092, -1327.5942, 23.3782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[85] = CreateDynamicObject(869, 2011.0505, -1327.5942, 23.3782, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[86] = CreateDynamicObject(869, 2006.6396, -1327.5936, 23.3782, 0.0000, 0.0000, 89.1996, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //veg_Pflowerswee
    object_pooExterior[87] = CreateDynamicObject(19464, 1969.9642, -1320.3730, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[87], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[88] = CreateDynamicObject(18762, 1987.9508, -1330.4481, 23.6527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[88], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[89] = CreateDynamicObject(18762, 1977.5100, -1330.4481, 23.6527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[89], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[90] = CreateDynamicObject(19464, 1969.9642, -1315.6926, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[90], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[91] = CreateDynamicObject(19464, 1969.9642, -1310.9227, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[91], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[92] = CreateDynamicObject(19464, 1969.9642, -1315.6926, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[92], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[93] = CreateDynamicObject(19464, 1967.1345, -1327.9154, 20.4549, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[93], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[94] = CreateDynamicObject(19464, 1967.1345, -1321.9836, 20.4549, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[94], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[95] = CreateDynamicObject(19464, 1967.1345, -1310.1357, 20.4549, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[95], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[96] = CreateDynamicObject(19464, 1967.1335, -1316.0727, 20.4538, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[96], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[97] = CreateDynamicObject(19464, 2013.3149, -1327.9433, 20.4528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[97], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[98] = CreateDynamicObject(19464, 2013.3149, -1321.9836, 20.4528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[98], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[99] = CreateDynamicObject(19464, 2013.3149, -1316.0467, 20.4528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[99], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[100] = CreateDynamicObject(19464, 2013.3149, -1308.9078, 20.4528, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[100], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[101] = CreateDynamicObject(19464, 2013.3160, -1311.9681, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[101], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[102] = CreateDynamicObject(19464, 2010.2253, -1312.0643, 20.4519, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[102], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[103] = CreateDynamicObject(19464, 2004.3055, -1312.0643, 20.4538, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[103], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[104] = CreateDynamicObject(19464, 1998.3686, -1312.0643, 20.4519, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[104], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[105] = CreateDynamicObject(19464, 1992.4320, -1312.0643, 20.4519, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[105], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[106] = CreateDynamicObject(19464, 1989.5920, -1315.1595, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[106], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[107] = CreateDynamicObject(19464, 1999.5920, -1315.1595, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[107], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[108] = CreateDynamicObject(19464, 2004.5920, -1315.1595, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[108], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[109] = CreateDynamicObject(19464, 1994.5920, -1315.1595, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[109], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[110] = CreateDynamicObject(19464, 2009.5920, -1315.1595, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[110], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[111] = CreateDynamicObject(19464, 1989.5920, -1308.9709, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[111], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[112] = CreateDynamicObject(19464, 2004.5920, -1308.9709, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[112], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[113] = CreateDynamicObject(19464, 2009.5920, -1308.9709, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[113], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[114] = CreateDynamicObject(19464, 1999.5920, -1308.9709, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[114], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[115] = CreateDynamicObject(19464, 1994.5920, -1308.9709, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[115], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[116] = CreateDynamicObject(1215, 1988.2851, -1281.1202, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[117] = CreateDynamicObject(19173, 1991.8205, -1330.5727, 25.0002, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[117], 0, "_______", OBJECT_MATERIAL_SIZE_256x128, "Candara", 100, 1, 0xFFFF8C00, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[117], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[118] = CreateDynamicObject(19173, 1991.0511, -1330.5727, 24.9202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[118], 0, "_______", OBJECT_MATERIAL_SIZE_256x128, "Candara", 100, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[118], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[119] = CreateDynamicObject(19464, 1969.9774, -1305.2309, 30.6200, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[119], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[120] = CreateDynamicObject(19354, 1969.9051, -1305.2954, 30.5645, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[120], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[121] = CreateDynamicObject(19173, 1990.5583, -1330.5727, 24.9202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[121], 0, "Santos", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[121], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[122] = CreateDynamicObject(19173, 1992.2484, -1330.5727, 24.9202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[122], 0, "Ordnun", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFFFF8C00, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[122], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[123] = CreateDynamicObject(19173, 1993.9610, -1330.5727, 24.9202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[123], 0, "gsamt", OBJECT_MATERIAL_SIZE_256x128, "Arial", 65, 1, 0xFFFF8C00, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[123], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[124] = CreateDynamicObject(19464, 1972.7983, -1302.3404, 30.6200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[124], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[125] = CreateDynamicObject(19173, 1989.6599, -1330.5727, 25.0002, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[125], 0, "_______", OBJECT_MATERIAL_SIZE_256x128, "Candara", 100, 1, 0xFFFF8C00, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[125], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[126] = CreateDynamicObject(19464, 1969.9774, -1299.4803, 30.6200, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[126], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[127] = CreateDynamicObject(19173, 1993.2104, -1330.5727, 24.9202, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture2
    SetDynamicObjectMaterialText(object_pooExterior[127], 0, "_______", OBJECT_MATERIAL_SIZE_256x128, "Candara", 100, 1, 0xFF000000, 0x00000000, 0);
    SetDynamicObjectMaterial(object_pooExterior[127], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[128] = CreateDynamicObject(18762, 1994.8608, -1330.4481, 23.6527, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[128], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[129] = CreateDynamicObject(19464, 1991.3935, -1330.4431, 23.3938, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[129], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[130] = CreateDynamicObject(19464, 1967.1374, -1302.3404, 30.6200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[130], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[131] = CreateDynamicObject(19354, 1972.8457, -1302.4049, 30.5645, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[131], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[132] = CreateDynamicObject(19464, 1976.7467, -1284.5350, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[132], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[133] = CreateDynamicObject(19464, 1971.6440, -1284.5350, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[133], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[134] = CreateDynamicObject(19464, 1976.7467, -1290.4720, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[134], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[135] = CreateDynamicObject(19464, 1976.7467, -1296.4079, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[135], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[136] = CreateDynamicObject(19464, 1971.6440, -1290.4720, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[136], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[137] = CreateDynamicObject(19464, 1971.6440, -1296.4079, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[137], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[138] = CreateDynamicObject(19464, 1966.5410, -1284.5350, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[138], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[139] = CreateDynamicObject(19464, 1966.5410, -1290.4720, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[139], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[140] = CreateDynamicObject(19464, 1966.5410, -1296.4079, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[140], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[141] = CreateDynamicObject(3934, 1973.5295, -1291.5632, 28.1082, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //helipad01
    object_pooExterior[142] = CreateDynamicObject(19464, 1969.9250, -1302.8585, 33.0662, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[142], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[143] = CreateDynamicObject(19464, 1969.9261, -1301.8675, 33.0623, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[143], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[144] = CreateDynamicObject(19464, 1970.4167, -1302.4084, 33.0461, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[144], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[145] = CreateDynamicObject(19464, 1970.4156, -1302.2983, 33.0452, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[145], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[146] = CreateDynamicObject(18766, 2013.9399, -1303.4516, 19.1340, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[146], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[147] = CreateDynamicObject(19464, 1976.7467, -1302.3431, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[147], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
    object_pooExterior[148] = CreateDynamicObject(19354, 1975.2340, -1281.6645, 25.9547, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[148], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[149] = CreateDynamicObject(19354, 1969.7528, -1281.6645, 25.9547, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall002
    SetDynamicObjectMaterial(object_pooExterior[149], 0, 6522, "cuntclub_law2", "marinawindow1_256", 0x00000000);
    object_pooExterior[150] = CreateDynamicObject(1215, 2035.2965, -1271.2912, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[151] = CreateDynamicObject(1215, 2024.3553, -1271.2912, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[152] = CreateDynamicObject(19464, 1967.1279, -1302.3891, 25.5200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[152], 0, 12855, "cunte_cop", "sw_brick05", 0x00000000);
    object_pooExterior[153] = CreateDynamicObject(1231, 2013.2911, -1312.0620, 25.6177, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_pooExterior[154] = CreateDynamicObject(1231, 1984.5804, -1312.0620, 25.6177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_pooExterior[155] = CreateDynamicObject(1231, 1967.2696, -1310.9217, 25.6177, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_pooExterior[156] = CreateDynamicObject(1231, 1967.2696, -1320.3125, 25.6177, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_pooExterior[157] = CreateDynamicObject(1215, 1977.4930, -1329.7014, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[158] = CreateDynamicObject(1215, 1987.9239, -1329.7220, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[159] = CreateDynamicObject(8623, 2051.5505, -1313.9167, 23.6485, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
    object_pooExterior[161] = CreateDynamicObject(8623, 2051.5505, -1288.0156, 23.6485, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bush03_lvs
    object_pooExterior[162] = CreateDynamicObject(966, 1986.0660, -1330.5412, 22.9897, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_gatebar01
    object_pooExterior[163] = CreateDynamicObject(19172, 1970.1671, -1308.2270, 22.9859, -90.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[163], 0, "@", OBJECT_MATERIAL_SIZE_256x128, "Webdings", 165, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[163], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[164] = CreateDynamicObject(19464, 1984.5920, -1308.9709, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[164], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[165] = CreateDynamicObject(19464, 1967.1345, -1304.1999, 20.4549, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[165], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[166] = CreateDynamicObject(19464, 1969.9642, -1305.4919, 20.4528, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[166], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[167] = CreateDynamicObject(19172, 1967.0068, -1306.7165, 24.4258, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[167], 0, "Tanken", OBJECT_MATERIAL_SIZE_256x128, "Arial", 50, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[167], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[168] = CreateDynamicObject(19172, 1967.0068, -1307.7264, 24.6557, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[168], 0, "&", OBJECT_MATERIAL_SIZE_256x128, "Arial", 80, 0, 0xFFFFFFFF, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[168], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[169] = CreateDynamicObject(18762, 1994.8618, -1330.4381, 23.6515, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[169], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[170] = CreateDynamicObject(18766, 1972.0107, -1330.4420, 21.6340, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[170], 0, 17547, "eastbeach4a_lae2", "dryhedge_128", 0xFFFFFFFF);
    object_pooExterior[171] = CreateDynamicObject(8661, 1986.0155, -1320.8249, 22.9829, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_pooExterior[171], 0, 4835, "airoads_las", "concretenewb256", 0xFF696969);
    object_pooExterior[172] = CreateDynamicObject(19464, 2004.3055, -1281.7147, 20.4538, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[172], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[173] = CreateDynamicObject(19464, 1998.3686, -1281.7147, 20.4519, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[173], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[174] = CreateDynamicObject(19464, 1992.4320, -1281.7147, 20.4519, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[174], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[175] = CreateDynamicObject(19464, 1989.5920, -1284.8105, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[175], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[176] = CreateDynamicObject(19464, 1994.5920, -1284.8105, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[176], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[177] = CreateDynamicObject(19464, 1999.5920, -1284.8105, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[177], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[178] = CreateDynamicObject(19464, 2004.5920, -1284.8105, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[178], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[179] = CreateDynamicObject(19464, 2009.5920, -1284.8105, 20.4519, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[179], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[180] = CreateDynamicObject(1231, 2004.5786, -1281.8613, 25.6177, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_pooExterior[181] = CreateDynamicObject(1231, 1994.5871, -1281.8613, 25.6177, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Streetlamp2
    object_pooExterior[182] = CreateDynamicObject(1280, 2012.8491, -1286.3723, 23.3446, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_pooExterior[183] = CreateDynamicObject(1280, 2012.8491, -1291.3425, 23.3446, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //parkbench1
    object_pooExterior[184] = CreateDynamicObject(18762, 2044.6120, -1303.7269, 23.6515, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[184], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[185] = CreateDynamicObject(18762, 2044.6120, -1296.8288, 23.6515, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx5m
    SetDynamicObjectMaterial(object_pooExterior[185], 0, 3979, "civic01_lan", "airportwall_256128", 0xFFFFFFFF);
    object_pooExterior[186] = CreateDynamicObject(19464, 2044.6230, -1300.2823, 23.3938, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[186], 0, 10765, "airportgnd_sfse", "white", 0x00000000);
    object_pooExterior[187] = CreateDynamicObject(19172, 2044.5056, -1299.7259, 24.9524, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[187], 0, "_______________", OBJECT_MATERIAL_SIZE_256x128, "Courier", 70, 1, 0xFFFFA500, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[187], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[188] = CreateDynamicObject(19172, 2044.5056, -1299.5653, 24.9123, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[188], 0, "Verwahr", OBJECT_MATERIAL_SIZE_256x128, "Courier New", 70, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[188], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[189] = CreateDynamicObject(19172, 2044.5056, -1300.7856, 24.8523, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_pooExterior[189], 0, "_______________", OBJECT_MATERIAL_SIZE_256x128, "Courier", 70, 1, 0xFF000000, 0x00000000, 1);
    SetDynamicObjectMaterial(object_pooExterior[189], 1, 19297, "matlights", "invisible", 0x00000000);
    object_pooExterior[190] = CreateDynamicObject(1215, 2044.5759, -1304.5595, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[191] = CreateDynamicObject(1215, 2044.5759, -1296.0185, 23.5265, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_pooExterior[192] = CreateDynamicObject(8661, 1958.2332, -1291.8354, 27.9724, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    object_pooExterior[193] = CreateDynamicObject(968, 1986.0660, -1330.5412, 23.7686, 0.0000, -90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Barrier
    object_pooExterior_barrier = object_pooExterior[193];
    object_pooExterior[194] = CreateDynamicObject(19464, 1966.5410, -1302.3431, 27.9661, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_POOEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_pooExterior[194], 0, 10051, "carimpound_sfe", "poundroofblock_sfe", 0x00000000);
*/
}
