#include <YSI\y_hooks>

// Global interior define
#define MAPS_TRAFFICLIGHTS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Map variables
new object_trafficLights[39];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1283, 1311.2734, -1746.1172, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1345.7656, -1740.6172, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1325.7109, -1732.8281, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1335.1953, -1731.7813, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1357.5156, -1732.9375, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1376.5156, -1731.8516, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1388.3594, -1745.4453, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1441.8594, -1733.0078, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1403.3672, -1733.0078, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1414.4141, -1731.4297, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1513.2344, -1732.9219, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1568.8828, -1745.4766, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1545.7656, -1731.6719, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1530.1172, -1717.0078, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1582.6719, -1733.1328, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1688.9141, -1826.5078, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1688.8672, -1745.4688, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1672.0156, -1731.5234, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1690.2109, -1718.5781, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1701.9922, -1732.8750, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1762.7891, -1732.8281, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1736.5313, -1731.7969, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1750.2656, -1719.6328, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1350, 1286.2578, -1718.2500, 12.4453, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1332.0859, -1406.4063, 15.6875, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1342.0000, -1384.6563, 15.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1358.4766, -1416.2734, 15.5859, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1367.9766, -1394.7734, 15.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1367.9766, -1394.7734, 15.7109, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1428.9375, -1605.8203, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1416.5859, -1591.7422, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1428.8984, -1577.1328, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1443.2031, -1592.9453, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1439.6563, -1440.2578, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1453.6016, -1455.9063, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1455.2578, -1427.5156, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1469.5625, -1441.5391, 15.6250, 0.25);
    RemoveBuildingForPlayer(playerid, 1350, 802.9609, -1416.4766, 12.5391, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 798.3750, -1415.6719, 15.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 807.9531, -1406.5391, 15.5703, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 786.9453, -1394.5703, 15.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 798.3828, -1384.3516, 15.6094, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 798.0781, -1337.8516, 15.6016, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 791.8047, -1326.7734, 15.4922, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 807.9766, -1319.6563, 15.5469, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 796.8203, -1309.5469, 15.4609, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1354.9063, -1291.3906, 15.4922, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1345.1641, -1269.2578, 16.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1161.6797, -964.5313, 44.5547, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1150.0547, -943.0781, 45.1172, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1158.0391, -933.2109, 45.1172, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1172.7578, -952.1875, 44.7813, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1369.2422, -1046.8672, 28.6641, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1343.3984, -1037.1094, 28.6641, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1352.9063, -1025.8359, 28.8203, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1373.9297, -1030.5313, 28.6172, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1352.9375, -942.9688, 36.4766, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1378.3594, -956.8516, 36.3672, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1390.3359, -936.3359, 36.4219, 0.25);
    RemoveBuildingForPlayer(playerid, 1283, 1366.0625, -922.5547, 36.3828, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    object_trafficLights[0] = CreateDynamicObject(1350, 1317.72729, -1741.97424, 12.54542,   0.00000, 0.00000, 1.00745, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[1] = CreateDynamicObject(1350, 1322.41589, -1726.76807, 12.54542,   0.00000, 0.00000, 89.97610, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[2] = CreateDynamicObject(1350, 1287.44409, -1717.59631, 12.44530,   0.00000, 0.00000, 269.82474, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[3] = CreateDynamicObject(1350, 1699.54675, -1726.89905, 12.55401,   0.00000, 0.00000, 89.83974, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[4] = CreateDynamicObject(1350, 1684.36646, -1721.94824, 12.65299,   0.00000, 0.00000, 179.72234, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[5] = CreateDynamicObject(1350, 1694.76941, -1742.37598, 12.55401,   0.00000, 0.00000, 359.39056, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[6] = CreateDynamicObject(1350, 1679.33838, -1737.59424, 12.55401,   0.00000, 0.00000, 274.20010, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[7] = CreateDynamicObject(1350, 1362.70215, -1416.31506, 12.68963,   0.00000, 0.00000, 356.71692, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[8] = CreateDynamicObject(1350, 1332.48059, -1411.12793, 12.68928,   0.00000, 0.00000, 270.21872, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[9] = CreateDynamicObject(1350, 1337.51416, -1384.89050, 12.68928,   0.00000, 0.00000, 182.14655, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[10] = CreateDynamicObject(1350, 1367.60706, -1390.05103, 12.68963,   0.00000, 0.00000, 89.77437, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[11] = CreateDynamicObject(1350, 1449.45837, -1430.82336, 12.40214,   0.00000, 0.00000, 189.35634, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[12] = CreateDynamicObject(1350, 1464.77869, -1435.77063, 12.40214,   0.00000, 0.00000, 88.93259, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[13] = CreateDynamicObject(1350, 1459.93079, -1450.90747, 12.40214,   0.00000, 0.00000, 4.44838, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[14] = CreateDynamicObject(1350, 1444.90698, -1445.97791, 12.40214,   0.00000, 0.00000, 266.17035, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[15] = CreateDynamicObject(1350, 1354.71899, -947.85608, 33.35314,   0.00000, 0.00000, 256.64737, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[16] = CreateDynamicObject(1350, 1382.76147, -957.17511, 33.35314,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[17] = CreateDynamicObject(1350, 1390.75452, -931.77972, 33.35314,   0.00000, 0.00000, 88.08302, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[18] = CreateDynamicObject(1350, 1361.35950, -922.91998, 33.35314,   0.00000, 0.00000, 172.13828, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[19] = CreateDynamicObject(1350, 1153.67578, -933.57562, 42.10023,   0.00000, 0.00000, 181.74049, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[20] = CreateDynamicObject(1350, 1152.40051, -959.44867, 41.32807,   0.00000, 0.00000, 269.40631, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[21] = CreateDynamicObject(1350, 1170.33813, -936.63000, 42.10023,   0.00000, 0.00000, 96.81906, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[22] = CreateDynamicObject(1350, 1168.16577, -961.64301, 41.32807,   0.00000, 0.00000, 0.88575, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[23] = CreateDynamicObject(1350, 787.37964, -1325.38806, 12.44076,   0.00000, 0.00000, 274.23172, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[24] = CreateDynamicObject(1350, 802.55518, -1337.42590, 12.34205,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[25] = CreateDynamicObject(1350, 807.60583, -1315.04773, 12.34205,   0.00000, 0.00000, 90.16903, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[26] = CreateDynamicObject(1350, 792.30585, -1309.92529, 12.44076,   0.00000, 0.00000, 180.08270, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[27] = CreateDynamicObject(1350, 791.52386, -1384.90295, 12.35885,   0.00000, 0.00000, 177.93512, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[28] = CreateDynamicObject(1350, 787.03296, -1410.98633, 12.35885,   0.00000, 0.00000, 273.09323, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[29] = CreateDynamicObject(1350, 807.57178, -1390.47949, 12.35885,   0.00000, 0.00000, 89.70203, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[30] = CreateDynamicObject(1350, 802.54938, -1416.05505, 12.35885,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[31] = CreateDynamicObject(1350, 1439.70227, -1586.92700, 12.28955,   0.00000, 0.00000, 88.67950, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[32] = CreateDynamicObject(1350, 1419.60657, -1597.55054, 12.28955,   0.00000, 0.00000, 272.32889, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[33] = CreateDynamicObject(1350, 1424.28992, -1582.08752, 12.28955,   0.00000, 0.00000, 181.06067, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[34] = CreateDynamicObject(1350, 1434.62732, -1602.43896, 12.28955,   0.00000, 0.00000, 357.82962, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[35] = CreateDynamicObject(1350, 1343.89124, -1041.66797, 25.45462,   0.00000, 0.00000, 276.23648, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[36] = CreateDynamicObject(1350, 1373.75793, -1046.56396, 25.45462,   0.00000, 0.00000, 3.32605, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[37] = CreateDynamicObject(1350, 1378.30908, -1031.06628, 25.45462,   0.00000, 0.00000, 95.72239, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_trafficLights[38] = CreateDynamicObject(1350, 1348.52246, -1026.06616, 25.45462,   0.00000, 0.00000, 186.43243, VW_MAIN, MAPS_TRAFFICLIGHTS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}