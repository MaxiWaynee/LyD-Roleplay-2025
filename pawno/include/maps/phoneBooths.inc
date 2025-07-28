#include <YSI\y_hooks>

// Global interior define
#define MAPS_PHONEBOOTHS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 70.0;
static Float:DRAWDISTANCE   = 50.0;

// Map variables
new object_phoneBooths[55];

hook OnPlayerConnect(playerid) {
    //Telefonzellen in LS
    RemoveBuildingForPlayer(playerid, 713, 1496.8672, -1707.8203, 13.4063, 0.25);
    RemoveBuildingForPlayer(playerid, 1216, 1721.6719, -1721.2891, 13.2266, 0.25);
    RemoveBuildingForPlayer(playerid, 1216, 1722.6094, -1721.2891, 13.2266, 0.25);
    // RemoveBuildingForPlayer(playerid, 3407, 322.6875, -131.1328, 0.5703, 0.25);
    // RemoveBuildingForPlayer(playerid, 773, 300.2656, -113.6250, 1.3516, 0.25);
    // RemoveBuildingForPlayer(playerid, 780, 321.0703, -109.4922, 0.6250, 0.25);
    
    //Telefonzellen in SF und LV
    // RemoveBuildingForPlayer(playerid, 3323, 270.2969, -49.3438, 3.4297, 0.25);
    // RemoveBuildingForPlayer(playerid, 13493, 224.4922, -68.2578, 5.3750, 0.25);
    // RemoveBuildingForPlayer(playerid, 1294, 262.4375, -63.4141, 5.0313, 0.25);
    // RemoveBuildingForPlayer(playerid, 780, 274.0313, -56.2266, 0.5547, 0.25);
    // RemoveBuildingForPlayer(playerid, 1460, 262.8281, -61.6172, 1.3359, 0.25);
    // RemoveBuildingForPlayer(playerid, 1460, 267.4609, -61.6172, 1.3359, 0.25);
    // RemoveBuildingForPlayer(playerid, 3407, 270.7344, -61.7813, 0.5703, 0.25);
    // RemoveBuildingForPlayer(playerid, 1460, 282.9063, -61.6172, 1.3359, 0.25);
    // RemoveBuildingForPlayer(playerid, 1460, 282.8594, -59.1563, 1.3359, 0.25);
    // RemoveBuildingForPlayer(playerid, 1460, 282.8594, -54.5234, 1.3359, 0.25);
    // RemoveBuildingForPlayer(playerid, 673, 270.2734, -39.2500, 0.1719, 0.25);
    // RemoveBuildingForPlayer(playerid, 769, 279.8359, -39.5391, -0.1406, 0.25);
    // RemoveBuildingForPlayer(playerid, 768, 278.0625, -18.9688, 0.9297, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Objects
    object_phoneBooths[0] = CreateDynamicObject(1216, 1493.8215, -1022.1099, 23.5000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[1] = CreateDynamicObject(1216, 1430.7398, -1022.1299, 23.5000,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    // object_phoneBooths[2] = CreateDynamicObject(1216, 1423.17529, -980.62933, 1639.50659,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telefonzelle 1
    // object_phoneBooths[3] = CreateDynamicObject(1216, 1418.03040, -980.65070, 1639.50659,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //Telefonzelle 2
    object_phoneBooths[4] = CreateDynamicObject(1216, 826.1378, -1356.4941, 13.1284, 0.0000,    0.0000, -179.5998, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //phonebooth1

    //Telefonzellen SF und LV
    object_phoneBooths[5] = CreateDynamicObject(1216, 642.22803, 1686.41943, 6.63350,   0.00000, 0.00000, -139.44000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[6] = CreateDynamicObject(1216, 2086.28540, 952.86908, 10.09340,   0.00000, 0.00000, -91.26000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[7] = CreateDynamicObject(1216, 2087.17456, 1453.51099, 10.42242,   0.00000, 0.00000, 270.65994, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[8] = CreateDynamicObject(1216, 1746.39478, 488.16449, 29.12510,   0.00000, 0.00000, -107.82000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[9] = CreateDynamicObject(1216, 1711.83167, 502.24524, 29.16731,   0.00000, 0.00000, 66.36000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[10] = CreateDynamicObject(1216, 242.32457, -54.86663, 1.20300,   0.00000, 0.00000, -90.72000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[11] = CreateDynamicObject(1216, 260.33389, -383.38239, 8.31110,   0.00000, 0.00000, -192.65990, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[12] = CreateDynamicObject(1216, 308.62372, -575.42407, 40.82828,   0.00000, 0.00000, -185.63997, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[13] = CreateDynamicObject(1216, -894.70398, -1121.95459, 98.66000,   0.00000, 0.00000, 73.26000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[14] = CreateDynamicObject(1216, -1734.75085, -592.85681, 15.99980,   0.00000, 0.00000, -178.67999, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[15] = CreateDynamicObject(1216, -2033.67737, -60.80249, 34.92630,   0.00000, 0.00000, -0.90000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[16] = CreateDynamicObject(1216, -1980.88159, 133.44743, 27.20130,   0.00000, 0.00000, -90.06000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[17] = CreateDynamicObject(1216, -1993.93909, 275.82797, 32.55905,   0.00000, 0.00000, -94.79996, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[18] = CreateDynamicObject(1216, -2165.07007, 112.21864, 34.84680,   0.00000, 0.00000, 84.24000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[19] = CreateDynamicObject(1216, -2715.32422, 221.75488, 3.95036,   0.00000, 0.00000, 90.24001, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[20] = CreateDynamicObject(1216, -1704.98828, 31.87425, 3.06393,   0.00000, 0.00000, 134.28000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[21] = CreateDynamicObject(1216, -1815.93738, -363.10153, 19.15330,   0.00000, 0.00000, 90.06000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[22] = CreateDynamicObject(1216, -1903.98242, -842.66290, 44.56131,   0.00000, 0.00000, -179.64005, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    //Telefonzellen LS
    object_phoneBooths[23] = CreateDynamicObject(1216, 1941.67175, -1764.98450, 13.18864,   0.00000, 0.00000, -178.73997, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[24] = CreateDynamicObject(1216, 1833.10242, -1849.52454, 12.98133,   0.00000, 0.00000, -89.70001, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[25] = CreateDynamicObject(1216, 1811.33130, -1899.06738, 13.28196,   0.00000, 0.00000, 175.67996, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[26] = CreateDynamicObject(1216, 1644.65723, -1885.52698, 13.07743,   0.00000, 0.00000, 130.31998, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[27] = CreateDynamicObject(1216, 1549.68311, -1715.23047, 13.05870,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[28] = CreateDynamicObject(1216, 1333.69067, -1565.14136, 12.95291,   0.00000, 0.00000, -12.66000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[29] = CreateDynamicObject(1216, 1318.12671, -1415.70056, 13.03620,   0.00000, 0.00000, -177.89999, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[30] = CreateDynamicObject(1216, 1153.67957, -1415.34229, 13.25989,   0.00000, 0.00000, 180.89999, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[31] = CreateDynamicObject(1216, 787.95319, -1366.83081, 13.15038,   0.00000, 0.00000, 90.11998, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[32] = CreateDynamicObject(1216, 1019.95349, -1310.75757, 13.15575,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[33] = CreateDynamicObject(1216, 1046.67175, -1165.53784, 23.42542,   0.00000, 0.00000, 90.54001, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[34] = CreateDynamicObject(1216, 1061.98914, -1026.94055, 31.67170,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[35] = CreateDynamicObject(1216, 1231.66724, -922.09222, 42.50990,   0.00000, 0.00000, 10.62000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);

    object_phoneBooths[36] = CreateDynamicObject(1216, 1829.65039, -1190.42725, 23.47450,   0.00000, 0.00000, -178.98000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[37] = CreateDynamicObject(1216, 1862.10413, -1390.24304, 13.04675,   0.00000, 0.00000, -179.45996, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[38] = CreateDynamicObject(1216, 1812.21313, -1710.30432, 13.15550,   0.00000, 0.00000, 92.94000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[39] = CreateDynamicObject(1216, 1138.26587, -1750.43774, 13.24660,   0.00000, 0.00000, -178.56000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[41] = CreateDynamicObject(1216, 1135.89893, -1750.42188, 13.24660,   0.00000, 0.00000, -178.67999, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[42] = CreateDynamicObject(1216, 1133.39880, -1750.43201, 13.24660,   0.00000, 0.00000, -179.81984, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[43] = CreateDynamicObject(1216, 707.51343, -1019.95276, 51.56104,   0.00000, 0.00000, -118.73999, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[44] = CreateDynamicObject(1216, -278.37869, -1647.36841, 15.21120,   0.00000, 0.00000, -108.90000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[45] = CreateDynamicObject(1216, -268.99951, -1650.42395, 14.69030,   0.00000, 0.00000, 69.72000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[46] = CreateDynamicObject(1216, 670.71802, -583.92798, 15.87570,   0.00000, 0.00000, -88.50000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[47] = CreateDynamicObject(1216, 1623.87561, -1110.16614, 59.00400,   0.00000, 0.00000, -186.59990, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[48] = CreateDynamicObject(1216, 1639.07996, -1241.13281, 49.05150,   0.00000, 0.00000, -3.12000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[49] = CreateDynamicObject(1216, 1556.27148, -1312.62451, 16.36390,   0.00000, 0.00000, -180.06000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[50] = CreateDynamicObject(1216, 1463.99573, -1452.25818, 13.21430,   0.00000, 0.00000, -91.68000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[51] = CreateDynamicObject(1216, 1038.80969, -1932.43811, 12.63050,   0.00000, 0.00000, 90.96000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[52] = CreateDynamicObject(1216, 103.92840, -1522.48511, 6.59400,   0.00000, 0.00000, -63.24000, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_phoneBooths[53] = CreateDynamicObject(1216, 44.19660, -219.07460, 1.18550,   0.00000, 0.00000, -182.46001, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    // object_phoneBooths[54] = CreateDynamicObject(1216,1443.28137200,-989.31127900,1639.38781700,0.00000000,0.00000000,-89.99998128, VW_MAIN, MAPS_PHONEBOOTHS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //object(67)
}