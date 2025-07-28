#include <YSI\y_hooks>

// Global interior define
#define MAPS_TUEV_INTERIOR      0

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 200.0;
static Float:DRAWDISTANCE   = 180.0;

// TÜV stations
#define TUEV_INFO_POINT         547.8384, -1285.5684, 17.0197
#define TUEV_AIRCRAFT_POINT     2113.1296, -2423.3569, 13.6150
#define TUEV_AUTO_POINT         547.8384, -1285.5684, 17.0197

// Map variables
new object_tuev[52];
new pickup_tuev[2];
new text3D_tuev[3];

hook OnPlayerConnect(playerid) {
    RemoveBuildingForPlayer(playerid, 1211, 555.1563, -1251.9297, 16.6406, 0.25);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
    // ---
}

hook OnGameModeInit() {
    // Map Icons
    CreateDynamicMapIcon(TUEV_INFO_POINT, 27, 0, VW_MAIN, MAPS_TUEV_INTERIOR);
    CreateDynamicMapIcon(TUEV_AIRCRAFT_POINT, 27, 0, VW_MAIN, MAPS_TUEV_INTERIOR);
    
    // Pickups    
    pickup_tuev[0] = CreateDynamicPickup(19627, 1, TUEV_AUTO_POINT, VW_MAIN, MAPS_TUEV_INTERIOR); // TUEV für Auto und Motorräder
	pickup_tuev[1] = CreateDynamicPickup(19627, 1, TUEV_AIRCRAFT_POINT, VW_MAIN, MAPS_TUEV_INTERIOR); // TUEV für Flugzeuge

    // 3DTextLabels
    text3D_tuev[0] = _:CreateDynamic3DTextLabel("TÜV-WERKSTATT", COLOR_YELLOW, TUEV_INFO_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TUEV_INTERIOR);
    text3D_tuev[1] = _:CreateDynamic3DTextLabel("TÜV-WERKSTATT\n" COLOR_HEX_WHITE "Tippe /Wartungen", COLOR_GREEN, TUEV_AUTO_POINT, 15.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TUEV_INTERIOR);
	text3D_tuev[2] = _:CreateDynamic3DTextLabel("TÜV-WERKSTATT\n" COLOR_HEX_WHITE "Tippe /Wartungen", COLOR_GREEN, TUEV_AIRCRAFT_POINT, 40.0, .testlos = 1, .worldid = VW_MAIN, .interiorid = MAPS_TUEV_INTERIOR);    

    // Objects
    // TÜV Auto Map
    
    object_tuev[0] = CreateDynamicObject(12978, 547.64386, -1285.86926, 16.69165, 0.00000, 0.00000, 177.35098, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[1] = CreateDynamicObject(13027, 547.74939, -1285.69861, 19.62720, 0.00000, 0.00000, 357.63467, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[2] = CreateDynamicObject(14826, 554.81177, -1277.64050, 16.87831, 0.00000, 0.00000, 354.43314, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[3] = CreateDynamicObject(19898, 546.51001, -1275.45203, 16.25510, 0.00000, 0.00000, 324.53809, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[4] = CreateDynamicObject(19903, 551.75366, -1282.99988, 16.12658, 0.00000, 0.00000, 179.74806, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[5] = CreateDynamicObject(19900, 551.29437, -1286.76563, 16.43605, 0.00000, 0.00000, 358.09952, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[6] = CreateDynamicObject(19899, 551.36853, -1288.36450, 16.43491, 0.00000, 0.00000, 178.24158, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[7] = CreateDynamicObject(19621, 551.27582, -1286.73291, 17.40420, 0.00000, 0.00000, 359.06311, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[8] = CreateDynamicObject(19903, 544.78210, -1277.41992, 16.12658, 0.00000, 0.00000, 85.37640, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[9] = CreateDynamicObject(11728, 543.98248, -1277.77222, 18.45390, 0.00000, 0.00000, 177.21919, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[10] = CreateDynamicObject(11710, 543.20648, -1291.32617, 18.85063, 0.00000, 0.00000, 270.78076, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[11] = CreateDynamicObject(19898, 550.00134, -1287.38770, 16.44620, 0.00000, 0.00000, 119.97318, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[12] = CreateDynamicObject(19904, 543.91461, -1282.84045, 18.08790, 0.00000, 0.00000, 83.58140, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[13] = CreateDynamicObject(19904, 543.84918, -1284.35181, 18.10380, 0.00000, 0.00000, 83.58140, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[14] = CreateDynamicObject(19904, 543.86591, -1283.59656, 18.10380, 0.00000, 0.00000, 83.58140, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[15] = CreateDynamicObject(19872, 547.84149, -1285.53674, 14.66084, 0.00000, 0.00000, 358.22159, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    
    // TÜV Aircraft Map
    object_tuev[16] = CreateDynamicObject(1653, 2134.98633, -2429.06152, 13.16570, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[17] = CreateDynamicObject(1653, 2090.94678, -2441.71704, 13.16570, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[18] = CreateDynamicObject(1653, 2090.94263, -2428.93872, 13.16570, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[19] = CreateDynamicObject(1653, 2090.94263, -2416.14600, 13.16570, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[20] = CreateDynamicObject(1653, 2134.98633, -2416.23340, 13.16570, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[21] = CreateDynamicObject(1653, 2134.98633, -2441.83521, 13.16570, 0.00000, 0.00000, 270.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[22] = CreateDynamicObject(10757, 2977.85229, 6297.90967, -5015.82959, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[23] = CreateDynamicObject(10757, 2112.75488, -2409.48486, 26.97763, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[24] = CreateDynamicObject(9241, 2113.11182, -2422.32446, 11.78690, 0.00000, 0.00000, 89.66700, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[25] = CreateDynamicObject(19124, 2090.92334, -2448.32495, 13.26812, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[26] = CreateDynamicObject(19124, 624.81335, 5926.28125, -5556.83984, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[27] = CreateDynamicObject(19124, 2134.94995, -2448.26709, 13.05440, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[28] = CreateDynamicObject(19903, 2100.00171, -2409.88135, 12.46976, 0.00000, 0.00000, 272.16910, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[29] = CreateDynamicObject(1437, 2105.08496, -2410.13013, 12.60701, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[30] = CreateDynamicObject(19899, 2091.49829, -2414.31421, 12.44109, 0.00000, 0.00000, 0.43950, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[31] = CreateDynamicObject(19900, 2095.52612, -2410.16138, 12.54729, 0.00000, 0.00000, 1.89599, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[32] = CreateDynamicObject(19815, 2103.40771, -2409.20361, 14.14648, 0.00000, 0.00000, 359.79898, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[33] = CreateDynamicObject(19921, 2101.65991, -2411.48364, 12.71580, 0.00000, 0.00000, 28.71153, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[34] = CreateDynamicObject(19627, 2097.41626, -2410.20117, 13.70890, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[35] = CreateDynamicObject(19627, 2102.20361, -2411.49536, 12.63220, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[36] = CreateDynamicObject(18633, 2101.92432, -2411.48950, 12.61250, 0.00000, 0.00000, 350.13101, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[37] = CreateDynamicObject(1370, 2092.77710, -2410.99902, 13.15355, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[38] = CreateDynamicObject(1370, 2092.00024, -2411.26904, 13.15355, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[39] = CreateDynamicObject(1370, 2092.00024, -2411.26904, 13.15355, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[40] = CreateDynamicObject(1370, 2092.12109, -2410.50415, 13.15355, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[41] = CreateDynamicObject(1370, 2092.12109, -2410.50415, 13.15355, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[42] = CreateDynamicObject(1370, 2093.41675, -2410.20630, 12.75360, 0.00000, 84.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[43] = CreateDynamicObject(14679, 2099.47729, -2409.93115, 12.95445, 0.00000, 0.00000, 20.44954, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[44] = CreateDynamicObject(3271, 2141.52368, -2441.81885, 12.35857, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[45] = CreateDynamicObject(19899, 2097.12524, -2409.97510, 12.44109, 0.00000, 0.00000, 270.60223, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[46] = CreateDynamicObject(1025, 2092.22974, -2416.19556, 12.65190, 0.00000, 92.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[47] = CreateDynamicObject(1025, 2092.22974, -2416.19556, 12.99290, 0.00000, 92.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[48] = CreateDynamicObject(1025, 2092.39697, -2417.05176, 12.82485, 39.00000, 92.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[49] = CreateDynamicObject(1025, 2092.22974, -2416.19556, 13.33290, 0.00000, 90.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[50] = CreateDynamicObject(19898, 2112.26880, -2419.37769, 12.62220, 0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_tuev[51] = CreateDynamicObject(3633, 2092.37524, -2418.73413, 12.95242, 0.00000, 0.00000, 340.41779, VW_MAIN, MAPS_TUEV_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}
