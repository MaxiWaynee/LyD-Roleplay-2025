#include <YSI\y_hooks>

// Global interior define
#define MAPS_BUSSTOPS_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 150.0;
static Float:DRAWDISTANCE   = 130.0;

// Map variables
new object_busStops[51];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
	// ---
}

hook OnGameModeInit() {
    // 3DTextLabels

    // Actors

	// Objects
	object_busStops[0] = CreateDynamicObject(1375, 1463.12512, -1726.94202, 13.96417, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[1] = CreateDynamicObject(1257, 1244.60010, -1845.96985, 13.75104, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[2] = CreateDynamicObject(1375, 1241.34985, -1846.64246, 14.13190, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[3] = CreateDynamicObject(1257, 431.22342, -1696.57751, 10.42080, 0.00000, 0.00000, 86.04001, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[4] = CreateDynamicObject(1375, 427.57925, -1696.93091, 10.60670, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[5] = CreateDynamicObject(1257, 435.39548, -1503.61060, 31.31547, 0.00000, 0.00000, 189.77980, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[6] = CreateDynamicObject(1375, 436.56958, -1507.40344, 31.66310, 0.00000, 0.00000, 187.61975, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[7] = CreateDynamicObject(1257, 803.70667, -1355.19995, 13.76570, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[8] = CreateDynamicObject(1375, 803.03967, -1351.57361, 14.14522, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[9] = CreateDynamicObject(1257, 1283.82104, -1412.00525, 13.60184, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[10] = CreateDynamicObject(1375, 1288.17493, -1411.36719, 13.80450, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[11] = CreateDynamicObject(1257, 1363.96533, -1224.77246, 14.63877, 10.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[12] = CreateDynamicObject(1375, 1363.33350, -1220.56824, 15.80466, 10.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[13] = CreateDynamicObject(1257, 1467.43420, -1167.16614, 24.17109, 0.00000, 0.00000, 268.62006, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[14] = CreateDynamicObject(1375, 1471.23730, -1166.54407, 24.61120, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[15] = CreateDynamicObject(1257, 1444.99255, -1027.67871, 24.10810, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[16] = CreateDynamicObject(1375, 1440.92334, -1028.26172, 24.29730, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[17] = CreateDynamicObject(1257, 1327.19458, -918.74481, 37.24937, 5.00000, 0.00000, 81.29998, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[18] = CreateDynamicObject(1375, 1322.94043, -918.64734, 38.06763, 5.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[19] = CreateDynamicObject(1257, 1143.00378, -938.07806, 43.29725, 0.00000, 0.00000, 95.03999, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[20] = CreateDynamicObject(1375, 1139.30200, -938.95929, 43.51739, 0.00000, 0.00000, 95.04000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[21] = CreateDynamicObject(1257, 936.24280, -1238.20288, 16.75180, -2.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[22] = CreateDynamicObject(1375, 937.15540, -1241.46777, 17.41030, -2.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[23] = CreateDynamicObject(1257, 1149.20044, -1412.09436, 13.89973, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[24] = CreateDynamicObject(1375, 1152.93860, -1411.43860, 14.28092, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[25] = CreateDynamicObject(1257, 1639.59998, -1878.42932, 13.76790, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[26] = CreateDynamicObject(1375, 1643.08252, -1877.72473, 14.04202, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[27] = CreateDynamicObject(1257, 1815.35522, -1874.31982, 13.79458, 0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[28] = CreateDynamicObject(1375, 1816.01489, -1878.22656, 14.18700, 0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[29] = CreateDynamicObject(1257, 1981.73364, -2172.81934, 13.79897, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[30] = CreateDynamicObject(1375, 1985.77637, -2172.19556, 14.16716, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[31] = CreateDynamicObject(1257, 2690.09302, -2467.14941, 13.82804, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[32] = CreateDynamicObject(1375, 2689.54053, -2463.88892, 14.25474, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[33] = CreateDynamicObject(1257, 2207.10205, -1629.79590, 16.04195, 4.00000, 0.00000, -13.26000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[34] = CreateDynamicObject(1375, 2207.46704, -1625.88123, 16.62035, 4.00000, 0.00000, -13.26000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[35] = CreateDynamicObject(1257, 2013.14233, -1454.57544, 13.80112, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[36] = CreateDynamicObject(1375, 2009.25720, -1455.15344, 14.11437, 0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[37] = CreateDynamicObject(1257, 1815.40857, -1676.45789, 13.79130, 0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[38] = CreateDynamicObject(1375, 1816.04211, -1680.16821, 14.11160, 0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[39] = CreateDynamicObject(1257, -108.56046, -1171.22058, 3.09173, 0.00000, 0.00000, -22.74000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[40] = CreateDynamicObject(1375, -107.50555, -1167.39673, 3.44578, 0.00000, 0.00000, -19.20001, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[41] = CreateDynamicObject(1257, -133.81808, -196.05246, 2.08852, 0.00000, 0.00000, -100.25999, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[42] = CreateDynamicObject(1375, -129.97540, -196.15208, 3.47755, 0.00000, 0.00000, -93.18004, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[43] = CreateDynamicObject(1257, 635.43927, -577.42279, 16.52781, 0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[44] = CreateDynamicObject(1375, 636.15973, -581.77686, 16.92885, 0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[45] = CreateDynamicObject(1257, 928.30908, -985.11328, 38.62853, 0.00000, 0.00000, -78.47999, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[46] = CreateDynamicObject(1375, 931.95514, -983.74677, 39.12421, 0.00000, 0.00000, -79.55997, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[47] = CreateDynamicObject(1257, 1021.58490, -1155.72632, 23.95150, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[48] = CreateDynamicObject(1375, 1025.62683, -1155.08850, 24.36821, 0.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[49] = CreateDynamicObject(1257, 1550.68787, -1309.59583, 16.79200, 1.00000, 0.00000, -89.63999, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_busStops[50] = CreateDynamicObject(1375, 1554.56982, -1308.98401, 17.29710, 1.00000, 0.00000, -90.00000, VW_MAIN, MAPS_BUSSTOPS_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}