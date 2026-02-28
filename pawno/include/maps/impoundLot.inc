#include <YSI\y_hooks>

// Global interior define
#define MAPS_IMPOUNDLOT_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// Map variables
new object_impoundLot[22];

hook OnPlayerConnect(playerid) {
	// Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 5951, 958.8203, -1359.8672, 17.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 6002, 931.2266, -1357.3281, 25.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 6003, 954.6875, -1305.7734, 30.1406, 0.25);
    RemoveBuildingForPlayer(playerid, 1266, 932.5859, -1363.5156, 21.7969, 0.25);
    RemoveBuildingForPlayer(playerid, 1261, 958.3359, -1377.3203, 24.1328, 0.25);
    RemoveBuildingForPlayer(playerid, 1260, 932.5859, -1363.5156, 21.7969, 0.25);
    RemoveBuildingForPlayer(playerid, 5814, 931.2266, -1357.3281, 25.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1522, 929.3281, -1352.1719, 12.3281, 0.25);
    RemoveBuildingForPlayer(playerid, 1438, 981.8750, -1385.9922, 12.6484, 0.25);
    RemoveBuildingForPlayer(playerid, 1440, 948.7656, -1381.1641, 13.0469, 0.25);
    RemoveBuildingForPlayer(playerid, 1267, 958.3359, -1377.3203, 24.1328, 0.25);
    RemoveBuildingForPlayer(playerid, 5813, 958.8203, -1359.8672, 17.9688, 0.25);
    RemoveBuildingForPlayer(playerid, 1440, 957.9688, -1336.4531, 13.0313, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 951.4453, -1327.9531, 15.4922, 0.25);
    RemoveBuildingForPlayer(playerid, 5818, 954.6875, -1305.7734, 30.1406, 0.25);
    
    // Hangars on the old base
    RemoveBuildingForPlayer(playerid, 3776, 831.960, -1191.140, 25.039, 300.0);
    RemoveBuildingForPlayer(playerid, 3777, 831.960, -1191.140, 25.039, 300.0);
    // RemoveBuildingForPlayer(playerid, 3776, 868.132, -1191.140, 25.039, 0.250);
    // RemoveBuildingForPlayer(playerid, 3776, 902.335, -1191.140, 25.039, 0.250);
}

hook OnGameModeInit() {
	// Objects
	object_impoundLot[0] = CreateDynamicObject(19464, 954.5930, -1337.2429, 13.6799, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_impoundLot[0], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_impoundLot[1] = CreateDynamicObject(18766, 955.8272, -1337.2164, 11.0200, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
    SetDynamicObjectMaterial(object_impoundLot[1], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[2] = CreateDynamicObject(8661, 954.7327, -1366.7618, 12.5692, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[2], 0, 10778, "airportcpark_sfse", "ws_carpark3", 0xFFFFFFFF);
    object_impoundLot[3] = CreateDynamicObject(8661, 954.7501, -1354.8730, 12.5882, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[3], 0, 10778, "airportcpark_sfse", "ws_carpark3", 0xFFFFFFFF);
    object_impoundLot[4] = CreateDynamicObject(8661, 947.6804, -1347.3127, 12.5375, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[4], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_impoundLot[5] = CreateDynamicObject(8661, 947.6428, -1374.2646, 12.5375, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[5], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_impoundLot[6] = CreateDynamicObject(8661, 964.0531, -1374.2746, 12.5389, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[6], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_impoundLot[7] = CreateDynamicObject(8661, 964.0900, -1347.3322, 12.5396, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[7], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_impoundLot[8] = CreateDynamicObject(8661, 947.6353, -1364.7435, 12.5389, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[8], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_impoundLot[9] = CreateDynamicObject(18980, 983.6840, -1372.6357, 12.8170, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[9], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[10] = CreateDynamicObject(18980, 983.6845, -1349.2945, 12.8177, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[10], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[11] = CreateDynamicObject(18980, 927.2744, -1349.2945, 12.8170, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[11], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[12] = CreateDynamicObject(18980, 939.7249, -1384.6041, 12.8170, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[12], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[13] = CreateDynamicObject(8661, 964.0664, -1364.7646, 12.5394, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[13], 0, 16640, "a51", "concretemanky", 0xFFBDBEC6);
    object_impoundLot[14] = CreateDynamicObject(18980, 927.2946, -1372.6136, 12.8177, 0.0000, 90.0000, 90.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[14], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[15] = CreateDynamicObject(18980, 946.2553, -1384.6241, 12.8191, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[15], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    object_impoundLot[16] = CreateDynamicObject(19464, 957.2335, -1337.2469, 13.6794, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall104
    SetDynamicObjectMaterial(object_impoundLot[16], 0, 16093, "a51_ext", "ws_whitewall2_top", 0xFFFFFFFF);
    object_impoundLot[17] = CreateDynamicObject(19175, 956.9331, -1337.1102, 14.4260, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_impoundLot[17], 0, "Verwahrplatz", 90, "Arial", 40, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_impoundLot[17], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_impoundLot[18] = CreateDynamicObject(19175, 954.7031, -1337.1296, 14.4260, 0.0000, 0.0000, 180.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture4
    SetDynamicObjectMaterialText(object_impoundLot[18], 0, " - Los Santos", 90, "Arial", 40, 1, 0xFF000000, 0x0, 0);
    SetDynamicObjectMaterial(object_impoundLot[18], 1, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_impoundLot[19] = CreateDynamicObject(18980, 971.2453, -1384.6241, 12.8182, 0.0000, 90.0000, 0.0000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete1mx1mx25m
    SetDynamicObjectMaterial(object_impoundLot[19], 0, 12855, "cunte_cop", "ws_bigstones", 0xFFFFFFFF);
    
    // Solid ground
    object_impoundLot[20] = CreateDynamicObject(8661, 954.7597, -1354.8889, 12.5396, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[20], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);
    object_impoundLot[21] = CreateDynamicObject(8661, 954.7427, -1367.0491, 12.5496, 0.0000, 0.0000, -0.0798, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE); //gnhtelgrnd_lvs
    SetDynamicObjectMaterial(object_impoundLot[21], 0, 0, "INVALID", "INVALID", 0xFFFFFFFF);

    // Old Poo Base
    // object_impoundLot[22] = CreateDynamicObject(8841, 875.880187, -1180.036376, 18.981000, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE);
    // object_impoundLot[23] = CreateDynamicObject(8841, 832.003112, -1180.036376, 18.981000, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_IMPOUNDLOT_INTERIOR, .streamdistance = -1, .drawdistance = DRAWDISTANCE);
}