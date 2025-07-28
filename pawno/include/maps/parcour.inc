#include <YSI\y_hooks>

// Global interior define
#define MAPS_PARCOUR_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 150.0;

// Parcour points
#define PARCOUR_SPAWN_POINT          1432.9171, -1459.6316, 125.3672
#define PARCOUR_SPAWN_POINT_FACING   312.0

// Map variables
new object_parcour[56];
// new pickup_parcour[1];
// new text3D_parcour[1];
// new vehicle_parcour[16];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnPlayerSpawn(playerid) {
    if (GetPVarInt(playerid, "PARCOUR")) {
        SetPlayerPos(playerid, PARCOUR_SPAWN_POINT);
        SetPlayerFacingAngle(playerid, PARCOUR_SPAWN_POINT_FACING);
        SetCameraBehindPlayer(playerid);
        SetPlayerSkin(playerid, Spieler[playerid][pSkin]);
        SetPlayerHealth(playerid, 100.0);
        DeletePVar(playerid, "PARCOUR");
        return -1;
    }

    return 1;
}

hook OnPlayerDeath(playerid, killerid, reason) {
    if (GetPlayerVirtualWorld(playerid) == VW_PARCOUR) 
    {
        SetPVarInt(playerid, "PARCOUR", 1);
        Spieler[playerid][pTot] = 0;
        Spieler[playerid][pTotTime] = 0;
        SpawnPlayer(playerid);
        return -1;
    }

    return 1;
}

CMD:parcour(playerid) {
    if (GetPlayerVirtualWorld(playerid) == VW_PARCOUR) {
        SpawnPlayer(playerid);
        return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Parkour-Welt verlassen.");
    }

    if (Spieler[playerid][pAdmin] < 2) return SendClientMessage(playerid, COLOR_RED, "Du hast nicht die benötigten Rechte.");
    SetPlayerPosEx(playerid, PARCOUR_SPAWN_POINT, MAPS_PARCOUR_INTERIOR, VW_PARCOUR);
    SetPlayerFacingAngle(playerid, PARCOUR_SPAWN_POINT_FACING);
    SetCameraBehindPlayer(playerid);
    return SendClientMessage(playerid, COLOR_YELLOW, "[INFO] {FFFFFF}Du hast die Parkour-Welt betreten.");
}

hook OnGameModeInit() {
    // Pickups

    // 3DTextLabels

    // Vehicles

    // Objects
    object_parcour[0] = CreateDynamicObject(993, 1442.4071, -1455.9748, 124.0281, 90.0000, 89.6998, -90.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_barrier10
    object_parcour[1] = CreateDynamicObject(14467, 1466.4809, -1391.2832, 138.3509, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter_statue
    object_parcour[2] = CreateDynamicObject(973, 1447.7519, -1449.7982, 123.9571, 0.0000, 0.0000, 75.9999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[3] = CreateDynamicObject(973, 1451.0096, -1436.7458, 125.1671, 0.0000, 0.0000, 75.9999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[4] = CreateDynamicObject(993, 1453.1446, -1427.3072, 126.3610, 91.0000, 163.9001, 90.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_barrier10
    object_parcour[5] = CreateDynamicObject(993, 1456.2943, -1416.2600, 127.6352, 48.9001, 163.9001, 90.0998, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_barrier10
    object_parcour[6] = CreateDynamicObject(993, 1459.5959, -1405.1612, 131.1766, 123.5999, 17.1998, 62.2000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_barrier10
    object_parcour[7] = CreateDynamicObject(3502, 1462.3708, -1397.5697, 136.2391, 34.5998, 0.0000, -26.7999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsN_con_tube
    object_parcour[8] = CreateDynamicObject(1554, 1493.0200, -1359.1765, 166.9311, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CJ_WATER_BARRIER
    object_parcour[9] = CreateDynamicObject(969, 1466.9200, -1388.2181, 139.4698, 0.1999, -41.0998, 70.4000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Electricgate
    object_parcour[10] = CreateDynamicObject(975, 1470.5731, -1379.5758, 151.0962, -43.2999, -76.1998, -2.2999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Columbiangate
    object_parcour[11] = CreateDynamicObject(975, 1473.1982, -1373.7269, 158.4465, -33.7000, -75.1998, -1.7000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Columbiangate
    object_parcour[12] = CreateDynamicObject(975, 1490.1252, -1359.1291, 162.8018, 0.0000, -46.9000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Columbiangate
    object_parcour[13] = CreateDynamicObject(19467, 1496.7530, -1358.7065, 167.7223, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
    object_parcour[14] = CreateDynamicObject(13593, 1563.8548, -1380.5246, 183.5155, -1.1000, 90.0000, 134.8000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kickramp03
    object_parcour[15] = CreateDynamicObject(19467, 1501.1014, -1357.9073, 165.8325, 0.0000, 29.9999, 20.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vehicle_barrier01
    object_parcour[16] = CreateDynamicObject(13637, 1541.8487, -1384.5045, 175.6101, 0.0000, 0.0000, 140.8000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //tuberamp
    object_parcour[17] = CreateDynamicObject(3702, 1518.9735, -1370.8216, 165.4207, 0.0000, 0.0000, -141.3999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //barrio6B_LAe2
    object_parcour[18] = CreateDynamicObject(14409, 1569.9945, -1344.4245, 197.4799, 0.0000, 0.0000, -157.5997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //carter-stairs02
    object_parcour[19] = CreateDynamicObject(1245, 1560.3924, -1384.5815, 181.3444, 0.0000, 0.0000, -149.1000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newramp
    object_parcour[20] = CreateDynamicObject(1245, 1560.3924, -1384.5815, 181.3444, 0.0000, 0.0000, -149.1000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newramp
    object_parcour[21] = CreateDynamicObject(13636, 1577.4748, -1371.3304, 185.9160, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //logramps
    object_parcour[22] = CreateDynamicObject(1245, 1553.4245, -1386.5196, 177.4745, 0.0000, 0.0000, -175.6999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //newramp
    object_parcour[23] = CreateDynamicObject(1503, 1572.4122, -1377.8315, 186.6277, 0.0000, 45.8997, -89.8000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //DYN_RAMP
    object_parcour[24] = CreateDynamicObject(19817, 1571.4422, -1356.1059, 189.8515, 30.3999, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //CarFixerRamp1
    object_parcour[25] = CreateDynamicObject(2960, 1527.5738, -1314.9576, 211.1423, 0.0000, 0.0000, 68.7997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kmb_beam
    object_parcour[26] = CreateDynamicObject(18824, 1563.4425, -1314.2519, 204.6428, -86.3999, 151.8999, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Tube50mGlass90Bend1
    object_parcour[27] = CreateDynamicObject(18831, 1538.4012, -1297.0919, 208.5357, 69.7997, 3.5999, -65.3999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RT25mBend90Tube1
    object_parcour[28] = CreateDynamicObject(995, 1528.9449, -1311.8662, 209.9082, 0.0000, 32.5998, 69.1997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_barrier16
    object_parcour[29] = CreateDynamicObject(18778, 1524.5621, -1324.7353, 215.7086, 0.0000, 54.1999, 141.5000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RampT1
    object_parcour[30] = CreateDynamicObject(996, 1509.2939, -1381.7518, 262.0793, -62.5000, -22.1000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier1
    object_parcour[31] = CreateDynamicObject(973, 1500.2076, -1370.6256, 254.4098, 0.0000, 27.5000, 72.1997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[32] = CreateDynamicObject(18779, 1518.6706, -1348.0832, 235.2861, 0.0000, 7.5000, 44.9000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //RampT2
    object_parcour[33] = CreateDynamicObject(973, 1502.7247, -1362.7856, 250.1253, 0.0000, 27.5000, 72.1997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[34] = CreateDynamicObject(973, 1498.4631, -1378.2259, 258.1733, 23.0000, 27.8999, 72.1997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[35] = CreateDynamicObject(993, 1503.5560, -1382.3702, 261.4147, -90.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bar_barrier10
    object_parcour[36] = CreateDynamicObject(973, 1571.0122, -1335.8022, 323.3865, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[37] = CreateDynamicObject(973, 1520.5052, -1379.4731, 265.3965, 0.0000, -23.0998, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[38] = CreateDynamicObject(997, 1525.6568, -1379.4560, 268.1000, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_parcour[39] = CreateDynamicObject(997, 1529.6820, -1379.5118, 269.6716, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_parcour[40] = CreateDynamicObject(997, 1532.7392, -1379.4792, 271.2431, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier3
    object_parcour[41] = CreateDynamicObject(998, 1537.2805, -1379.2735, 273.2886, 125.9999, 5.1999, -0.3998, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Gdyn_barrier17
    object_parcour[42] = CreateDynamicObject(3502, 1549.0998, -1378.5909, 279.1741, 42.0998, 0.0000, -78.8999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //vgsN_con_tube
    object_parcour[43] = CreateDynamicObject(18811, 1572.6180, -1354.0709, 303.1098, -41.2999, 0.0000, -33.5998, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Tube50mGlassBulge1
    object_parcour[44] = CreateDynamicObject(973, 1575.4143, -1351.3778, 301.7351, 0.0000, 0.0000, 56.2000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[45] = CreateDynamicObject(973, 1568.4293, -1354.6042, 303.3887, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[46] = CreateDynamicObject(973, 1573.2403, -1350.3813, 306.6950, 0.0000, -22.0000, 54.5000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[47] = CreateDynamicObject(973, 1577.5384, -1344.3208, 311.5013, 0.0000, -40.8997, 55.4999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[48] = CreateDynamicObject(973, 1581.2523, -1338.8017, 317.4902, 0.0000, -36.8997, 55.5998, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[49] = CreateDynamicObject(994, 1576.2364, -1335.8972, 321.1524, 0.0000, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lhouse_barrier2
    object_parcour[50] = CreateDynamicObject(973, 1562.7303, -1338.7524, 326.2398, 0.0000, 28.8999, 36.2999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //sub_roadbarrier
    object_parcour[51] = CreateDynamicObject(18764, 1545.0091, -1351.8454, 329.5451, 0.0000, 0.0000, -51.3997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete5mx5mx5m
    object_parcour[52] = CreateDynamicObject(19172, 1546.9832, -1350.2845, 330.2901, 0.0000, 0.0000, 128.1999, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPPicture1
    SetDynamicObjectMaterialText(object_parcour[52], 0, "Z I E L", OBJECT_MATERIAL_SIZE_256x128, "Arial", 100, 1, 0xFF00008B, 0x00000000, 1);
    SetDynamicObjectMaterial(object_parcour[52], 1, 19297, "matlights", "invisible", 0x00000000);
    object_parcour[53] = CreateDynamicObject(1215, 1548.2523, -1352.2840, 331.9822, 0.0000, 0.0000, -49.8997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_parcour[54] = CreateDynamicObject(1215, 1545.1711, -1348.6269, 331.9822, 0.0000, 0.0000, -49.8997, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_parcour[55] = CreateDynamicObject(18766, 1545.9350, -1365.6842, 329.1336, 87.4999, 0.0000, 0.0000, VW_PARCOUR, MAPS_PARCOUR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Concrete10mx1mx5m
}