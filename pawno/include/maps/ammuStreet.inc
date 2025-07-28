#include <YSI\y_hooks>

// Global interior define
#define MAPS_AMMUSTREET_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Map variables
new object_ammuStreet[79];

hook OnPlayerConnect(playerid) {
    // ---
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Map Icon
    CreateDynamicMapIcon(1364.3768, -1280.3932, 13.5469, 6, 0, VW_MAIN, MAPS_AMMUSTREET_INTERIOR);

    // Pickups
    
    // 3DTextLabels
    
    // Actors

    // Objects
    object_ammuStreet[0] = CreateDynamicObject(3660, 1348.8039, -1430.9832, 14.4258, 0.0000, 0.0000, 85.9000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_ammuStreet[1] = CreateDynamicObject(5859, 1304.9936, -1719.8946, 11.6358, 0.0996, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //road_lawn24
    object_ammuStreet[2] = CreateDynamicObject(3660, 1345.0257, -1462.0683, 14.4258, 0.0000, 0.0000, -102.6998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_ammuStreet[3] = CreateDynamicObject(3660, 1335.2196, -1488.0206, 14.4258, 0.0000, 0.0000, 62.7000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_ammuStreet[4] = CreateDynamicObject(19950, 1363.3105, -1415.9079, 12.5156, 0.0000, 0.0000, 178.3000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[5] = CreateDynamicObject(5859, 1304.9892, -1782.0714, 11.5685, 0.0000, 0.0000, 179.7998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //road_lawn24
    object_ammuStreet[6] = CreateDynamicObject(3660, 1311.9255, -1528.9920, 14.4258, 0.0000, 0.0000, 68.9000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
    object_ammuStreet[7] = CreateDynamicObject(19950, 1318.4665, -1743.9079, 12.5057, 0.0000, 0.0000, -178.9996, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[8] = CreateDynamicObject(19950, 1351.8581, -1416.4427, 12.5156, 0.0000, 0.0000, 178.3000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[9] = CreateDynamicObject(19957, 1337.3253, -1416.5079, 12.4912, 0.0000, 0.0000, 179.1000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[10] = CreateDynamicObject(19957, 1348.2746, -1416.6800, 12.4912, 0.0000, 0.0000, 179.1000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[11] = CreateDynamicObject(19957, 1363.4675, -1384.1556, 12.5698, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[12] = CreateDynamicObject(19957, 1351.4449, -1384.0754, 12.5698, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[13] = CreateDynamicObject(19950, 1337.1855, -1384.9128, 12.6084, 0.0000, 0.0000, 12.8999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[14] = CreateDynamicObject(19950, 1348.9825, -1384.0029, 12.6084, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[15] = CreateDynamicObject(19950, 1291.6866, -1842.2502, 12.4462, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[16] = CreateDynamicObject(19950, 1303.3275, -1842.2502, 12.4462, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[17] = CreateDynamicObject(19957, 1306.2602, -1842.5046, 12.5445, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[18] = CreateDynamicObject(19957, 1318.7435, -1842.5046, 12.5445, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[19] = CreateDynamicObject(19956, 1322.5249, -1725.4051, 12.5044, 0.0000, 0.0000, 87.5000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign9
    object_ammuStreet[20] = CreateDynamicObject(19949, 1322.5240, -1725.3951, 11.8781, 0.0000, 0.0000, 79.6997, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign2
    object_ammuStreet[21] = CreateDynamicObject(19950, 1306.3874, -1744.1179, 12.5057, 0.0000, 0.0000, -178.9996, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[22] = CreateDynamicObject(19956, 1285.5460, -1718.7475, 12.0881, 0.0000, 0.0000, -102.4999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign9
    object_ammuStreet[23] = CreateDynamicObject(19949, 1285.5373, -1718.7513, 11.4947, 0.0000, 0.0000, -97.1996, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign2
    object_ammuStreet[24] = CreateDynamicObject(19950, 1291.8658, -1703.5566, 12.4462, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[25] = CreateDynamicObject(19950, 1303.6158, -1703.5566, 12.4462, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[26] = CreateDynamicObject(19950, 1363.3349, -1161.5162, 22.6632, 0.0000, 0.0000, -177.0997, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[27] = CreateDynamicObject(19950, 1351.5301, -1162.1136, 22.6632, 0.0000, 0.0000, 174.6999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[28] = CreateDynamicObject(19957, 1336.9635, -1162.0587, 22.8253, 0.0000, 0.0000, 177.7998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[29] = CreateDynamicObject(19957, 1348.7032, -1161.9503, 22.8253, 0.0000, 0.0000, 177.7998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[30] = CreateDynamicObject(1652, 1347.6308, -1280.8725, 13.0647, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[31] = CreateDynamicObject(1652, 1347.6433, -1280.9410, 13.0544, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[32] = CreateDynamicObject(19954, 1347.6485, -1280.9193, 11.5179, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
    object_ammuStreet[33] = CreateDynamicObject(19954, 1347.6485, -1287.3216, 11.5179, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
    object_ammuStreet[34] = CreateDynamicObject(19445, 1348.0849, -1274.1960, 10.6443, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    object_ammuStreet[35] = CreateDynamicObject(983, 1348.9610, -1296.6330, 13.0769, 0.0000, 0.0000, 24.1000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    object_ammuStreet[36] = CreateDynamicObject(983, 1349.2722, -1265.3846, 13.0683, 0.0000, 0.0000, 149.5997, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fenceshit3
    object_ammuStreet[37] = CreateDynamicObject(19978, 1363.0290, -1276.6877, 11.5720, 0.0000, 0.0000, -89.4000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign31
    object_ammuStreet[38] = CreateDynamicObject(19956, 1322.3685, -1565.9206, 12.4687, 0.0000, 0.0000, 85.3000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign9
    object_ammuStreet[39] = CreateDynamicObject(19445, 1348.0849, -1283.7967, 10.6443, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall085
    object_ammuStreet[40] = CreateDynamicObject(19353, 1349.4366, -1289.3288, 10.6400, 0.0000, 0.0000, 59.7999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    object_ammuStreet[41] = CreateDynamicObject(640, 1367.1800, -1285.7563, 13.1927, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush2
    object_ammuStreet[42] = CreateDynamicObject(638, 1367.1684, -1275.4619, 13.1751, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //kb_planter+bush
    object_ammuStreet[43] = CreateDynamicObject(1652, 1363.0367, -1287.8785, 13.2047, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[44] = CreateDynamicObject(1653, 1363.0605, -1266.0239, 13.2201, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaitism
    object_ammuStreet[45] = CreateDynamicObject(1652, 1363.0367, -1313.4642, 13.2047, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[46] = CreateDynamicObject(1652, 1363.0367, -1339.0544, 13.2047, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[47] = CreateDynamicObject(1652, 1363.0367, -1364.6993, 13.2047, 0.0000, 0.0000, -89.9999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[48] = CreateDynamicObject(1652, 1363.0367, -1364.7795, 13.2047, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[49] = CreateDynamicObject(1652, 1363.0367, -1339.1202, 13.2047, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[50] = CreateDynamicObject(1652, 1363.0367, -1313.4504, 13.2047, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[51] = CreateDynamicObject(1652, 1363.0367, -1287.9000, 13.2047, 0.0000, 0.0000, 90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaiti
    object_ammuStreet[52] = CreateDynamicObject(1653, 1363.0605, -1266.0239, 13.2201, 0.0000, 0.0000, 90.0998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //fencehaitism
    object_ammuStreet[53] = CreateDynamicObject(1215, 1364.2822, -1377.4697, 13.1359, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[54] = CreateDynamicObject(1215, 1366.2724, -1377.4697, 13.1359, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[55] = CreateDynamicObject(1215, 1364.4715, -1259.7429, 13.0284, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[56] = CreateDynamicObject(1215, 1366.2414, -1259.7429, 13.0284, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[57] = CreateDynamicObject(19954, 1347.6485, -1274.5072, 11.5179, 0.0000, 0.0000, -90.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign7
    object_ammuStreet[58] = CreateDynamicObject(19353, 1349.4366, -1285.3288, 10.6400, 0.0000, 0.0000, 59.7999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    object_ammuStreet[59] = CreateDynamicObject(19353, 1349.4366, -1281.3288, 10.6400, 0.0000, 0.0000, 59.7999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    object_ammuStreet[60] = CreateDynamicObject(19353, 1349.4366, -1277.3288, 10.6400, 0.0000, 0.0000, 59.7999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    object_ammuStreet[61] = CreateDynamicObject(19353, 1349.4366, -1273.3288, 10.6400, 0.0000, 0.0000, 59.7999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //wall001
    object_ammuStreet[62] = CreateDynamicObject(1215, 1367.3879, -1282.2281, 12.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[63] = CreateDynamicObject(1215, 1367.3879, -1277.4071, 12.5452, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[64] = CreateDynamicObject(19950, 1291.7187, -1563.4315, 12.4420, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[65] = CreateDynamicObject(1215, 1348.1064, -1270.8657, 12.3652, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[66] = CreateDynamicObject(19950, 1303.1888, -1563.4315, 12.4420, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[67] = CreateDynamicObject(1215, 1348.1064, -1288.6451, 12.3652, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //bollardlight
    object_ammuStreet[68] = CreateDynamicObject(19950, 1318.2845, -1582.4477, 12.3737, 0.0000, 0.0000, 179.4998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[69] = CreateDynamicObject(19950, 1306.4436, -1582.3454, 12.3737, 0.0000, 0.0000, 179.4998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[70] = CreateDynamicObject(19956, 1286.5090, -1578.6922, 12.4446, 0.0000, 0.0000, -104.1997, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign9
    object_ammuStreet[71] = CreateDynamicObject(19950, 1336.5050, -1270.8940, 12.5774, 0.0000, 0.0000, 0.0000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[72] = CreateDynamicObject(19950, 1347.6457, -1271.3243, 12.5774, 0.0000, 0.0000, -15.1000, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[73] = CreateDynamicObject(19956, 1330.2425, -1286.7591, 12.3846, 0.0000, 0.0000, -96.1997, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign9
    object_ammuStreet[74] = CreateDynamicObject(19950, 1363.3812, -1253.1986, 12.5046, 0.0000, 0.0000, 179.8999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[75] = CreateDynamicObject(19950, 1351.0499, -1253.1938, 12.5046, 0.0000, 0.0000, 177.9998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign3
    object_ammuStreet[76] = CreateDynamicObject(19957, 1336.7535, -1253.2596, 12.4368, 0.0000, 0.0000, -179.6999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[77] = CreateDynamicObject(19957, 1349.4023, -1253.1937, 12.4368, 0.0000, 0.0000, -179.6999, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //SAMPRoadSign10
    object_ammuStreet[78] = CreateDynamicObject(3660, 1323.2087, -1509.1185, 14.4258, 0.0000, 0.0000, -124.1998, VW_MAIN, MAPS_AMMUSTREET_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE); //lasairfbed_LAS
}