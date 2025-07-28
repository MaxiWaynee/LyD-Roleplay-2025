#include <YSI\y_hooks>

// Global interior define
#define MAPS_YAKUZAEXTERIOR_INTERIOR      0
#define MAPS_YAKUZAINTERIOR_INTERIOR      1

// Local drawdistance & streamdistance setting
static Float:STREAMDISTANCE = 350.0;
static Float:DRAWDISTANCE   = 350.0;

// Yakuza points
#define YAKUZA_INTERIOR_ENTER_COORDS        2773.5256,-2456.0720,13.6371
#define YAKUZA_INTERIOR_EXIT_COORDS         2234.0027, 1713.4369, 1012.1367
#define YAKUZA_INTERIOR_ENTER_FACING        180.0
#define YAKUZA_INTERIOR_EXIT_FACING         320.5

// Map variables
new object_yakuzaExterior[109];

hook OnPlayerConnect(playerid) {
    // Remove RenderWare objects
    RemoveBuildingForPlayer(playerid, 3710, 2788.1563, -2417.7891, 16.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3710, 2788.1563, -2455.8828, 16.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3710, 2788.1563, -2493.9844, 16.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2771.0703, -2372.4453, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2789.2109, -2377.6250, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2774.7969, -2386.8516, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2771.0703, -2520.5469, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3744, 2774.7969, -2534.9531, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3746, 2814.2656, -2356.5703, 25.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 3746, 2814.2656, -2521.4922, 25.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 3770, 2795.8281, -2394.2422, 14.1719, 0.25);
    RemoveBuildingForPlayer(playerid, 3770, 2746.4063, -2453.4844, 14.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 1306, 2742.2656, -2481.5156, 19.8438, 0.25);
    RemoveBuildingForPlayer(playerid, 5326, 2661.5156, -2465.1406, 20.1094, 0.25);
    RemoveBuildingForPlayer(playerid, 1306, 2742.2656, -2416.5234, 19.8438, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2774.7969, -2534.9531, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2771.0703, -2520.5469, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2501.8359, 14.6953, 0.25);
    RemoveBuildingForPlayer(playerid, 3624, 2788.1563, -2493.9844, 16.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2486.9609, 14.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 3578, 2747.0078, -2480.2422, 13.1719, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2463.8203, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 1278, 2773.3438, -2479.9688, 26.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 3624, 2788.1563, -2455.8828, 16.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3626, 2746.4063, -2453.4844, 14.0781, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2448.4766, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 1278, 2773.3438, -2443.1719, 26.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 3577, 2744.5703, -2436.1875, 13.3438, 0.25);
    RemoveBuildingForPlayer(playerid, 3577, 2744.5703, -2427.3203, 13.3516, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2425.3516, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2774.7969, -2386.8516, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2771.0703, -2372.4453, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2783.7813, -2410.2109, 14.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 3624, 2788.1563, -2417.7891, 16.7266, 0.25);
    RemoveBuildingForPlayer(playerid, 3574, 2789.2109, -2377.6250, 15.2188, 0.25);
    RemoveBuildingForPlayer(playerid, 1278, 2802.4297, -2556.5234, 26.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2501.8359, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2797.5156, -2486.8281, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2486.9609, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2463.8203, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2797.5156, -2448.3438, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2448.4766, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2425.3516, 14.6719, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2791.9531, -2410.2109, 14.6563, 0.25);
    RemoveBuildingForPlayer(playerid, 3761, 2797.5156, -2410.0781, 14.6328, 0.25);
    RemoveBuildingForPlayer(playerid, 3626, 2795.8281, -2394.2422, 14.1719, 0.25);
    RemoveBuildingForPlayer(playerid, 3620, 2814.2656, -2521.4922, 25.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 3620, 2814.2656, -2356.5703, 25.5156, 0.25);
    RemoveBuildingForPlayer(playerid, 1278, 2762.7578, -2333.3828, 26.7031, 0.25);
    RemoveBuildingForPlayer(playerid, 1278, 2804.2422, -2333.3828, 26.7031, 0.25);
    //durchgang Zaun
    RemoveBuildingForPlayer(playerid, 713, 1304.7734, -1839.8672, 12.4375, 0.25);
}

hook OnGameModeInit() {
    // Vehicles

    // Pickups
    
    // Actors

    // Objects
    object_yakuzaExterior[0] = CreateDynamicObject(7885, 2787.615478, -2456.232666, 12.468420, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[1] = CreateDynamicObject(7917, 2787.567871, -2456.235107, 12.408436, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[2] = CreateDynamicObject(3528, 2768.991900, -2455.930200, 27.248500, 0.000000, 0.000000, 180.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[3] = CreateDynamicObject(3934, 2796.078369, -2512.894042, 12.633167, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[4] = CreateDynamicObject(3934, 2796.108398, -2530.977539, 12.633167, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[5] = CreateDynamicObject(3934, 2796.078369, -2548.802001, 12.633167, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[6] = CreateDynamicObject(3934, 2781.039062, -2512.894042, 12.633167, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[7] = CreateDynamicObject(3934, 2781.039062, -2531.001708, 12.633167, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[8] = CreateDynamicObject(3934, 2781.039062, -2548.816162, 12.633167, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[9] = CreateDynamicObject(19122, 2784.790283, -2545.449462, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[10] = CreateDynamicObject(19122, 2784.790283, -2552.359619, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[11] = CreateDynamicObject(19122, 2777.074462, -2552.359619, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[12] = CreateDynamicObject(19122, 2777.074462, -2545.476806, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[13] = CreateDynamicObject(19122, 2792.096435, -2552.349609, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[14] = CreateDynamicObject(19122, 2799.813232, -2552.349609, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[15] = CreateDynamicObject(19122, 2799.833251, -2545.433593, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[16] = CreateDynamicObject(19122, 2792.135742, -2545.453613, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[17] = CreateDynamicObject(19122, 2792.135742, -2534.515869, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[18] = CreateDynamicObject(19122, 2799.819580, -2534.515869, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[19] = CreateDynamicObject(19122, 2799.849609, -2527.622802, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[20] = CreateDynamicObject(19122, 2792.164306, -2527.632812, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[21] = CreateDynamicObject(19122, 2784.768554, -2527.632812, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[22] = CreateDynamicObject(19122, 2777.086181, -2527.652832, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[23] = CreateDynamicObject(19122, 2777.056152, -2534.549072, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[24] = CreateDynamicObject(19122, 2784.751464, -2534.549072, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[25] = CreateDynamicObject(19122, 2784.768554, -2516.443359, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[26] = CreateDynamicObject(19122, 2777.063476, -2516.443359, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[27] = CreateDynamicObject(19122, 2777.083496, -2509.571044, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[28] = CreateDynamicObject(19122, 2784.766113, -2509.541015, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[29] = CreateDynamicObject(19122, 2792.118652, -2509.541015, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[30] = CreateDynamicObject(19122, 2799.831298, -2509.541015, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[31] = CreateDynamicObject(19122, 2799.821289, -2516.434814, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[32] = CreateDynamicObject(19122, 2792.093994, -2516.434814, 12.714381, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[33] = CreateDynamicObject(8263, 2810.49829, -2389.69189, 14.89960,   0.00000, 0.00000, -270.06049, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[34] = CreateDynamicObject(8263, 2810.40625, -2505.72900, 14.89960,   0.00000, 0.00000, -270.06049, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[35] = CreateDynamicObject(16401, 2779.494630, -2335.211670, 12.657400, 0.000000, 0.000000, 87.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[36] = CreateDynamicObject(3502, 2779.897949, -2331.919921, 12.986630, 0.100000, 1.499998, 89.000114, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[37] = CreateDynamicObject(987, 2810.58618, -2330.13013, 12.63760,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[38] = CreateDynamicObject(987, 2798.60620, -2330.13013, 12.63760,   0.00000, 0.00000, 180.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[39] = CreateDynamicObject(987, 2774.54614, -2330.25000, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[40] = CreateDynamicObject(987, 2762.56616, -2330.29004, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[41] = CreateDynamicObject(987, 2750.58618, -2330.31006, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[42] = CreateDynamicObject(987, 2738.62622, -2330.33008, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[43] = CreateDynamicObject(987, 2726.68628, -2330.35010, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[44] = CreateDynamicObject(987, 2714.74634, -2330.35010, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[45] = CreateDynamicObject(987, 2687.54565, -2332.44312, 12.63760,   0.00000, 0.00000, 180.10001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[46] = CreateDynamicObject(987, 2798.43433, -2565.72412, 12.62940,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[47] = CreateDynamicObject(987, 2786.49438, -2565.72412, 12.62940,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[48] = CreateDynamicObject(987, 2774.55444, -2565.72412, 12.62940,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[49] = CreateDynamicObject(987, 2764.03442, -2565.72412, 12.62940,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[50] = CreateDynamicObject(987, 2722.41431, -2565.72412, 12.62940,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[51] = CreateDynamicObject(987, 2734.35425, -2565.72412, 12.62940,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[52] = CreateDynamicObject(19641, 2675.445556, -2344.287597, 12.622800, 0.000000, 0.000000, 89.400001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[53] = CreateDynamicObject(19641, 2675.524658, -2336.710205, 12.622800, 0.000000, 0.000000, 89.400001, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[54] = CreateDynamicObject(19641, 2720.873291, -2559.128662, 12.591826, 0.000000, 0.000000, -90.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[55] = CreateDynamicObject(19641, 2720.764648, -2554.102294, 12.591826, 0.000000, 0.000000, -90.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[56] = CreateDynamicObject(4697, 2748.75464, -2475.98633, 12.7327,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[57] = CreateDynamicObject(4697, 2748.75464, -2444.28638, 12.7127,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[58] = CreateDynamicObject(1231, 2740.89331, -2482.81152, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[59] = CreateDynamicObject(1231, 2740.89331, -2478.31152, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[60] = CreateDynamicObject(1231, 2740.89331, -2473.76001, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[61] = CreateDynamicObject(1231, 2740.89331, -2469.23999, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[62] = CreateDynamicObject(1231, 2740.89331, -2464.69995, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[63] = CreateDynamicObject(1231, 2740.89331, -2460.17993, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[64] = CreateDynamicObject(1231, 2740.89331, -2455.65991, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[65] = CreateDynamicObject(1231, 2740.89331, -2451.11987, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[66] = CreateDynamicObject(1231, 2740.89331, -2446.57983, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[67] = CreateDynamicObject(1231, 2740.89331, -2442.05981, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[68] = CreateDynamicObject(1231, 2740.89331, -2437.53979, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[69] = CreateDynamicObject(1231, 2740.89331, -2432.99976, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[70] = CreateDynamicObject(1231, 2740.89331, -2428.45972, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[71] = CreateDynamicObject(1231, 2740.89331, -2423.95972, 13.90000,   0.00000, 0.00000, 90.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[72] = CreateDynamicObject(1232, 2774.10449, -2452.85718, 12.55430,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[73] = CreateDynamicObject(1232, 2774.10449, -2459.63721, 12.55430,   0.00000, 0.00000, 0.00000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[74] = CreateDynamicObject(1215, 2781.924072, -2435.351074, 21.691534, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[75] = CreateDynamicObject(1215, 2781.924072, -2432.039306, 21.691534, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[76] = CreateDynamicObject(1215, 2781.904785, -2480.333740, 21.651546, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[77] = CreateDynamicObject(1215, 2781.904785, -2477.023193, 21.651546, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[78] = CreateDynamicObject(19121, 2772.187255, -2492.483398, 13.242800, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[79] = CreateDynamicObject(1645, 2770.923828, -2457.687255, 16.741575, 0.000000, 0.000000, -90.400009, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[80] = CreateDynamicObject(1597, 2766.035644, -2444.542968, 15.138222, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[81] = CreateDynamicObject(1645, 2771.002441, -2455.416992, 16.691568, 0.000000, 0.000000, -90.300033, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[82] = CreateDynamicObject(3802, 2765.620117, -2452.752929, 15.041123, 0.000000, 0.000000, -178.699829, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[83] = CreateDynamicObject(3802, 2765.551025, -2459.716796, 14.971674, 0.000000, 0.000000, -175.500030, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[84] = CreateDynamicObject(1819, 2770.753906, -2457.058837, 16.461565, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[85] = CreateDynamicObject(1597, 2766.494384, -2467.548339, 15.105578, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[86] = CreateDynamicObject(869, 2766.732421, -2459.578857, 13.033185, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[87] = CreateDynamicObject(869, 2766.593261, -2452.739501, 13.002560, 0.000000, 0.000000, -178.599990, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[88] = CreateDynamicObject(11697, 2772.245117, -2490.771240, 13.889267, 20.800033, 0.000000, -1.500003, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[89] = CreateDynamicObject(11698, 2772.357666, -2486.234375, 15.232289, 22.500007, 0.000000, -0.999999, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[90] = CreateDynamicObject(11698, 2772.376220, -2483.655273, 16.463899, 27.999998, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[91] = CreateDynamicObject(11698, 2772.372314, -2481.052734, 17.824148, 27.300016, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[92] = CreateDynamicObject(11697, 2772.369384, -2477.954101, 18.312255, -1.499993, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[93] = CreateDynamicObject(11697, 2772.528808, -2473.263916, 17.424747, -15.300000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[94] = CreateDynamicObject(3503, 2771.039062, -2479.800292, 16.066591, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[95] = CreateDynamicObject(3503, 2771.089843, -2475.353027, 15.558460, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[96] = CreateDynamicObject(3503, 2771.034912, -2479.812988, 13.418434, 0.000000, 0.000000, -2.699999, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[97] = CreateDynamicObject(3503, 2771.063720, -2475.426269, 12.928434, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[98] = CreateDynamicObject(641, 2769.752685, -2481.353271, 9.636548, 0.000000, 0.000000, -52.700012, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[99] = CreateDynamicObject(641, 2769.732177, -2476.446289, 9.588423, 0.000000, 0.000000, -23.499935, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[100] = CreateDynamicObject(16151, 2780.899658, -2456.669677, 16.748403, 0.000000, 0.000000, -0.500000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[101] = CreateDynamicObject(3660, 2775.886962, -2479.987548, 18.718427, 0.000000, 0.000000, -89.199989, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[102] = CreateDynamicObject(16152, 2781.170654, -2443.045410, 16.351572, 0.000000, 0.000000, 178.899932, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[103] = CreateDynamicObject(2036, 2771.171386, -2456.406250, 16.991571, 0.000000, 0.000000, 47.999996, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[104] = CreateDynamicObject(2034, 2779.842773, -2458.986328, 17.431581, 0.000000, 0.000000, -106.600013, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[105] = CreateDynamicObject(1550, 2770.416992, -2457.060058, 16.851568, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[106] = CreateDynamicObject(1545, 2781.881591, -2458.532958, 18.168424, 0.000000, 0.000000, -93.999992, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[107] = CreateDynamicObject(2710, 2771.489013, -2456.508544, 17.118412, 0.000000, 0.000000, -74.700004, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
    object_yakuzaExterior[108] = CreateDynamicObject(1985, 2778.453613, -2466.239990, 19.488426, 0.000000, 0.000000, 0.000000, VW_MAIN, MAPS_YAKUZAEXTERIOR_INTERIOR, .streamdistance = STREAMDISTANCE, .drawdistance = DRAWDISTANCE);
}

hook OnPlayerKeyStateChange(playerid, newkeys, oldkeys) {
}