#include <YSI\y_hooks>

// Global interior define
#define HITMAN_INTERIOR			      4
#define MAPS_HITMANBASE_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 200.0;

// Hitman base points
#define HITMANBASE_SPAWN2_POINT			1515.8018, -1457.2578, 9.5000
#define HITMANBASE_SPAWN2_POINT_FACING  0.0
#define HITMANBASE_ENTER_COORDS         -1067.1992, -1201.9427, 129.3584
#define HITMANBASE_EXIT_COORDS          302.1405, 300.7604, 999.1484
#define HITMANBASE_ENTER_FACING         0.0
#define HITMANBASE_EXIT_FACING          180.0
#define HITMANBASE_AD_POINT             -1061.2728, -1201.9796, 129.4548
#define HITMAN_GATE_RANGE_COORDS		1534.8059, -1451.2822, 12.6244
#define HITMAN_GATE_OPEN_Z              7.514380
#define HITMAN_GATE_CLOSED_Z            12.624402
#define HITMANBASE_AD_POINT2			1524.1472, -1457.2494, 9.5000
#define HITMANBASE_WEAPONS_DEPOT_POINT2	1518.9912, -1457.2953, 9.5000
#define HITMANBASE_TELE_DACH            1543.1931,-1479.9551,63.8594
#define HITMANBASE_TELE_BASE            1528.8279,-1468.2585,9.5000


// Map variables
new object_hitmanBase[71];
new pickup_hitmanBase[6];
new text3D_hitmanBase[5];

/*CMD:agtor(playerid, params[]) {
    if (!(Spieler[playerid][pFraktion] == 14))
        return SendClientMessage(playerid, COLOR_RED, "Du bist kein Staatsbeamter.");

    if (IsPlayerInRangeOfPoint(playerid, 8.0, HITMAN_GATE_RANGE_COORDS)) {
        new Float:fX, Float:fY, Float:fZ;
        GetDynamicObjectPos(object_hBase_gate, fX, fY, fZ);
        
        if (fZ == HITMAN_GATE_OPEN_Z)
            MoveDynamicObject(object_hBase_gate, fX, fY, HITMAN_GATE_CLOSED_Z, 3.25);
        else
            MoveDynamicObject(object_hBase_gate, fX, fY, HITMAN_GATE_OPEN_Z, 3.25);

        return 1;
    }
    
    return SendClientMessage(playerid, COLOR_RED, "Du bist nicht in der Nähe des Tores.");
}*/

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 705, -1086.4141, -1291.3906, 128.0703, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -1088.4063, -1238.4375, 129.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 3276, -1088.4063, -1249.9219, 129.0625, 0.25);
	RemoveBuildingForPlayer(playerid, 691, -1073.8047, -1234.7578, 128.0781, 0.25);
	RemoveBuildingForPlayer(playerid, 17008, -1067.5703, -1200.7266, 134.3125, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1028.5703, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1030.5781, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1032.5625, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1034.5703, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1036.5703, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1026.5625, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 3260, -1024.5625, -1179.7188, 129.2188, 0.25);
	RemoveBuildingForPlayer(playerid, 691, -1023.8047, -1171.0938, 128.5859, 0.25);
	RemoveBuildingForPlayer(playerid, 705, -1022.8750, -1153.4453, 128.2734, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    if (newkeys & KEY_SECONDARY_ATTACK) {
        if (IsPlayerInRangeOfPoint(playerid, 1.0, HITMANBASE_ENTER_COORDS)) { // Hitman Entrance
            if (Spieler[playerid][pFraktion] != 14) return SendClientMessage(playerid, COLOR_RED, "[INFO] {FFFFFF}Du hast keine Schlüssel um die Tür zu öffnen.");
			SetPlayerPos(playerid, HITMANBASE_EXIT_COORDS);
            SetPlayerFacingAngle(playerid, HITMANBASE_EXIT_FACING);
            SetPlayerInterior(playerid, HITMAN_INTERIOR);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
        else if (IsPlayerInRangeOfPoint(playerid, 1.0, HITMANBASE_EXIT_COORDS)) { // Hitman Exit
            SetPlayerPos(playerid, HITMANBASE_ENTER_COORDS);
            SetPlayerFacingAngle(playerid, HITMANBASE_ENTER_FACING);
            SetPlayerInterior(playerid, MAPS_HITMANBASE_INTERIOR);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
        else if (IsPlayerInRangeOfPoint(playerid, 1.0, HITMANBASE_TELE_BASE)) { // Hitman Dach
            SetPlayerPos(playerid, HITMANBASE_TELE_DACH);
            SetPlayerFacingAngle(playerid, HITMANBASE_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
        else if (IsPlayerInRangeOfPoint(playerid, 1.0, HITMANBASE_TELE_DACH)) { // Hitman Base
            SetPlayerPos(playerid, HITMANBASE_TELE_BASE);
            SetPlayerFacingAngle(playerid, HITMANBASE_ENTER_FACING);
            SetCameraBehindPlayer(playerid);
            return 1;
        }
    }

    return 1;
}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
    pickup_hitmanBase[0] = CreateDynamicPickup(1239,  1, HITMANBASE_AD_POINT, VW_MAIN, MAPS_HITMANBASE_INTERIOR); // Hitman ad point
    pickup_hitmanBase[1] = CreateDynamicPickup(1254,  1, HITMANBASE_WEAPONS_DEPOT_POINT2, VW_MAIN); // Hitman weapons depot point
    pickup_hitmanBase[2] = CreateDynamicPickup(1239,  1, HITMANBASE_AD_POINT2, VW_MAIN); // Hitman ad point
    pickup_hitmanBase[3] = CreateDynamicPickup(1240,  1, HITMANBASE_SPAWN2_POINT, VW_MAIN); // Hitman spawn2 point
    pickup_hitmanBase[4] = CreateDynamicPickup(1239,  1, HITMANBASE_TELE_DACH, VW_MAIN,MAPS_HITMANBASE_INTERIOR); // Dach i Point
    pickup_hitmanBase[5] = CreateDynamicPickup(19197,  1, HITMANBASE_TELE_BASE, VW_MAIN,MAPS_HITMANBASE_INTERIOR); // Base i Point

    // 3DTextLabels
    text3D_hitmanBase[0] = _:CreateDynamic3DTextLabel("Agency Werbung\n" COLOR_HEX_WHITE "Tippe /HWerbung", COLOR_YELLOW, HITMANBASE_AD_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = HITMAN_INTERIOR);
	text3D_hitmanBase[1] = _:CreateDynamic3DTextLabel("Agency - Waffenlager\n" COLOR_HEX_WHITE "Tippe /Waffenlager", COLOR_YELLOW, HITMANBASE_WEAPONS_DEPOT_POINT2, 10.0, .testlos = 1, .worldid = VW_MAIN);
	text3D_hitmanBase[2] = _:CreateDynamic3DTextLabel("Agency Spawn\n" COLOR_HEX_WHITE "Tippe /Hitmanwaffen zum Ausrüsten\nTippe /Gheilen zum Heilen", COLOR_BLUE, HITMANBASE_SPAWN2_POINT, 10.0, .testlos = 1, .worldid = VW_MAIN);
	text3D_hitmanBase[3] = _:CreateDynamic3DTextLabel("Agency Werbung\n" COLOR_HEX_WHITE "Tippe /HWerbung", COLOR_YELLOW, HITMANBASE_AD_POINT2, 15.0, .testlos = 1, .worldid = VW_MAIN);
	text3D_hitmanBase[4] = _:CreateDynamic3DTextLabel(COLOR_HEX_RED"Agency Teleport\n" COLOR_HEX_WHITE "Drücke 'Enter'", COLOR_YELLOW, HITMANBASE_TELE_BASE, 15.0, .testlos = 1, .worldid = VW_MAIN);
	

    // Objects
    object_hitmanBase[0] = CreateDynamicObject(17008, -1072.00659, -1200.98999, 134.19431,   0.00000, 0.00000, 90.13480, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[1] = CreateDynamicObject(3125, -1071.95447, -1213.22168, 128.85353,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[2] = CreateDynamicObject(3125, -1065.28674, -1213.21240, 128.85353,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[3] = CreateDynamicObject(3125, -1060.68604, -1213.20508, 128.85353,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[4] = CreateDynamicObject(3125, -1058.46741, -1210.96509, 128.85353,   0.00000, 0.00000, 91.50192, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[5] = CreateDynamicObject(3125, -1058.57703, -1203.82690, 128.85353,   0.00000, 0.00000, 91.50192, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[6] = CreateDynamicObject(3934, -1073.41187, -1265.81934, 128.23180,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[7] = CreateDynamicObject(3934, -1087.71570, -1281.61255, 128.23180,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[8] = CreateDynamicObject(3934, -1073.49390, -1281.49207, 128.21181,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[9] = CreateDynamicObject(3934, -1087.80701, -1265.74866, 128.23180,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[10] = CreateDynamicObject(3276, -1094.07861, -1220.91907, 129.06250,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[11] = CreateDynamicObject(705, -1114.79492, -1273.74670, 128.07031,   3.14159, 0.00000, 0.95120, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[12] = CreateDynamicObject(3125, -1064.98657, -1253.31458, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[13] = CreateDynamicObject(3125, -1064.98792, -1248.71594, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[14] = CreateDynamicObject(3125, -1064.96582, -1244.09595, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[15] = CreateDynamicObject(3125, -1064.95129, -1239.49536, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[16] = CreateDynamicObject(3125, -1064.93909, -1234.87500, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[17] = CreateDynamicObject(3125, -1064.84741, -1224.60437, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[18] = CreateDynamicObject(3125, -1064.84644, -1220.04443, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[19] = CreateDynamicObject(3125, -1064.83203, -1215.53162, 128.93150,   0.00000, 0.00000, 89.98790, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[20] = CreateDynamicObject(3276, -1105.91394, -1220.93237, 129.06250,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[21] = CreateDynamicObject(3276, -1117.77844, -1220.93042, 129.06250,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[22] = CreateDynamicObject(17010, -1031.47791, -1175.66870, 128.21875,   356.85840, 0.00000, -3.14159, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[23] = CreateDynamicObject(3260, -1037.55969, -1178.55835, 129.21875,   356.85840, 0.00000, -1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[24] = CreateDynamicObject(3260, -1037.53857, -1176.63831, 129.21875,   356.85840, 0.00000, -1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[25] = CreateDynamicObject(3260, -1037.53723, -1174.57837, 129.21875,   356.85840, 0.00000, -1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[26] = CreateDynamicObject(3260, -1036.44067, -1173.59399, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[27] = CreateDynamicObject(3260, -1034.46033, -1173.58533, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[28] = CreateDynamicObject(3260, -1032.55933, -1173.57275, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[29] = CreateDynamicObject(3260, -1030.57764, -1173.54175, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[30] = CreateDynamicObject(3260, -1028.57739, -1173.54468, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[31] = CreateDynamicObject(3260, -1026.59668, -1173.53186, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[32] = CreateDynamicObject(3260, -1024.61536, -1173.54736, 129.21875,   356.85840, 0.00000, 0.00000, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[33] = CreateDynamicObject(3260, -1023.62744, -1178.65942, 129.21875,   3.14159, 0.00000, 1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[34] = CreateDynamicObject(3260, -1023.63940, -1176.67615, 129.21875,   3.14159, 0.00000, 1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[35] = CreateDynamicObject(3260, -1023.65820, -1174.59314, 129.21875,   3.14159, 0.00000, 1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[36] = CreateDynamicObject(3374, -1080.48279, -1217.50598, 129.70313,   356.85840, 0.00000, 1.38266, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[37] = CreateDynamicObject(3374, -1076.48389, -1217.37720, 129.70313,   356.85840, 0.00000, 1.38266, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[38] = CreateDynamicObject(3374, -1072.44287, -1217.27295, 129.70313,   356.85840, 0.00000, 1.38266, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[39] = CreateDynamicObject(708, -1118.24622, -1224.07227, 128.44531,   356.85840, 0.00000, 3.14159, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[40] = CreateDynamicObject(3276, -1099.43774, -1249.37000, 129.06250,   3.14159, 0.00000, 1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[41] = CreateDynamicObject(3276, -1099.44861, -1237.53210, 129.06250,   3.14159, 0.00000, 1.57080, VW_MAIN, MAPS_HITMANBASE_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

	// Objects - Interior
	object_hitmanBase[42] = CreateDynamicObject(1496, 302.968780, 300.029876, 998.162719, 0.399999, 0.000000, 179.866806, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[43] = CreateDynamicObject(2181, 305.769927, 305.993072, 998.148437, 0.000000, 0.000000, -90.175125, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[44] = CreateDynamicObject(1806, 304.667144, 305.406982, 998.148437, 0.000000, 0.000000, -69.773506, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[45] = CreateDynamicObject(19121, 306.138000, 300.076263, 997.677978, 0.000000, 0.000000, 294.663116, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[46] = CreateDynamicObject(19121, 298.285247, 300.068237, 997.667968, 0.000000, 0.000000, 245.861022, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[47] = CreateDynamicObject(1736, 305.898773, 305.535278, 1001.269531, 0.000000, -1.999999, -90.583518, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[48] = CreateDynamicObject(19315, 299.070648, 300.646575, 998.608886, 0.000000, 0.000000, 27.161043, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[49] = CreateDynamicObject(2060, 298.525115, 301.687469, 998.238525, 0.000000, 0.000000, -93.657951, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[50] = CreateDynamicObject(2060, 298.608642, 302.928741, 998.148437, 0.000000, 0.000000, 89.270416, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[51] = CreateDynamicObject(2060, 298.493652, 302.315979, 998.388671, 0.000000, 0.000000, 89.548957, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[52] = CreateDynamicObject(1828, 306.517852, 308.057586, 1002.304687, 0.000000, 0.000000, 147.969375, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[53] = CreateDynamicObject(2068, 301.975280, 304.151550, 1001.887634, 0.000000, 0.000000, 338.634399, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[54] = CreateDynamicObject(1550, 305.307220, 308.202026, 998.498413, 0.000000, 0.000000, 176.486099, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[55] = CreateDynamicObject(2036, 303.816131, 300.029296, 1000.201660, 91.700004, -15.899999, -163.713867, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[56] = CreateDynamicObject(1985, 303.523864, 309.260253, 1005.775634, 0.000000, 0.000000, 168.743545, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[57] = CreateDynamicObject(19087, 303.539459, 309.298736, 1008.087158, 0.000000, 0.000000, 131.025695, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[58] = CreateDynamicObject(1210, 303.043457, 304.654632, 1003.569396, -90.699989, 0.200000, 91.166687, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[59] = CreateDynamicObject(1578, 303.088226, 305.348693, 1003.539550, 0.000000, 0.000000, 403.089721, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[60] = CreateDynamicObject(2427, 301.888336, 300.216552, 1003.559387, 0.000000, 0.000000, -179.689163, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[61] = CreateDynamicObject(2821, 299.774841, 302.508178, 1003.579956, 0.000000, 0.000000, 190.065887, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[62] = CreateDynamicObject(18885, 311.003448, 309.351623, 1003.394714, 0.000000, 0.000000, -90.605049, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[63] = CreateDynamicObject(2232, 304.136138, 301.389770, 1002.875122, 0.000000, 0.000000, 131.006439, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[64] = CreateDynamicObject(19124, 301.338592, 315.001525, 998.148437, 0.000000, 0.000000, 440.169097, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[65] = CreateDynamicObject(19124, 301.401428, 312.380706, 998.108398, 0.000000, 0.000000, 442.049133, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[66] = CreateDynamicObject(2232, 304.659362, 305.754730, 1002.845214, 0.000000, 0.000000, 62.423088, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[67] = CreateDynamicObject(19273, 301.317199, 300.013397, 999.538818, 0.000000, 0.000000, 179.974807, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[68] = CreateDynamicObject(1814, 305.941101, 303.392852, 1002.304687, 0.000000, 0.000000, 78.868820, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[69] = CreateDynamicObject(19328, 298.250000, 308.778686, 1000.018615, 0.000000, 0.000000, 89.443969, VW_MAIN, HITMAN_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
	object_hitmanBase[70] = CreateDynamicObject(19380, 1534.8059, -1451.2822, 12.6244, 90.0000, 0.0000, 90.0000); //wall028	
	SetDynamicObjectMaterial(object_hitmanBase[70], 0, 3629, "arprtxxref_las", "ws_corrugated1", 0x00000000);	
}
