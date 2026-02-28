#include <YSI\y_hooks>

// Global interior define
#define MAPS_SAMDEXTERIOR_INTERIOR      0
#define MAPS_SAMDINTERIOR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// SAMD enter / exit points, staterepair and garage points
#define SAMD_INTERIOR_ENTER_COORDS		1153.4695, -1345.8171, 15.4365
#define SAMD_INTERIOR_EXIT_COORDS		1449.6344, -995.9602, 675.6033
#define SAMD_INTERIOR_ENTER_FACING		0.0
#define SAMD_INTERIOR_EXIT_FACING   	270.0
#define SAMD_STATEREPAIR_COORDS			1137.4974, -1350.2291, 14.0176
#define SAMD_CLOSED                     14.60000
#define SAMD_OPEN                       8.60000

// Map variables
new object_samdExterior[109];
new pickup_samdExterior[1];
new text3D_samdExterior[1];
new object_samdExteriortor[6];


hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	/*if (newkeys & KEY_SECONDARY_ATTACK) {
		if (IsPlayerInRangeOfPoint(playerid, 2.0, SAMD_INTERIOR_ENTER_COORDS)) { // Entrance
			SetPlayerFacingAngle(playerid, SAMD_INTERIOR_EXIT_FACING);
			SetCameraBehindPlayer(playerid);
			SetPlayerPosEx(playerid, SAMD_INTERIOR_EXIT_COORDS, MAPS_SAMDINTERIOR_INTERIOR, VW_SAMDINTERIOR);
			return 1;
		}
	}*/
	return 1;
}

hook OnPlayerConnect(playerid)
{
    RemoveBuildingForPlayer(playerid, 1529, 1098.8125, -1292.5469, 17.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 5930, 1134.2500, -1338.0781, 23.1563, 0.25);
    RemoveBuildingForPlayer(playerid, 5931, 1114.3125, -1348.1016, 17.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 5934, 1076.7109, -1358.0938, 15.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 5935, 1120.1563, -1303.4531, 18.5703, 0.25);
    RemoveBuildingForPlayer(playerid, 5936, 1090.0547, -1310.5313, 17.5469, 0.25);
    RemoveBuildingForPlayer(playerid, 1440, 1085.7031, -1361.0234, 13.2656, 0.25);
    RemoveBuildingForPlayer(playerid, 5731, 1076.7109, -1358.0938, 15.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 5787, 1090.0547, -1310.5313, 17.5469, 0.25);
    RemoveBuildingForPlayer(playerid, 5764, 1065.1406, -1270.5781, 25.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 5810, 1114.3125, -1348.1016, 17.9844, 0.25);
    RemoveBuildingForPlayer(playerid, 5811, 1131.1953, -1380.4219, 17.0703, 0.25);
    RemoveBuildingForPlayer(playerid, 5708, 1134.2500, -1338.0781, 23.1563, 0.25);
    RemoveBuildingForPlayer(playerid, 620, 1184.0078, -1343.2656, 12.5781, 0.25);
    RemoveBuildingForPlayer(playerid, 1294, 1115.0781, -1285.3672, 17.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 5737, 1120.1563, -1303.4531, 18.5703, 0.25);
	RemoveBuildingForPlayer(playerid, 5788, 1080.9844, -1305.5234, 16.3594, 0.25);
}

hook OnGameModeInit()
{
    	// Map Icon
    CreateDynamicMapIcon(SAMD_INTERIOR_ENTER_COORDS, 22, 0, VW_MAIN, MAPS_SAMDINTERIOR_INTERIOR);

	// Pickups
	pickup_samdExterior[0] = CreateDynamicPickup(1239, 1, SAMD_STATEREPAIR_COORDS, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR); // Staterepair

	// 3DTextLabels
	text3D_samdExterior[0] = _:CreateDynamic3DTextLabel(COLOR_HEX_YELLOW "Staats-Reparatur\n" COLOR_HEX_WHITE "Tippe /Staatrepair", COLOR_WHITE, SAMD_STATEREPAIR_COORDS, 10.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_SAMDEXTERIOR_INTERIOR); // Staterepair

    object_samdExterior[0] = CreateDynamicObject(19126, 1092.09998, -1368.90002, 13.40000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[1] = CreateDynamicObject(19126, 1118.30005, -1375.50000, 13.60000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[2] = CreateDynamicObject(19126, 1067.69995, -1336.50000, 13.10000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[3] = CreateDynamicObject(19126, 1067.69995, -1383.30005, 13.40000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[4] = CreateDynamicObject(19126, 1118.39941, -1369.00000, 13.50000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[5] = CreateDynamicObject(5708, 1138.69922, -1307.44995, 22.92220,   0.00000, 359.60001, 270.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[6] = CreateDynamicObject(1231, 1149.69995, -1371.09998, 15.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[7] = CreateDynamicObject(1231, 1180.59998, -1371.00000, 15.50000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[8] = CreateDynamicObject(1211, 1182.30005, -1390.00000, 13.10000,   0.00000, 0.00000, 9.99900, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[9] = CreateDynamicObject(8855, 1171.09998, -1371.00000, 12.99900,   0.70000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[10] = CreateDynamicObject(8855, 1140.69995, -1371.00000, 13.20000,   0.43400, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[11] = CreateDynamicObject(1231, 1161.40002, -1371.00000, 15.60000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[12] = CreateDynamicObject(700, 1184.00000, -1355.90002, 13.30000,   0.00000, 0.00000, 21.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[13] = CreateDynamicObject(700, 1115.19922, -1354.19922, 13.30000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[14] = CreateDynamicObject(673, 1100.40002, -1383.80005, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[15] = CreateDynamicObject(673, 1137.80005, -1383.69995, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[16] = CreateDynamicObject(673, 1173.00000, -1383.80005, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[17] = CreateDynamicObject(673, 1170.40002, -1371.00000, 12.80000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[18] = CreateDynamicObject(700, 1183.90002, -1383.69995, 12.20000,   0.00000, 0.00000, 333.98999, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[19] = CreateDynamicObject(700, 1112.59998, -1383.69995, 12.20000,   0.00000, 0.00000, 99.99800, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[20] = CreateDynamicObject(716, 1074.19995, -1383.80005, 12.90000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[21] = CreateDynamicObject(716, 1074.19995, -1292.30005, 12.80000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[22] = CreateDynamicObject(1231, 1131.00000, -1370.90002, 16.00000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[23] = CreateDynamicObject(3666, 1099.90002, -1330.59998, 39.60000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[24] = CreateObject(8079, 1123.09998, -1319.13000, 25.90084,   0.22500, 0.00000, 270.00000);
    object_samdExterior[25] = CreateDynamicObject(3666, 1099.80005, -1307.69995, 39.60000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[26] = CreateDynamicObject(3666, 1133.00000, -1330.90002, 39.70000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[27] = CreateDynamicObject(3666, 1132.50000, -1307.69995, 39.70000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[28] = CreateDynamicObject(3934, 1110.06641, -1319.66113, 39.09812,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[29] = CreateObject(9946, 1167.19995, -1361.00000, 12.69550,   0.70000, 0.24000, 90.00000);
    object_samdExterior[30] = CreateObject(9946, 1129.00000, -1361.00000, 12.86200,   359.81299, 0.24000, 90.00000);
    object_samdExterior[31] = CreateDynamicObject(673, 1160.69995, -1383.90002, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[32] = CreateDynamicObject(673, 1139.40002, -1370.90002, 13.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[33] = CreateObject(9946, 1091.59998, -1361.00000, 12.69000,   359.81299, 0.41000, 90.00000);
    object_samdExterior[34] = CreateDynamicObject(7191, 1091.69995, -1380.31116, -1.80000,   90.00000, 180.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[35] = CreateDynamicObject(7191, 1089.81995, -1359.99902, 20.30000,   0.00000, 270.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[36] = CreateDynamicObject(7191, 1085.90002, -1359.99902, 20.30000,   0.00000, 270.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[37] = CreateDynamicObject(7191, 1082.02002, -1359.99902, 20.30000,   0.00000, 270.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[38] = CreateDynamicObject(7191, 1078.12000, -1359.99902, 20.30000,   0.00000, 270.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[39] = CreateDynamicObject(7191, 1091.69397, -1376.59998, -1.80000,   90.00000, 180.00500, 179.98399, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[40] = CreateDynamicObject(7191, 1091.69922, -1360.00000, -1.80000,   90.00000, 179.99500, 179.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[41] = CreateDynamicObject(7191, 1091.69922, -1356.19995, -1.80000,   90.00000, 179.99500, 179.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[42] = CreateDynamicObject(7191, 1091.69922, -1352.27783, -1.80000,   90.00000, 180.00500, 179.98399, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[43] = CreateDynamicObject(7191, 1091.69922, -1348.37781, -1.80000,   90.00000, 179.99500, 179.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[44] = CreateDynamicObject(7191, 1091.69922, -1345.31995, -1.80000,   90.00000, 179.99500, 179.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[45] = CreateDynamicObject(7191, 1091.69922, -1341.59998, -1.80000,   90.00000, 180.00500, 179.98399, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[46] = CreateDynamicObject(7191, 1091.69922, -1370.63000, -1.80000,   90.00000, 179.99500, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[47] = CreateDynamicObject(700, 1149.80005, -1383.59998, 12.20000,   0.00000, 0.00000, 83.98500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[48] = CreateDynamicObject(673, 1124.50000, -1383.69922, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[49] = CreateObject(9946, 1091.59998, -1314.69995, 12.62000,   359.80801, 359.76001, 90.00000);
    object_samdExterior[50] = CreateObject(9946, 1129.69995, -1309.32996, 12.76000,   0.00000, 0.05500, 0.00000);
    object_samdExterior[51] = CreateObject(9946, 1166.74304, -1314.80005, 12.70000,   0.30000, 0.20000, 90.00000);
    object_samdExterior[52] = CreateDynamicObject(700, 1183.90002, -1292.59998, 12.20000,   0.00000, 0.00000, 21.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[53] = CreateDynamicObject(700, 1152.09998, -1292.50000, 12.20000,   0.00000, 0.00000, 21.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[54] = CreateDynamicObject(673, 1161.00000, -1292.00000, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[55] = CreateDynamicObject(673, 1172.30005, -1292.00000, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[56] = CreateDynamicObject(673, 1088.19995, -1292.09998, 12.20000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[57] = CreateDynamicObject(2774, 1073.19995, -1381.50000, 7.94000,   0.00000, 180.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[58] = CreateDynamicObject(7191, 1074.29553, -1359.99902, 20.30000,   0.00000, 90.00000, 179.99500, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[59] = CreateDynamicObject(2774, 1073.19922, -1373.09998, 7.30000,   0.00000, 179.99500, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[60] = CreateDynamicObject(7191, 1072.39941, -1359.99902, 18.43000,   0.00000, 180.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[61] = CreateDynamicObject(2774, 1073.19922, -1364.68884, 7.30000,   0.00000, 179.99500, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[62] = CreateDynamicObject(2774, 1073.19922, -1356.27002, 7.30000,   0.00000, 179.99500, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[63] = CreateDynamicObject(2774, 1073.19922, -1347.85596, 7.30000,   0.00000, 179.99500, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[64] = CreateDynamicObject(2774, 1073.19922, -1339.44995, 7.30000,   0.00000, 179.99500, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[65] = CreateDynamicObject(2774, 1072.59900, -1337.90002, 7.90000,   0.00000, 180.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[66] = CreateDynamicObject(7191, 1075.59998, -1337.30005, -1.80000,   90.00000, 179.99500, 90.01100, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[67] = CreateDynamicObject(7191, 1079.59998, -1339.70996, -1.80000,   90.00000, 180.00500, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[68] = CreateDynamicObject(7191, 1079.56006, -1337.30005, -1.80000,   90.00000, 180.00500, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[69] = CreateDynamicObject(7191, 1075.89941, -1339.70996, -1.80000,   90.00000, 180.00500, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[70] = CreateDynamicObject(7191, 1091.69922, -1373.00000, -1.80000,   90.00000, 180.00500, 359.98901, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[71] = CreateDynamicObject(3851, 1091.70996, -1365.18005, 18.30000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[72] = CreateDynamicObject(7191, 1079.59961, -1382.19897, -1.80000,   90.00000, 180.00500, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[73] = CreateDynamicObject(7191, 1075.98999, -1382.19897, -1.80000,   90.00000, 180.00500, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[74] = CreateDynamicObject(7191, 1083.50000, -1382.19824, -1.80000,   90.00000, 180.00500, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[75] = CreateDynamicObject(7191, 1087.31995, -1382.19824, -1.80000,   90.00000, 179.99500, 90.01100, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[76] = CreateDynamicObject(7191, 1089.82227, -1382.19824, -1.80000,   90.00000, 179.99500, 90.01100, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[77] = CreateDynamicObject(3578, 1078.90002, -1373.09998, 12.10000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[78] = CreateDynamicObject(3578, 1078.90002, -1364.69995, 12.06000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[79] = CreateDynamicObject(3578, 1078.90002, -1347.80005, 11.91000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[80] = CreateDynamicObject(3578, 1078.90002, -1356.29980, 12.01000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[81] = CreateDynamicObject(984, 1099.09998, -1369.00000, 13.60000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[82] = CreateDynamicObject(984, 1111.90930, -1369.00000, 13.60000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[83] = CreateDynamicObject(984, 1098.19995, -1382.40002, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[84] = CreateDynamicObject(984, 1111.01001, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[85] = CreateDynamicObject(984, 1123.81995, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[86] = CreateDynamicObject(984, 1136.63000, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[87] = CreateDynamicObject(984, 1149.43994, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[88] = CreateDynamicObject(984, 1162.24780, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[89] = CreateDynamicObject(984, 1175.05664, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[90] = CreateDynamicObject(983, 1183.06006, -1382.39941, 13.40000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[91] = CreateDynamicObject(3785, 1072.21997, -1381.50000, 18.30000,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[92] = CreateDynamicObject(3785, 1072.21997, -1339.50000, 18.30000,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[93] = CreateDynamicObject(3785, 1072.21997, -1373.09998, 18.30000,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[94] = CreateDynamicObject(3785, 1072.21997, -1364.69995, 18.30000,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[95] = CreateDynamicObject(3785, 1072.21997, -1356.19995, 18.30000,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[96] = CreateDynamicObject(3785, 1072.21997, -1347.80005, 18.30000,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[97] = CreateDynamicObject(3785, 1091.88000, -1361.50000, 18.30000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[98] = CreateDynamicObject(3785, 1091.88000, -1369.09998, 18.30000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[99] = CreateDynamicObject(3519, 1082.30005, -1373.09998, 20.00000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[100] = CreateDynamicObject(3519, 1082.29980, -1364.69995, 20.00000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[101] = CreateDynamicObject(3519, 1082.29980, -1356.29980, 20.00000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[102] = CreateDynamicObject(3519, 1082.29980, -1347.80005, 20.00000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[103] = CreateDynamicObject(983, 1118.30994, -1372.18896, 13.65500,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[104] = CreateDynamicObject(8325, 1084.40002, -1382.29004, 17.80000,   0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[105] = CreateDynamicObject(1238, 1091.19995, -1381.69995, 13.30000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[106] = CreateDynamicObject(10183, 1097.68799, -1372.77698, 12.94000,   0.30000, 0.29000, 225.88800, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExterior[107] = CreateDynamicObject(3934, 1124.38892, -1319.56750, 39.15632,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    object_samdExteriortor[0] = CreateDynamicObject(10575, 1072.44995, -1377.19995, 14.60000,   359.89999, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExteriortor[1] = CreateDynamicObject(10575, 1072.43298, -1368.89197, 14.60000,   359.89600, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExteriortor[2] = CreateDynamicObject(10575, 1072.43298, -1360.44556, 14.60000,   359.89600, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExteriortor[3] = CreateDynamicObject(10575, 1072.43298, -1352.00000, 14.52000,   359.89600, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExteriortor[4] = CreateDynamicObject(10575, 1072.43262, -1343.62219, 14.52000,   359.89600, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_samdExteriortor[5] = CreateDynamicObject(10575, 1091.73999, -1365.32996, 14.60000,   359.89600, 0.00000, 0.00000, VW_MAIN, MAPS_SAMDEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    
}
